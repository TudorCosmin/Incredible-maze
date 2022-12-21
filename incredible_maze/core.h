#ifndef CORE_H
#define CORE_H

void initialization() {
  lcdBrightness = EEPROM.read(lcdBrightnessAddress);
  matrixBrightness = EEPROM.read(matrixBrightnessAddress);
  soundOn = EEPROM.read(soundAddress);  

  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(lcdBrightnessPin, OUTPUT);

  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.createChar(arrowUpCode, arrowUpChar);
  lcd.createChar(arrowDownCode, arrowDownChar);
  lcd.createChar(arrowLeftCode, arrowLeftChar);
  lcd.createChar(arrowRightCode, arrowRightChar);
  lcd.createChar(slidingBarCode, slidingBarChar);
  
  matrix.shutdown(0, false);
  matrix.setIntensity(0, matrixBrightness);
  matrix.clearDisplay(0);

  analogWrite(lcdBrightnessPin, lcdBrightness);
  if(soundOn) {
    settingsMenuItems[4][9] = 'Y';
  }
  else {
    settingsMenuItems[4][9] = 'N';
  }

  gameState = welcomeGS;
  welcomeMoment = millis();
  if(soundOn) {
    buzzer.playMelody(welcomeMelody, welcomeNoteDurations, sizeof(welcomeNoteDurations) / sizeof(int));
  }
}

void changeState() {
  if(gameState == welcomeGS) {
    welcome();
  }

  // ------------------------------------------------ menu
  else if(gameState == mainMenuGS) {
    mainMenu();
  }
  else if(gameState == highscoreGS) {
    highscoreMenu();
  }
  else if(gameState == settingsGS) {
    settingsMenu();
  }
  else if(gameState == creditsGS) {
    creditsMenu();
  }
  else if(gameState == howToPlayGS) {
    howToPlayMenu();
  }
  else if(gameState == enterNameGS) {
    enterNameMenu();
  }
  else if(gameState == selectLevelGS) {
    selectLevelMenu();
  }
  else if(gameState == lcdBrightnessGS) {
    lcdBrightnessMenu();
  }
  else if(gameState == matrixBrightnessGS) {
    matrixBrightnessMenu();
  }
  else if(gameState == selectSoundGS) {
    selectSoundMenu();
  }
  else if(gameState == resetHighscoreGS) {
    resetHighscoreMenu();
  }

  // ------------------------------------------------ gameplay
  else if(gameState == initGameMapGS) {
    initGameMap();
  }
  else if(gameState == runGS) {
    run();
  }
  else if(gameState == winEndGameGS) {
    winEndGame();
  }
  else if(gameState == explosionEndGameGS) {
    explosionEndGame();
  }
  else if(gameState == nextLevelGS) {
    nextLevelMenu();
  }
  else if(gameState == easterEggGS) {
    easterEgg();
  }
}

void welcome() {
  if(millis() - welcomeMoment < welcomeMsgTime) {
    displayImage(images[6]);

    lcd.setCursor(0, 0);
    lcd.print("   Welcome to");
    lcd.setCursor(0, 1);
    lcd.print("Incredible maze!");
  }
  else {
    gameState = mainMenuGS;
    lcd.clear();
  }
}

void menuArrows() {
  if(currentItem == minCurrentItem) {
    lcd.setCursor(15, 1);
    lcd.write(arrowDownCode);
  }
  else if(currentItem == maxCurrentItem) {
      lcd.setCursor(15, 0);
      lcd.write(arrowUpCode);
  }
  else {
    lcd.setCursor(15, 0);
    lcd.write(arrowUpCode);
    lcd.setCursor(15, 1);
    lcd.write(arrowDownCode);
  }
}

void displayImage(uint64_t image) {
  static int i, j;
  for(i = 0; i < 8; i++) {
    byte row = (image >> i * 8) & 0xFF;
    for(j = 0; j < 8; j++) {
      matrix.setLed(0, i, j, bitRead(row, j));
    }
  }
}

void displayGame() {
  static int i, j;

  for(i = 0; i < 8; i++) {
    for(j = 0; j < 8; j++) {
      matrix.setLed(0, i, j, getValue(mapX + i, mapY + j));
    }
  }
}

int getValue(int i, int j) {
  return bitRead(gameMap[i], mapSize - j);
}

void setValue(int i, int j, int value) {
  bitWrite(gameMap[i], mapSize - j, value);
}

void beepBuzz(int *beepType) {
  if(soundOn) {
    buzzer.playMelody(beepType, beepDuration, 1);
  }
}

void resetHighscore() {
  for(int i = 3; i < 3 + 25 * (maxLevel + 1); i++) {
    EEPROM.update(i, 0);
  }
}

#endif