# Environmental Chamber V1

Environmental Chamber software and firmware.
It has a tcp conection and a console (tinish).
Library to get data from the BME280 sensor (Relative Humidity, Temperature and Pressure), usian another  I2C library for the ESP32.
Modules to control a dryer and a humidicator through GPIO (ESP32) and optoacomplators.
Two options for control: "Set point" & "PID"
All the control and comunication is made with FreeRTOS tasks.

coming actualizations:
level sensor
