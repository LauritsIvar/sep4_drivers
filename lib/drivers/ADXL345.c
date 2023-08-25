#include "ADXL345.h"
#include "includes.h"

// ADXL345 Register Addresses
#define ADXL345_DEVID 0x00
#define ADXL345_POWER_CTL 0x2D
#define ADXL345_DATA_FORMAT 0x31
#define ADXL345_DATAX0 0x32

// ADXL345 specific constants
#define ADXL345_RANGE_16G 0x03
#define ADXL345_MEASURE_MODE 0x08

#define DD_MISO DDC7 // SDO to MISO (Pin 50)
#define DD_MOSI DDA6 // SDA/SDI to MOSI
#define DD_SCK DDA4  // SCL/SCLK to SCK (Pin 52)
#define DD_SS DDC1

uint8_t spi_transfer(uint8_t data);

void ADXL345_init(void)
{
    DDRA |= (1 << DD_MOSI) | (1 << DD_SCK);
    DDRC |= (1 << DD_SS);

    DDRC &= ~(1 << DD_MISO);

    // //Chip sellect high, because its not sellected.
    PORTC |= (1 << DD_SS);

    // Ground
    DDRG |= (1 << PG1);
    PORTG &= ~(1 << PG1);

    // Vcc
    DDRD |= (1 << PD7);
    PORTD |= (1 << PD7);

    // Clock is default high.
    PORTA |= (1 << DD_SCK);

    _delay_ms(20);

    adxl345_write_register(ADXL345_POWER_CTL, ADXL345_MEASURE_MODE);
    adxl345_write_register(ADXL345_DATA_FORMAT, 0);
}

uint8_t spi_transfer(uint8_t data)
{
    uint8_t received_data = 0;
    for (uint8_t i = 0; i < 8; i++)
    {
        if (data & (1 << (7 - i)))
        {
            PORTA |= (1 << DD_MOSI);
        }
        else
        {
            PORTA &= ~(1 << DD_MOSI);
        }

        // PORTA |= (1 << DD_SCK);
        PORTA &= ~(1 << DD_SCK);
        _delay_us(1);

        received_data <<= 1;
        if (PINC & (1 << DD_MISO))
        {
            received_data |= 1;
        }

        // PORTA &= ~(1 << DD_SCK);
        PORTA |= (1 << DD_SCK);
        _delay_us(1);
    }

    return received_data;
}

void adxl345_write_register(uint8_t reg, uint8_t value)
{
    PORTC &= ~(1 << DD_SS);
    _delay_us(1);

    spi_transfer(reg);
    spi_transfer(value);

    PORTC |= (1 << DD_SS);
}

uint8_t adxl345_read_register(uint8_t reg)
{
    PORTC &= ~(1 << DD_SS);
    spi_transfer(0x80 | reg);
    uint8_t value = spi_transfer(0x00);
    PORTC |= (1 << DD_SS);

    return value;
}

void adxl345_read_xyz(int16_t *x, int16_t *y, int16_t *z)
{
    PORTC &= ~(1 << DD_SS);
    // spi_transfer(0x80 | 0x40 | ADXL345_DATAX0);
    *z = spi_transfer(0xC0 | 0x32);

    *x = spi_transfer(0x00);
    *x |= spi_transfer(0x00) << 8;

    *y = spi_transfer(0x00);
    *y |= spi_transfer(0x00) << 8;

    *z = spi_transfer(0x00);
    *z |= spi_transfer(0x00) << 8;

    PORTC |= (1 << DD_SS);
}