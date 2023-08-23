#pragma once
#include <inttypes.h>



void ADXL345_init(void);



void adxl345_write_register(uint8_t reg, uint8_t value);

void adxl345_read_xyz(int16_t *x, int16_t *y, int16_t *z);