#include <AccelStepper.h>
#define dir 8
#define pul 9 //100000 steps max
#define button 4
#define ena 13
#define sensorPin A0
int sensorMeasureDistance=0; //"sm"
int boyu; //insanin boyu "sm"
const int terminalYerMesafesi=200; //"sm" measure between terminal and ground is constant
int Position=0;
//declare pin connect
//AccelStepper::DRIVER
//AccelStepper stepper1(AccelStepper::FULL3WIRE, 5, 4, 3, 2);
AccelStepper stepper(1, 9, 8);
//Set default motor speed,acceleration,disableOutputs,currentPosition
void setup() {     
  //Serial.begin(9600);
  stepper.setMaxSpeed(30000); //SPEED = Steps / second
  stepper.setAcceleration(1000); //ACCELERATION = Steps /(second)^2
  stepper.disableOutputs();
  stepper.setCurrentPosition(0);
}
void loop() { 
  stepper.run();
  sensorMeasureDistance = analogRead(sensorPin) * 1;//read sesnor value
  boyu=terminalYerMesafesi-sensorMeasureDistance;
  int buttonvalue=digitalRead(button);//read button value(1 or 0)
  //Serial.print(buttonvalue);
  //Serial.println( sensorMeasureDistance);
  //delay(500);
if(buttonvalue==1){
  stepper.setCurrentPosition(0);
  stepper.stop();
  }
//Heigh-> 150 <=> 170
if(boyu>=150 && boyu<=170){
  if(Position==0){
  stepper.setMaxSpeed(29000);                                         //check human heigh and direction motor
  stepper.moveTo(30000);
  Position=30000;
  }
  else if(Position==50000){
  stepper.setMaxSpeed(29000);                                         //check human heigh and direction motor
  stepper.moveTo(-20000);
  Position=30000;
  }
  else if(Position==70000){
  stepper.setMaxSpeed(29000);                                         //check human heigh and direction motor
  stepper.moveTo(-40000);
  Position=30000;
  }}
//Heigh-> 171 <=> 188
if(boyu>=171 && boyu<=188){
  if(Position==0){
  stepper.setMaxSpeed(29000);
  stepper.moveTo(50000);
  Position=50000;
  }
  else if(Position==30000){
  stepper.setMaxSpeed(29000);
  stepper.moveTo(20000);
  Position=50000;
  }
  else if(Position==70000){
  stepper.setMaxSpeed(29000);
  stepper.moveTo(-20000);
  Position=50000;
  }}
//Heigh-> 190 <=> 195
if(boyu>=190 &&boyu<=195){
  if(Position==0){
  stepper.setMaxSpeed(13000); //set speed
  stepper.moveTo(70000);
  Position=70000;
  }
  else if(Position=30000){
  stepper.setMaxSpeed(13000); //set speed
  stepper.moveTo(50000);  
  Position=70000;
  }
  else if(Position==50000){
  stepper.setMaxSpeed(13000); //set speed
  stepper.moveTo(20000);  
  Position=70000;
  }}}
