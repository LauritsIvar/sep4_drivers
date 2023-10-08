# sep4_drivers
This repository contains a collection of drivers designed to to work with the hardware at SEP4 at Software Technology Engineering at VIA. All drivers are located in the lib/drivers directory.

Driver Descriptions
##1. adxl345.h
This driver interfaces with the ADXL345 chip, a small, thin, ultralow power, 3-axis accelerometer with high resolution (13-bit) measurement at up to ±16 g. It can be used to measure the static acceleration of gravity in tilt-sensing applications, as well as dynamic acceleration resulting from motion or shock.

##2. buttons.h
This driver is designed to control the three buttons located on top of the multifunction shield.

##3. buzzer.h
Controls the active buzzer positioned on top of the multifunction shield. This can be used to generate audio signals or alerts.

##4. dht11.h
The DHT11 is a basic, ultra low-cost digital temperature and humidity sensor. This driver allows for interfacing with the DHT11 to obtain temperature and humidity readings.

##5. display.h
This driver controls the four 7-segment displays positioned on top of the multifunction shield. It can be used to display numbers or certain characters.

##6. hc_sr04.h
The HC-SR04 is an ultrasonic ranging module that provides 2 cm to 400 cm non-contact measurement functionality with an accuracy of up to 3mm. This driver facilitates the measurement of distance using ultrasonic waves.

##7. leds.h
Controls the four LEDs located on top of the multifunction shield. This can be used for indication, signaling, or other visual purposes.

##8. light.h
This driver controls the photoresistor and is capable of measuring the amount of light in the environment. It can be used in applications that require light sensing or adaptive light control.

##9. pc_comm.h
Facilitates communication to the PC over USB using UART. This can be used for data transfer, debugging, or other PC-based interactions.

##10. periodic_task.h
This driver sets up an interrupt-based service that can call a function at a specified interval. It's useful for tasks that need to be executed periodically without manual intervention.

##11. pir.h
The HC-SR501 is a passive infrared (PIR) motion sensor. This driver interfaces with the HC-SR501 to detect motion based on the infrared radiation emitted by objects (typically humans) within its field of view.

##12. servo.h
This driver interfaces with the SG90 servo motor, a popular and affordable 9g micro servo used in various applications like robotics, drones, and hobby projects. The SG90 operates on a pulse width modulation (PWM) signal, allowing for precise angular positioning ranging from 0 to 180 degrees.

##13. tone.h
Designed for use with a passive buzzer, this driver can generate tones of specified frequencies. By providing different frequency values, you can play various tones or even simple melodies using the passive buzzer.

##14. uart.h
This driver facilitates UART (Universal Asynchronous Receiver-Transmitter) communication, a fundamental serial communication protocol. It is utilized by both the pc_comm and wifi drivers to enable data transfer and communication functionalities.

##15. wifi.h
This driver interfaces with the ESP8266 module, a low-cost Wi-Fi microchip with full TCP/IP stack and microcontroller capability. With this driver, you can connect to an Access Point (AP) and establish a TCP connection, enabling your device to communicate over Wi-Fi and access internet resources.
