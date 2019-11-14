EESchema Schematic File Version 4
LIBS:test_Lucas-cache
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L Connector_Generic:Conn_01x19 J1
U 1 1 5DCB1082
P 1850 3100
F 0 "J1" V 1950 3150 50  0000 L CNN
F 1 "Conn_01x19" V 1950 2650 50  0000 L CNN
F 2 "Connector_PinSocket_2.54mm:PinSocket_1x19_P2.54mm_Vertical" H 1850 3100 50  0001 C CNN
F 3 "~" H 1850 3100 50  0001 C CNN
	1    1850 3100
	0    1    1    0   
$EndComp
$Comp
L Isolator:PC817 U1
U 1 1 5DC61018
P 5000 2350
F 0 "U1" H 5000 2675 50  0000 C CNN
F 1 "PC817" H 5000 2584 50  0000 C CNN
F 2 "Package_DIP:DIP-4_W7.62mm" H 4800 2150 50  0001 L CIN
F 3 "http://www.soselectronic.cz/a_info/resource/d/pc817.pdf" H 5000 2350 50  0001 L CNN
	1    5000 2350
	1    0    0    -1  
$EndComp
Wire Wire Line
	4600 2450 4700 2450
Wire Wire Line
	4700 2250 4400 2250
$Comp
L Device:R R2
U 1 1 5DC6E775
P 4250 2250
F 0 "R2" V 4043 2250 50  0000 C CNN
F 1 "1.8k" V 4134 2250 50  0000 C CNN
F 2 "Resistor_SMD:R_1206_3216Metric_Pad1.42x1.75mm_HandSolder" V 4180 2250 50  0001 C CNN
F 3 "~" H 4250 2250 50  0001 C CNN
	1    4250 2250
	0    1    1    0   
$EndComp
Wire Wire Line
	5450 2250 5300 2250
Wire Wire Line
	5450 2000 5450 2250
Wire Wire Line
	5300 2450 5850 2450
$Comp
L Device:R R1
U 1 1 5DC67A74
P 5850 2600
F 0 "R1" H 5920 2646 50  0000 L CNN
F 1 "100" H 5920 2555 50  0000 L CNN
F 2 "Resistor_SMD:R_1206_3216Metric_Pad1.42x1.75mm_HandSolder" H 5920 2509 50  0001 L CNN
F 3 "~" H 5850 2600 50  0001 C CNN
	1    5850 2600
	1    0    0    -1  
$EndComp
$Comp
L Isolator:PC817 U2
U 1 1 5DCBD2F2
P 5000 3250
F 0 "U2" H 5000 3575 50  0000 C CNN
F 1 "PC817" H 5000 3484 50  0000 C CNN
F 2 "Package_DIP:DIP-4_W7.62mm" H 4800 3050 50  0001 L CIN
F 3 "http://www.soselectronic.cz/a_info/resource/d/pc817.pdf" H 5000 3250 50  0001 L CNN
	1    5000 3250
	1    0    0    -1  
$EndComp
Wire Wire Line
	4600 3350 4700 3350
Wire Wire Line
	3500 3150 4100 3150
Wire Wire Line
	4700 3150 4400 3150
$Comp
L Device:R R3
U 1 1 5DCBD303
P 4250 3150
F 0 "R3" V 4043 3150 50  0000 C CNN
F 1 "1.8k" V 4134 3150 50  0000 C CNN
F 2 "Resistor_SMD:R_1206_3216Metric_Pad1.42x1.75mm_HandSolder" V 4180 3150 50  0001 C CNN
F 3 "~" H 4250 3150 50  0001 C CNN
	1    4250 3150
	0    1    1    0   
$EndComp
Wire Wire Line
	5450 3150 5300 3150
Wire Wire Line
	5450 2900 5450 3150
Wire Wire Line
	5300 3350 5850 3350
$Comp
L Device:R R4
U 1 1 5DCBD310
P 5850 3500
F 0 "R4" H 5920 3546 50  0000 L CNN
F 1 "100" H 5920 3455 50  0000 L CNN
F 2 "Resistor_SMD:R_1206_3216Metric_Pad1.42x1.75mm_HandSolder" H 5920 3409 50  0001 L CNN
F 3 "~" H 5850 3500 50  0001 C CNN
	1    5850 3500
	1    0    0    -1  
