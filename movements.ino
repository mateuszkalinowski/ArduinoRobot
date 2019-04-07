void turn_left() {
  motor1->run(RELEASE);
  motor2->run(RELEASE);
  motor3->run(FORWARD);
  motor4->run(FORWARD);
   
  motor3->setSpeed(100);
  motor4->setSpeed(100);

  counter_right = 48;

//  int steps = right_steps;
//  steps = steps + 10;
//  while(right_steps < steps) {
//    delay(100);
//  }

//  delay(2000);
//  motor3->run(RELEASE);
//  motor4->run(RELEASE);
}

void turn_right() {
  motor1->run(FORWARD);
  motor2->run(FORWARD);
  motor3->run(RELEASE);
  motor4->run(RELEASE);

  motor1->setSpeed(100); 
  motor2->setSpeed(100);  

  counter_left = 48;

//  int steps = left_steps;
//  steps = steps + 10;
//  while(left_steps < steps) {
//    delay(100);
//  }
//  delay(2000);
//  motor1->run(RELEASE);
//  motor2->run(RELEASE);
}

void ride(int speed, bool direction,byte time){
    motor1->setSpeed(speed+5); 
    motor2->setSpeed(speed+5);  
    motor3->setSpeed(speed);
    motor4->setSpeed(speed);

    if(direction == true) {
      motor1->run(FORWARD);
      motor2->run(FORWARD);
      motor3->run(FORWARD);
      motor4->run(FORWARD);
    }
    else {
      motor1->run(BACKWARD);
      motor2->run(BACKWARD);
      motor3->run(BACKWARD);
      motor4->run(BACKWARD);
    }

    if(time>0) {
      delay(time);
      stop();
    }
}

void stop() {
  motor1->run(RELEASE);
  motor2->run(RELEASE);
  motor3->run(RELEASE);
  motor4->run(RELEASE);
}
