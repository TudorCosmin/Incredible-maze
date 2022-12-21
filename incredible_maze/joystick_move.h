#ifndef JOYSTICK_MOVE_H
#define JOYSTICK_MOVE_H

void inputData() {
  xValue = analogRead(pinX);
  yValue = analogRead(pinY);
  reading = digitalRead(buttonPin);

  if(reading != lastReading)
    lastDebounceTime = millis();

  if(millis() - lastDebounceTime > shortDebounceDelay) {
    if(reading != buttonState) {
      buttonState = reading;
      if(buttonState == LOW) {
        buttonPressed = true;
      }
      else buttonPressed = false;
    } 
  }
  lastReading = reading;

  if( (minThreshold <= xValue && xValue <= maxThreshold) && (minThreshold <= yValue && yValue <= maxThreshold) ) {
    joyMoved = false;
    up = down = left = right = false;
  }

  if(yValue < minThreshold && joyMoved == false) { // up
    joyMoved = true;
    down = true;
  }

  if(yValue > maxThreshold && joyMoved == false) { // down
    joyMoved = true;
    up = true;
  }

  if(xValue < minThreshold && joyMoved == false) { // left
    joyMoved = true;
    right = true;
  }

  if(xValue > maxThreshold && joyMoved == false) { // right
    joyMoved = true;
    left = true;
  }
}

#endif