$EndComp
$Comp
L power:+24V #PWR05
U 1 1 5DCC0BAF
P 5450 2000
F 0 "#PWR05" H 5450 1850 50  0001 C CNN
F 1 "+24V" H 5465 2173 50  0000 C CNN
F 2 "" H 5450 2000 50  0001 C CNN
F 3 "" H 5450 2000 50  0001 C CNN
	1    5450 2000
	1    0    0    -1  
$EndComp
$Comp
L power:+12V #PWR06
U 1 1 5DCC1422
P 5450 2900
F 0 "#PWR06" H 5450 2750 50  0001 C CNN
F 1 "+12V" H 5465 3073 50  0000 C CNN
F 2 "" H 5450 2900 50  0001 C CNN
F 3 "" H 5450 2900 50  0001 C CNN
	1    5450 2900
	1    0    0    -1  
$EndComp
Wire Wire Line
	1450 2900 1450 2250
Wire Wire Line
	1450 2250 4100 2250
Wire Wire Line
	1550 2900 1550 2350
Wire Wire Line
	1550 2350 3500 2350
Wire Wire Line
	3500 2350 3500 3150
$Comp
L power:GND #PWR04
U 1 1 5DCC32FB
P 4600 3350
F 0 "#PWR04" H 4600 3100 50  0001 C CNN
F 1 "GND" H 4605 3177 50  0000 C CNN
F 2 "" H 4600 3350 50  0001 C CNN
F 3 "" H 4600 3350 50  0001 C CNN
	1    4600 3350
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR03
U 1 1 5DCC39F0
P 4600 2450
F 0 "#PWR03" H 4600 2200 50  0001 C CNN
F 1 "GND" H 4605 2277 50  0000 C CNN
F 2 "" H 4600 2450 50  0001 C CNN
F 3 "" H 4600 2450 50  0001 C CNN
	1    4600 2450
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR02
U 1 1 5DCC3FF0
P 3000 4300
F 0 "#PWR02" H 3000 4050 50  0001 C CNN
F 1 "GND" H 3005 4127 50  0000 C CNN
F 2 "" H 3000 4300 50  0001 C CNN
F 3 "" H 3000 4300 50  0001 C CNN
	1    3000 4300
	1    0    0    -1  
$EndComp
Wire Wire Line
	2750 3700 2750 3600
Wire Wire Line
	2750 3600 3000 3600
Wire Wire Line
	3000 3600 3000 4050
$Comp
L power:+3.3V #PWR01
U 1 1 5DCC50FC
P 2750 2750
F 0 "#PWR01" H 2750 2600 50  0001 C CNN
F 1 "+3.3V" H 2765 2923 50  0000 C CNN
F 2 "" H 2750 2750 50  0001 C CNN
F 3 "" H 2750 2750 50  0001 C CNN
	1    2750 2750
	1    0    0    -1  
$EndComp
Wire Wire Line
	2750 2750 2750 2850
$Comp
L power:GNDPWR #PWR08
U 1 1 5DCC66DB
P 5850 3900
F 0 "#PWR08" H 5850 3700 50  0001 C CNN
F 1 "GNDPWR" H 5854 3746 50  0000 C CNN
F 2 "" H 5850 3850 50  0001 C CNN
F 3 "" H 5850 3850 50  0001 C CNN
	1    5850 3900
	1    0    0    -1  
$EndComp
$Comp
L power:GNDPWR #PWR07
U 1 1 5DCC7564
P 5850 3000
F 0 "#PWR07" H 5850 2800 50  0001 C CNN
F 1 "GNDPWR" H 5854 2846 50  0000 C CNN
F 2 "" H 5850 2950 50  0001 C CNN
F 3 "" H 5850 2950 50  0001 C CNN
	1    5850 3000
	1    0    0    -1  
$EndComp
Wire Wire Line
	5850 2750 5850 3000
Wire Wire Line
	5850 2450 6450 2450
Connection ~ 5850 2450
Wire Wire Line
	5850 3650 5850 3850
