#ifndef GAME_H
#define GAME_H

void run() {
  if(!easterEggDiscovered) {
    elapsedTime = millis() - startGameTime;
  }
  else {
    elapsedTime = max(1, millis() - startGameTime - easterEggMinusTime * 1000 - easterEggMsgTime);
  }

  movePlayer();
  blinkPlayer();
  bombCheck();
  printScore();

  if(elapsedTime > easterEggMinusTime * 1000 && easterEggActivated && !easterEggDiscovered) {
    easterEggActivated = false;
    easterEggDiscovered = true;
    if(soundOn) {
      buzzer.playMelody(easterEggMelody, easterEggNoteDurations, sizeof(easterEggNoteDurations) / sizeof(int));
    }
    easterEggMoment = millis() - 5;

    gameState = easterEggGS;
    lcd.clear();
  }

  if(explosion) {    
    setValue(playerX, playerY, 1);
    explosionMoment = millis() - 5;
    if(soundOn) {
      buzzer.playMelody(explosionMelody, explosionNoteDurations, sizeof(explosionNoteDurations) / sizeof(int));
    }

    gameState = explosionEndGameGS;
    lcd.clear();
  }

  if(win) {
    win = false;
    if(soundOn) {
      buzzer.playMelody(easterEggMelody, easterEggNoteDurations, sizeof(easterEggNoteDurations) / sizeof(int));
    }
    setValue(playerX, playerY, 1);
    gameState = winEndGameGS;
    lcd.clear();
  }

  displayGame();
}

void winEndGame() {
  lcd.setCursor(0, 0);
  lcd.print("Congrats,     !");
  lcd.setCursor(10, 0);
  lcd.print(currentName[0]);
  lcd.setCursor(11, 0);
  lcd.print(currentName[1]);
  lcd.setCursor(12, 0);
  lcd.print(currentName[2]);
  lcd.setCursor(13, 0);
  lcd.print(currentName[3]);
  
  lcd.setCursor(0, 1);
  lcd.print("Time: ");

  lcd.setCursor(6, 1);
  lcd.print(elapsedTime / 1000);

  lcd.setCursor(12, 1);
  lcd.print("LVL");
  lcd.setCursor(15, 1);
  lcd.print(currentLevel);

  if(buttonPressed) {
    saveScore();
    setValue(playerX, playerY, 0);
    mapX = 0;
    mapY = 0;
    playerX = 1;
    playerY = 1;

    gameState = nextLevelGS;
    buttonPressed = false;
    lcd.clear();
  }
}

void explosionEndGame() {
  if(millis() - explosionMoment < explosionMsgTime) {
    lcd.setCursor(1, 0);
    lcd.print("Bomb exploded!");

    lcd.setCursor(0, 1);
    lcd.print("Be careful,     ");
    lcd.setCursor(12, 1);
    lcd.print(currentName[0]);
    lcd.setCursor(13, 1);
    lcd.print(currentName[1]);
    lcd.setCursor(14, 1);
    lcd.print(currentName[2]);
    lcd.setCursor(15, 1);
    lcd.print(currentName[3]);
  }
  else if(explosion) {
    explosion = false;
    lcd.clear();
  }
  else if(!explosion) {
    lcd.setCursor(1, 0);
    lcd.print("Bomb exploded!");

    lcd.setCursor(1, 1);
    lcd.write(arrowLeftCode);
    lcd.setCursor(2, 1);
    lcd.print("Exit");

    lcd.setCursor(14, 1);
    lcd.write(arrowRightCode);
    lcd.setCursor(9, 1);
    lcd.print("Retry");

    if(right) {
      gameState = initGameMapGS;
      right = false;
      lcd.clear();
    }

    if(left) {
      gameState = mainMenuGS;
      left = false;
      lcd.clear();
    }
  }
}

void nextLevelMenu() {
  lcd.setCursor(0, 0);
  lcd.print("Highscore pos  !");
  lcd.setCursor(14, 0);
  lcd.print("8");

  lcd.setCursor(1, 1);
  lcd.write(arrowLeftCode);
  lcd.setCursor(2, 1);
  lcd.print("Exit");

  if(currentLevel != maxLevel) {
    lcd.setCursor(14, 1);
    lcd.write(arrowRightCode);
    lcd.setCursor(10, 1);
    lcd.print("Next");
    
    if(right) {
      currentLevel = min(maxLevel, currentLevel + 1);
      settingsMenuItems[1][9] = (char)(48 + currentLevel);
      gameState = initGameMapGS;
      right = false;
      lcd.clear();
    }
  }

  if(left) {
    gameState = mainMenuGS;
    left = false;
    lcd.clear();
  }

}

