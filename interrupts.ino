void on_rotate_right() {
  unsigned long time_now = millis(); 
  if(time_now - last_time_right < 50)
    return;
   right_steps++;
   last_time_right = time_now;

   if(counter_right > 0) {
    counter_right -=1;
//
//    Serial.println("Counter right");
//    Serial.println(counter_right);

    if(counter_right == 0) {
      end_turn = true;
    }
  }
}

void on_rotate_left() {
  unsigned long time_now = millis(); 
  if(time_now - last_time_left < 50)
    return;
  left_steps++;
  last_time_left = time_now;


  if(counter_left > 0) {
    counter_left -=1;
//
//     Serial.println("Counter left");
//    Serial.println(counter_left);

     if(counter_left == 0) {
        end_turn = true;
    }
  }

}