NoConn ~ 5000 4650
$Comp
L power:+5V #PWR010
U 1 1 5DCCD517
P 5200 4500
F 0 "#PWR010" H 5200 4350 50  0001 C CNN
F 1 "+5V" H 5215 4673 50  0000 C CNN
F 2 "" H 5200 4500 50  0001 C CNN
F 3 "" H 5200 4500 50  0001 C CNN
	1    5200 4500
	1    0    0    -1  
$EndComp
Wire Wire Line
	5200 4500 5200 4600
NoConn ~ 950  3700
NoConn ~ 1050 3700
NoConn ~ 1250 3700
NoConn ~ 1350 3700
NoConn ~ 1550 3700
NoConn ~ 1650 3700
NoConn ~ 1750 3700
NoConn ~ 1850 3700
NoConn ~ 1950 3700
NoConn ~ 2050 3700
NoConn ~ 2150 3700
NoConn ~ 2250 3700
NoConn ~ 2350 3700
NoConn ~ 2450 3700
NoConn ~ 2550 3700
NoConn ~ 2650 3700
NoConn ~ 2650 2900
NoConn ~ 2550 2900
NoConn ~ 2450 2900
NoConn ~ 2350 2900
NoConn ~ 2250 2900
NoConn ~ 2150 2900
NoConn ~ 2050 2900
NoConn ~ 1950 2900
NoConn ~ 1850 2900
NoConn ~ 1750 2900
NoConn ~ 1650 2900
NoConn ~ 1350 2900
NoConn ~ 1250 2900
NoConn ~ 1150 2900
NoConn ~ 1050 2900
NoConn ~ 950  2900
Wire Wire Line
	5850 3350 6450 3350
Connection ~ 5850 3350
Wire Wire Line
	1450 3550 3300 3550
Text GLabel 3300 3550 2    50   Input ~ 0
SDA
Text GLabel 3300 3400 2    50   Input ~ 0
SCL
Wire Wire Line
	1150 3400 3300 3400
$Comp
L power:GND #PWR09
U 1 1 5DCE1235
P 5000 5850
F 0 "#PWR09" H 5000 5600 50  0001 C CNN
F 1 "GND" H 5005 5677 50  0000 C CNN
F 2 "" H 5000 5850 50  0001 C CNN
F 3 "" H 5000 5850 50  0001 C CNN
	1    5000 5850
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR011
U 1 1 5DCE1B2C
P 5200 5850
F 0 "#PWR011" H 5200 5600 50  0001 C CNN
F 1 "GND" H 5205 5677 50  0000 C CNN
F 2 "" H 5200 5850 50  0001 C CNN
F 3 "" H 5200 5850 50  0001 C CNN
	1    5200 5850
	1    0    0    -1  
$EndComp
Text GLabel 5700 5350 2    50   Input ~ 0
SDA
Text GLabel 5700 5150 2    50   Input ~ 0
SCL
Wire Wire Line
	5700 4950 5850 4950
Connection ~ 5200 4600
Wire Wire Line
	5200 4600 5200 4650
$Comp
L Sensor:BME280 U3
U 1 1 5DCCA1DA
P 5100 5250
F 0 "U3" H 4671 5296 50  0000 R CNN
F 1 "BME280" H 4671 5205 50  0000 R CNN
F 2 "Package_LGA:Bosch_LGA-8_2.5x2.5mm_P0.65mm_ClockwisePinNumbering" H 6600 4800 50  0001 C CNN
F 3 "https://ae-bst.resource.bosch.com/media/_tech/media/datasheets/BST-BME280-DS002.pdf" H 5100 5050 50  0001 C CNN
	1    5100 5250
	1    0    0    -1  
$EndComp
NoConn ~ 5700 5550
$Comp
L Connector:Conn_01x01_Male J3
U 1 1 5DCE3EB4
P 6650 2450
F 0 "J3" H 6758 2631 50  0000 C CNN
F 1 "Conn_01x01_Male" H 6758 2540 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x01_P2.54mm_Vertical" H 6650 2450 50  0001 C CNN
F 3 "~" H 6650 2450 50  0001 C CNN
	1    6650 2450
	-1   0    0    1   
