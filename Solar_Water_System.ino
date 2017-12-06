//Arduino PWM Speed Control：
int E1 = 5;  
int M1 = 4; 
int E2 = 6;                      
int M2 = 7;
int soilSensor = 0;

//moisture variables
int moistureThreshold = 300;//calibrate this variable based on how damp the soil needs to be for the particular plant
int waitTime = 5000; //ms
int waterTime = 1000; //ms

 
void setup() 
{ 
    pinMode(M1, OUTPUT);//motor 1
    pinMode(A0, INPUT); //moisture sensor input
    Serial.begin(57600);//comment out after calibration
} 
 
void loop() 
{ 
 
soilSensor = analogRead(A0);
Serial.println(soilSensor); //use for calibration, then comment out
if (soilSensor < moistureThreshold) {
  digitalWrite(M1, HIGH);//turn motor 1 one
  analogWrite(E1, 255);//PWM speed control
  delay(waterTime);
  digitalWrite(M1, LOW);
  analogWrite(E1, 0); 
}
delay(waitTime);
 
 
}




