
/*
 * Created by ASHIQ SHIBU (MAKER Q)
 * Project: Line following robot with obstacle avoidance
 * https://www.youtube.com/watch?v=Py2lBehF9rA
 */
  int vSpeed = 110;                      
  int turn_speed = 230;       // 0 - 255  max
  int t_p_speed = 125;
  int stop_distance = 12;
  int turn_delay = 10;


//HC-SR04 Sensor connection
  const int trigPin = 11;
  const int echoPin = 12;

//L293 Connection   
  const int motorA1      = 3;  
  const int motorA2      = 4; 
  const int motorAspeed  = 5;
  const int motorB1      = 7; 
  const int motorB2      = 8; 
  const int motorBspeed  =6;

//Sensor Connection
  const int left_sensor_pin =13;
  const int right_sensor_pin =10;

  
  int turnspeed;
  int left_sensor_state;
  int right_sensor_state;

  long duration;
  int distance;

void setup() {
  pinMode(motorA1, OUTPUT);
  pinMode(motorA2, OUTPUT);
  pinMode(motorB1, OUTPUT);
  pinMode(motorB2, OUTPUT);

  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT); 
    
  Serial.begin(9600);

  delay(3000);                              
  
}

void loop() {
  
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  
  distance= duration*0.034/2;
  Serial.print("Distance: ");
  Serial.println(distance);


left_sensor_state = digitalRead(left_sensor_pin);
right_sensor_state = digitalRead(right_sensor_pin);

if(left_sensor_state == HIGH || right_sensor_state == HIGH)
{
  digitalWrite (motorA1,LOW);
  
  //digitalWrite(motorA2,LOW);                       
}

else
{
  digitalWrite (motorA1,HIGH);
  //digitalWrite(motorA2,HIGH); 
}
}







 