void saveScore() {
  static int i, j, score, currentScore, currentLevelStartAddress;
  static bool ok;
  ok = true;
  currentLevelStartAddress = 3;// + currentLevel * infoDim * topDim; // --------------------------------------------- to be changed
  currentScore = elapsedTime / 1000;

  for(i = 1; i <= topDim; i++) {
    score = (int)EEPROM.read(currentLevelStartAddress + infoDim * i - 1);
    if(score == 0 || currentScore > score) {



      for(j = currentLevelStartAddress + infoDim * topDim - 1; j > infoDim * i - 1; j--) {
        EEPROM.update(j, EEPROM.read(j - infoDim));
      }

      EEPROM.update(currentLevelStartAddress + infoDim * (i - 1), (int)currentName[0]);
      EEPROM.update(currentLevelStartAddress + infoDim * (i - 1) + 1, (int)currentName[1]);
      EEPROM.update(currentLevelStartAddress + infoDim * (i - 1) + 2, (int)currentName[2]);
      EEPROM.update(currentLevelStartAddress + infoDim * (i - 1) + 3, (int)currentName[3]);
      EEPROM.update(currentLevelStartAddress + infoDim * (i - 1) + 4, (int)currentScore);
      EEPROM.update(currentLevelStartAddress + infoDim * (i - 1) + 5, (int)currentLevel);
      i = 6;
    }
  }
}

bool legalMove(int i, int j) {
  return i >= 0 && j >= 0 && i <= mapSize && j <= mapSize && getValue(i, j) != 1;
}

void movePlayer() {
  if(up) {
    if(legalMove(playerX - 1, playerY)) {
      setValue(playerX, playerY, 0);
      playerX--;
      setValue(playerX, playerY, 1);

      if(mapX > 0 && playerX < mapX + mapBorder) {
        mapX--;
      }
      beepBuzz(yepBeep);
    }
    else {
      beepBuzz(nopeBeep);
    }
    up = false;
  }

  if(down) {
    if(legalMove(playerX + 1, playerY)) {
      setValue(playerX, playerY, 0);
      playerX++;
      setValue(playerX, playerY, 1);

      if(mapX < mapSize - 7 && playerX > mapX + 7 - mapBorder) {
        mapX++;
      }
      beepBuzz(yepBeep);
    }
    else {
      beepBuzz(nopeBeep);
    }
    down = false;
  }

  if(left) {
    if(legalMove(playerX, playerY - 1)) {
      setValue(playerX, playerY, 0);
      playerY--;
      setValue(playerX, playerY, 1);

      if(mapY > 0 && playerY < mapY + mapBorder) {
        mapY--;
      }
      beepBuzz(yepBeep);
    }
    else {
      beepBuzz(nopeBeep);
    }
    left = false;
  }

  if(right) {
    if(legalMove(playerX, playerY + 1)) {
      setValue(playerX, playerY, 0);
      playerY++;
      setValue(playerX, playerY, 1);

      if(mapY < mapSize - 7 && playerY > mapY + 7 - mapBorder) {
        mapY++;
      }
      beepBuzz(yepBeep);
    }
    else {
      beepBuzz(nopeBeep);
    }
    right = false;
  }

  if(playerX == mapSize && playerY == mapSize) {
    win = true;
  }
}

void blinkPlayer() {
  if(!win && elapsedTime % 50 < 5) {
    setValue(playerX, playerY, !getValue(playerX, playerY));
  }
}

void bombCheck() {
  static int i, k;
  nearBomb = false;

  for(i = 0; i < bombCount; i++) {
    if(playerX == easterEggX && playerY == easterEggY && elapsedTime > easterEggMinusTime * 1000) {
      easterEggActivated = true;
      setValue(easterEggX, easterEggY, 0);

      easterEggX = 0;
      bombX[i] = 0;
      easterEggY = 0;
      bombY[i] = 0;
    }
    else if(playerX == bombX[i] && playerY == bombY[i]) {
      explosion = true;
      nearBomb = true;
    }

    for(k = 0; k < directions; k++) {
      if(legalMove(playerX + dX[k], playerY + dY[k])) {
        if((playerX + dX[k] == bombX[i]) && (playerY + dY[k] == bombY[i])) {
          nearBomb = true;
        }
      }
    }
  }

  if(nearBomb) {
    analogWrite(bombLedPin, 255);
  }
  else {
    analogWrite(bombLedPin, 0);
  }
}

void easterEgg() {
  if(millis() - easterEggMoment < easterEggMsgTime) {
    lcd.setCursor(3, 0);
    lcd.print("EASTER EGG");
    lcd.setCursor(0, 1);
    lcd.print("minus    seconds");
    lcd.setCursor(6, 1);
    lcd.print(easterEggMinusTime);
  }
  else {
    gameState = runGS;
    lcd.clear();
  }
}

void printScore() {
  lcd.setCursor(0, 0);
  lcd.print("Move fast,     !");

  lcd.setCursor(11, 0);
  lcd.print(currentName[0]);
  lcd.setCursor(12, 0);
  lcd.print(currentName[1]);
  lcd.setCursor(13, 0);
  lcd.print(currentName[2]);
  lcd.setCursor(14, 0);
  lcd.print(currentName[3]);  

  lcd.setCursor(0, 1);
  lcd.print("Time: ");

  lcd.setCursor(6, 1);
  lcd.print(elapsedTime / 1000);

  lcd.setCursor(12, 1);
  lcd.print("LVL");
  lcd.setCursor(15, 1);
  lcd.print(currentLevel);
}

#endif