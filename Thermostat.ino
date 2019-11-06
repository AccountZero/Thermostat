#include "DHT.h"
/*
author: Hubert 
description: The thermostat does measure the temperature and heats up or cools down the temperature whenever it's too hot (over 30C) or too cold (under 20C)
*/

// Digital pin connected to the DHT 
#define DHTPIN 8
// DHT 11 (Version of sensor)
#define DHTTYPE DHT11   

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  //initialise Monitor
  Serial.begin(9600); 

  //initialise pin for relay;
  pinMode (6, OUTPUT);
  
  //initialise pin for sound;
  pinMode (7, OUTPUT);
  
  //initialise pin for color: red
  pinMode(11, OUTPUT); 
  //initialise pin for color: blue
  pinMode(12, OUTPUT);
  //initialise pin for color: green 
  pinMode(13, OUTPUT);

  //initialise dht
  dht.begin(); 
}

void my_beep(int d, int duration, int iteration){
  unsigned char i, j;
  for(i = 0; i < iteration; i++){
     for (j = 0; j < duration; j++){ // Wen a frequency sound
       digitalWrite (7, HIGH) ;// send voice
       delay (d) ;// Delay 1ms
       digitalWrite (7, LOW) ;// do not send voice
       delay (d) ;// delay ms
     }
     delay(30);
   }
}


void temperature(){
  //Delay for meassurment (This sensor is slow)
  delay(2000);
  
  // Read temperature as Celsius
  float t = dht.readTemperature();
  
  if(t > 30){
    //beep as a warning
    my_beep(1, 50, 4);
    
    //change the light to red
    digitalWrite(11, HIGH);
    digitalWrite(12, LOW);
    digitalWrite(13, LOW);
    
    //print temperature + Message
    Serial.print(F("Temperature: "));
    Serial.println(t);
    Serial.println("Too hot, cooling down...");

    //turn on relay module for cooling (theoretically)
    digitalWrite(6, HIGH);
   }
   
   else if(t < 20){
    //beep as a warning
    my_beep(3, 160, 1);
    
    //change the light to blue
    digitalWrite(11, LOW);
    digitalWrite(12, HIGH);
    digitalWrite(13, LOW);
    
     //print temperature + Message
    Serial.print(F("Temperature: "));
    Serial.println(t);
    Serial.println("Too cold, heating up...");

    //turn on relay module for heating (theoretically)
    digitalWrite(6, HIGH); 
   }
   
   else{
     //change the light to blue
    digitalWrite(11, LOW);
    digitalWrite(12, LOW);
    digitalWrite(13, HIGH);
    
    //print temperature
    Serial.print(F("Temperature: "));
    Serial.println(t);

    //turn off relay module for cooling/heating (theoretically)
    digitalWrite(6, LOW);
   }
}

void loop() {
  //measure the temperature
  temperature();
}#include "DHT.h"
/*
author: Hubert Korona
description: The thermostat does measure the temperature and heats up or cools down the temperature whenever it's too hot (over 30C) or too cold (under 20C)
*/

// Digital pin connected to the DHT 
#define DHTPIN 8
// DHT 11 (Version of sensor)
#define DHTTYPE DHT11   

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  //initialise Monitor
  Serial.begin(9600); 

  //initialise pin for relay;
  pinMode (6, OUTPUT);
  
  //initialise pin for sound;
  pinMode (7, OUTPUT);
  
  //initialise pin for color: red
  pinMode(11, OUTPUT); 
  //initialise pin for color: blue
  pinMode(12, OUTPUT);
  //initialise pin for color: green 
  pinMode(13, OUTPUT);

  //initialise dht
  dht.begin(); 
}

void my_beep(int d, int duration, int iteration){
  unsigned char i, j;
  for(i = 0; i < iteration; i++){
     for (j = 0; j < duration; j++){ // Wen a frequency sound
       digitalWrite (7, HIGH) ;// send voice
       delay (d) ;// Delay 1ms
       digitalWrite (7, LOW) ;// do not send voice
       delay (d) ;// delay ms
     }
     delay(30);
   }
}


void temperature(){
  //Delay for meassurment (This sensor is slow)
  delay(2000);
  
  // Read temperature as Celsius
  float t = dht.readTemperature();
  
  if(t > 30){
    //beep as a warning
    my_beep(1, 50, 4);
    
    //change the light to red
    digitalWrite(11, HIGH);
    digitalWrite(12, LOW);
    digitalWrite(13, LOW);
    
    //print temperature + Message
    Serial.print(F("Temperature: "));
    Serial.println(t);
    Serial.println("Too hot, cooling down...");

    //turn on relay module for cooling (theoretically)
    digitalWrite(6, HIGH);
   }
   
   else if(t < 20){
    //beep as a warning
    my_beep(3, 160, 1);
    
    //change the light to blue
    digitalWrite(11, LOW);
    digitalWrite(12, HIGH);
    digitalWrite(13, LOW);
    
     //print temperature + Message
    Serial.print(F("Temperature: "));
    Serial.println(t);
    Serial.println("Too cold, heating up...");

    //turn on relay module for heating (theoretically)
    digitalWrite(6, HIGH); 
   }
   
   else{
     //change the light to blue
    digitalWrite(11, LOW);
    digitalWrite(12, LOW);
    digitalWrite(13, HIGH);
    
    //print temperature
    Serial.print(F("Temperature: "));
    Serial.println(t);

    //turn off relay module for cooling/heating (theoretically)
    digitalWrite(6, LOW);
   }
}

void loop() {
  //measure the temperature
  temperature();
}
