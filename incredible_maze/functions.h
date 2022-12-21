#ifndef FUNCTIONS_H
#define FUNCTIONS_H

// joystick_move.h
void inputData();

// settings_menu.h
void settingsMenu();
void enterNameMenu();
void selectLevelMenu();
void lcdBrightnessMenu();
void matrixBrightnessMenu();
void selectSoundMenu();
void resetHighscoreMenu();

// main_menu.h
void welcome();
void mainMenu();
void highscoreMenu();
void creditsMenu();
void howToPlayMenu();

// core.h
void changeState();
void menuArrows();
void displayImage(uint64_t image);
void displayGame();
int getValue(int i, int j);
void setValue(int i, int j, int value);
void beepBuzz(int *beepType);
void resetHighscore();

// game.h
void run();
void winEndGame();
void explosionEndGame();
void nextLevelMenu();
void saveScore();
void movePlayer();
void bombCheck();
void easterEgg();
bool legalMove(byte i, byte j);
void blinkPlayer();
void printScore();

#endif