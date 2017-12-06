//Arduino PWM Speed Control：
int E1 = 5;  
int M1 = 4; 
int E2 = 6;                      
int M2 = 7;
int soilSensor = 0;

//moisture variables
int moistureThreshold = 300;
int waitTime = 5000; //ms
int waterTime = 1000; //ms

 
void setup() 
{ 
    pinMode(M1, OUTPUT);
    pinMode(A0, INPUT); 
    Serial.begin(57600);
} 
 
void loop() 
{ 
 
soilSensor = analogRead(A0);
Serial.println(soilSensor); //use for calibration
if (soilSensor < moistureThreshold) {
  digitalWrite(M1, HIGH);
  analogWrite(E1, 255);
  delay(waterTime);
  digitalWrite(M1, LOW);
  analogWrite(E1, 0); 
}
delay(waitTime);
 
 
}