$EndComp
$Comp
L Connector:Conn_01x01_Male J4
U 1 1 5DCE4B30
P 6650 3350
F 0 "J4" H 6622 3282 50  0000 R CNN
F 1 "Conn_01x01_Male" H 6622 3373 50  0000 R CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x01_P2.54mm_Vertical" H 6650 3350 50  0001 C CNN
F 3 "~" H 6650 3350 50  0001 C CNN
	1    6650 3350
	-1   0    0    1   
$EndComp
$Comp
L Connector_Generic:Conn_01x19 J2
U 1 1 5DCA8418
P 1850 3900
F 0 "J2" V 1950 3950 50  0000 L CNN
F 1 "Conn_01x19" V 1950 3450 50  0000 L CNN
F 2 "Connector_PinSocket_2.54mm:PinSocket_1x19_P2.54mm_Vertical" H 1850 3900 50  0001 C CNN
F 3 "~" H 1850 3900 50  0001 C CNN
	1    1850 3900
	0    1    1    0   
$EndComp
Wire Wire Line
	1450 3550 1450 3700
Wire Wire Line
	1150 3400 1150 3700
$Comp
L power:PWR_FLAG #FLG0101
U 1 1 5DCAEA90
P 5450 2250
F 0 "#FLG0101" H 5450 2325 50  0001 C CNN
F 1 "PWR_FLAG" H 5450 2423 50  0000 C CNN
F 2 "" H 5450 2250 50  0001 C CNN
F 3 "~" H 5450 2250 50  0001 C CNN
	1    5450 2250
	1    0    0    -1  
$EndComp
Connection ~ 5450 2250
$Comp
L power:PWR_FLAG #FLG0102
U 1 1 5DCB0677
P 5450 3150
F 0 "#FLG0102" H 5450 3225 50  0001 C CNN
F 1 "PWR_FLAG" H 5450 3323 50  0000 C CNN
F 2 "" H 5450 3150 50  0001 C CNN
F 3 "~" H 5450 3150 50  0001 C CNN
	1    5450 3150
	1    0    0    -1  
$EndComp
Connection ~ 5450 3150
$Comp
L power:PWR_FLAG #FLG0103
U 1 1 5DCB0E6B
P 5200 4600
F 0 "#FLG0103" H 5200 4675 50  0001 C CNN
F 1 "PWR_FLAG" H 5200 4773 50  0000 C CNN
F 2 "" H 5200 4600 50  0001 C CNN
F 3 "~" H 5200 4600 50  0001 C CNN
	1    5200 4600
	1    0    0    -1  
$EndComp
$Comp
L power:PWR_FLAG #FLG0104
U 1 1 5DCB1284
P 2750 2850
F 0 "#FLG0104" H 2750 2925 50  0001 C CNN
F 1 "PWR_FLAG" H 2750 3023 50  0000 C CNN
F 2 "" H 2750 2850 50  0001 C CNN
F 3 "~" H 2750 2850 50  0001 C CNN
	1    2750 2850
	1    0    0    -1  
$EndComp
Connection ~ 2750 2850
Wire Wire Line
	2750 2850 2750 2900
$Comp
L power:PWR_FLAG #FLG0105
U 1 1 5DCB1AC0
P 3000 4050
F 0 "#FLG0105" H 3000 4125 50  0001 C CNN
F 1 "PWR_FLAG" H 3000 4223 50  0000 C CNN
F 2 "" H 3000 4050 50  0001 C CNN
F 3 "~" H 3000 4050 50  0001 C CNN
	1    3000 4050
	1    0    0    -1  
$EndComp
Connection ~ 3000 4050
Wire Wire Line
	3000 4050 3000 4300
$Comp
L power:PWR_FLAG #FLG0106
U 1 1 5DCB2099
P 5850 3850
F 0 "#FLG0106" H 5850 3925 50  0001 C CNN
F 1 "PWR_FLAG" H 5850 4023 50  0000 C CNN
F 2 "" H 5850 3850 50  0001 C CNN
F 3 "~" H 5850 3850 50  0001 C CNN
	1    5850 3850
	1    0    0    -1  
$EndComp
Connection ~ 5850 3850
Wire Wire Line
	5850 3850 5850 3900
NoConn ~ 5850 4950
$EndSCHEMATC
