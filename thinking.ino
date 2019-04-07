void makeDecisionWhereToTurnDuringStop(){
  servo.write(10);
  delay(500);
  measure_distance();
  int left = distance;
  servo.write(90);
  delay(500);
  measure_distance();
  int center = distance;
  servo.write(170);
  delay(500);
  measure_distance();
  int right = distance;
  servo.write(90);
  delay(500);
  
  if (right >= center && right >= left) {
    ride(100,false,250);
    turn_right();
  }
  else if (left >= right  && left >=center) {
    ride(100,false,250);
    turn_left();
    
  }
}
