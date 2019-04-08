int Trig = 12; 
int Echo = 11; 
int distance;        //odległość w cm
int previousDistance = 400;
long return_time;     //długość powrotnego impulsu w uS

static unsigned long lastTime = 0;

uint8_t speed = 100;

volatile unsigned int right_steps = 0;
volatile unsigned int left_steps = 0; 

volatile unsigned long last_time_right = 0;
volatile unsigned long last_time_left = 0;

volatile byte counter_left = 0;
volatile byte counter_right = 0;

volatile bool end_turn = false;

#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include <Servo.h>
#include <LiquidCrystal_I2C.h>

Adafruit_MotorShield AFMS = Adafruit_MotorShield(); 
Adafruit_DCMotor *motor1 = AFMS.getMotor(1); // LEWY PRZEDNI
Adafruit_DCMotor *motor2 = AFMS.getMotor(2); // LEWY TYLNI
Adafruit_DCMotor *motor3 = AFMS.getMotor(3); // PRAWY PRZEDNI
Adafruit_DCMotor *motor4 = AFMS.getMotor(4); // PRAWY TYLNI

Servo servo;

boolean move = true;

LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);  // Ustawienie adresu ukladu na 0x27

void setup() {
  Serial.begin(9600);    
  Serial.println("Adafruit Motorshield v2 - DC Motor test!");

  pinMode(Trig, OUTPUT);
  pinMode(Echo, INPUT);
  pinMode(10,OUTPUT);

  AFMS.begin();  // create with the default frequency 1.6KHz
  servo.write(90);
  servo.attach(9);
  servo.write(90);

  pinMode(2,INPUT_PULLUP);
  pinMode(3,INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(2),on_rotate_right,FALLING);
  attachInterrupt(digitalPinToInterrupt(3),on_rotate_left,FALLING);
  ride(speed,true,0);
  lcd.begin(16,2); 
  // tone(10, 300, 1000); 
  //lcd.noBacklight();
}

void loop() {
//    servo.write(90);

  if(end_turn == true) {
    ride(speed,true,0);
    end_turn = false;
    move = true;
  }

  byte i;
  measure_distance();
  unsigned long timeNow = millis(); 
  delay(200);
  if(timeNow - lastTime > 1000) {
    lastTime = timeNow;
    print_distance();
  }
  
  if(distance < 40 && previousDistance < 40 && distance > 0 && move == true) {
    print_distance();
    move = false;
    stop();
 //   tone(10, 500, 300); 
    makeDecisionWhereToTurnDuringStop();
//    ride(speed,true,0);
//   move = true;
  }
  previousDistance = distance;
}
