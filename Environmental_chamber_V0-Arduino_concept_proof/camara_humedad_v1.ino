
//codigo inicial V1 de control de la humedad: 
  //valor deseado ingresado por macro
  //usando un humidificador con un circuito externo generador de la frecuencia
  //deshumidificacion con bomba de aire por silica gel

//Libraries
#include <Seeed_BME280.h>
#include <Wire.h>
#include <FastPwmPin.h>

//Input Target Humidity 
#define TARGET_RH 40
//Delta RH
#define DELTA_RH 1
//Number of cicles to do de promediation in every read_RH()
#define N_CICLES_PER_READ_RH 5

//Humidity Sensors BME280
BME280 bme280_1;
BME280 bme280_2;

//Humidificator & Dehumidificator
int hum_on=4;
int hum_led=1;
int dehum_on=2;
int dehum_led=0;

//switch to turn on/off the system
int switch_pin=3;

//global variables
int target_RH;
bool control_ON;
int actual_average_RH;


void setup() {
  //Serial Comunication
   Serial.begin(9600);

  //BME280 Sensor comunication (I2C ==> both sensor to the same SDA & SCL pins of the arduino)
  if(!bme280_1.init(0x76)){
    Serial.println("Device error!");
  }
  if(!bme280_2.init(0x77)){
    Serial.println("Device error!");
  }

  //Humidificator pin out
  pinMode(hum_on,OUTPUT);
  pinMode(hum_led,OUTPUT);
  
  //Dehumidificator pin out
  pinMode(dehum_on,OUTPUT);
  pinMode(dehum_led,OUTPUT);

  //switch control ON/OFF pin
  pinMode(switch_pin,INPUT);
  
  FastPwmPin::enablePwmPin(11, 118000L, 45);
   
}

void loop() {
delay(10000);
Serial.println("hola");
delay(10000);
target_RH=get_target_humidity();
actual_average_RH=read_RH();

control_ON= HIGH; //digitalRead(switch_pin);
if(control_ON == HIGH){
  rh_control(); 
}

print_RH_status();

delay(1000);
}

void rh_control(){
  
    
  if(actual_average_RH<=(target_RH+DELTA_RH)&& actual_average_RH>=(target_RH-DELTA_RH)){  //keep humidity
     Serial.println("State: keep Humidity");
    digitalWrite(dehum_on,LOW);
    digitalWrite(hum_on,LOW);
    digitalWrite(dehum_led,LOW);
    digitalWrite(hum_led,LOW);
  }
  else if(actual_average_RH>(target_RH+DELTA_RH)){  //dehumidify
    Serial.println("State: dehumidify");



    digitalWrite(dehum_on,HIGH);
    digitalWrite(hum_on,LOW);

  }
  if(actual_average_RH<(target_RH-DELTA_RH)){  //humidify

     Serial.println("State: humidify");

    digitalWrite(dehum_on,LOW);
    digitalWrite(hum_on,HIGH);


  }
  
}

int read_RH(){
  int aux=0;
  int n_cicles= N_CICLES_PER_READ_RH;
  for(int i=0;i<n_cicles;i++){
  aux = aux+(bme280_1.getHumidity()+bme280_2.getHumidity())/2;
  delay(500);
  }
  return aux/n_cicles;
}

int get_target_humidity(){
  return TARGET_RH;
}
  
void print_RH_status(){
 Serial.print("Humidity control ON:");
 Serial.println(control_ON);
 Serial.print("Actual target RH =");
 Serial.println(target_RH);
 Serial.print("Sensor 1 RH: ");
 Serial.println(bme280_1.getHumidity());
 Serial.print("Sensor 2 RH: ");
 Serial.println(bme280_2.getHumidity());
 Serial.print("Average RH: ");
 Serial.println(actual_average_RH);
  
}
  
