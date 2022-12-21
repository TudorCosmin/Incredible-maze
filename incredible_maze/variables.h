#ifndef VAEIABLES_H
#define VARIABLES_H

#include <LiquidCrystal.h>
#include <LedControl.h>
#include <EEPROM.h>
#include <ezBuzzer.h>


// ------------------------------------------------ joystick variables
const byte buttonPin = 8;
const byte pinX = A3;
const byte pinY = A5;

bool changedMenuItem = false;
bool up = false;
bool down = false;
bool left = false;
bool right = false;
bool buttonPressed = false;

int xValue = 0;
int yValue = 0;
bool joyMoved = false;
int minThreshold = 400;
int maxThreshold = 600;

byte buttonState = LOW;
byte lastReading = LOW;
byte reading = LOW;
unsigned long lastDebounceTime = 0;
const unsigned long shortDebounceDelay = 20;
bool shortPress = false;


// ------------------------------------------------ buzzer variables
const int buzzerPin = A0;
ezBuzzer buzzer(buzzerPin);

int yepBeep[] = { NOTE_B5 };
int nopeBeep[] = { NOTE_E5 };
int beepDuration[] = { 8 };


// ------------------------------------------------ ldc and menu variables
const byte rs = 9;
const byte en = 2;
const byte d4 = 7;
const byte d5 = 6;
const byte d6 = 13;
const byte d7 = 4;
const byte lcdBrightnessPin = 5;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

byte currentItem = 0;
byte minCurrentItem = 0;
byte maxCurrentItem = 4;

char currentName[4] = {'O', 'M', 'A', 'R'};
byte selectNamePos = 0;

byte highscoreLevel = 0;
byte highscorePosition = 1;
int topDim = 5;
int infoDim = 6;

byte currentLevel = 0;
bool selectLevel = false;

byte lcdBrightness = 128;
byte lcdBrightnessAddress = 0;
bool soundOn = false;
byte soundAddress = 2;

bool resetInfoStartTime = true;
unsigned long infoStartTime = 0;
int startLetter = 0;


// ------------------------------------------------ game states:
byte gameState = 0;
const byte mainMenuGS = 0;
const byte runGS = 1;
const byte highscoreGS = 2;
const byte settingsGS = 3;
const byte creditsGS = 4;
const byte howToPlayGS = 5;
const byte enterNameGS = 6;
const byte selectLevelGS = 7;
const byte lcdBrightnessGS = 9;
const byte matrixBrightnessGS = 10;
const byte selectSoundGS = 11;
const byte winEndGameGS = 12;
const byte nextLevelGS = 13;
const byte initGameMapGS = 14;
const byte explosionEndGameGS = 15;
const byte easterEggGS = 16;
const byte resetHighscoreGS = 17;
const byte welcomeGS = 18;

char mainMenuItems[5][12] = {
  "Start game",
  "Highscore",
  "Settings",
  "Credits",
  "How to play"
};

char settingsMenuItems[7][14] = {
  "Enter name",
  "Level    0",
  "LCD bright",
  "Matrix bright",
  "Sound     ",
  "Reset highsc",
  "Back"
};


// ------------------------------------------------ messages
char *creditsMessage = "                Incredible Maze was made by: Tudor Cosmin Oanea, github.com/TudorCosmin                ";
char *howToPlayMessage = "                You must go from top-left to bottom-right without touching any bombs. Can you do it?!            ";
unsigned long welcomeMoment = 0;
unsigned long welcomeMsgTime = 4000;


// ------------------------------------------------ matrix variables
const byte dinPin = 12;
const byte clockPin = 11;
const byte loadPin = 10;

LedControl matrix = LedControl(dinPin, clockPin, loadPin, 1);
byte matrixBrightness = 10;
byte matrixBrightnessAddress = 1;

const uint64_t images[] = {
  0x040c1c3c3c1c0c04,
  0xdbdbdb1b18180000,
  0x03070e7c88880830,
  0x3c4299858599423c,
  0x0800080810202418,
  0xffffffffffffffff,
  0x004242425a664200
};


// ------------------------------------------------ gameplay:
// general gameplay variables
unsigned long startGameTime = 0;
unsigned long elapsedTime = 0;
bool win = false;
bool explosion = false;

// position of top-left corner of shown map
byte mapX = 0;
byte mapY = 0;
byte mapBorder = 3;

// position of the player
int playerX = 1;
int playerY = 1;

// current map
byte mapSize = 32;
const byte maxLevel = 6;
uint32_t gameMap[21];
int weight[7] = { 50, 40, 30, 30, 20, 20, 10 };

// current set of bombs
const byte bombLedPin = A1;
byte bombCount = 1;
bool nearBomb = false;
byte bombX[33];
byte bombY[33];

// coord of bomb-affected area
byte directions = 8;
int dX[] = {1, 0, -1, 0, 1, -1, 1, -1};
int dY[] = {0, 1, 0, -1, 1, -1, -1, 1};

// easter egg variables
bool easterEggActivated = false;
bool easterEggDiscovered = false;
byte easterEggX = 1;
byte easterEggY = 10;
unsigned long easterEggMinusTime = 10000;
unsigned long easterEggMoment = 0;
unsigned long easterEggMsgTime = 3000;

unsigned long explosionMoment = 0;
unsigned long explosionMsgTime = 5000;


// ------------------------------------------------ sound effects
// https://github.com/robsoncouto/arduino-songs

int welcomeMelody[] = { 0, NOTE_G5, NOTE_A5, NOTE_AS5, NOTE_A5, NOTE_F5, NOTE_A5, NOTE_G5};
int welcomeNoteDurations[] = { 4, 4, 4, 4, 4, 4, 4, 4};

int explosionMelody[] = { NOTE_FS4, 0, NOTE_A4, NOTE_CS5, 0, NOTE_A4, 0, NOTE_FS4, NOTE_D4, NOTE_D4, NOTE_D4, 0, 0, 0 };
int explosionNoteDurations[] = { 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 3, 6 };

int easterEggMelody[] = { NOTE_E5, NOTE_E5, 0, NOTE_E5, 0, NOTE_C5, NOTE_E5, NOTE_G5, 0, NOTE_G4, 0};
int easterEggNoteDurations[] = { 9, 9, 9, 9, 9, 9, 9, 4, 4, 9, 4 };


// ------------------------------------------------ custom characters
byte arrowUpChar[8] = {
	0b00000,
	0b00000,
	0b00100,
	0b01110,
	0b11111,
	0b00000,
	0b00000,
	0b00000
};
byte arrowUpCode = 0;

byte arrowDownChar[8] = {
	0b00000,
	0b00000,
	0b00000,
	0b11111,
	0b01110,
	0b00100,
	0b00000,
	0b00000
};
byte arrowDownCode = 1;

byte arrowLeftChar[8] = {
	0b00000,
	0b00000,
	0b00011,
	0b01111,
	0b01111,
	0b00011,
	0b00000,
	0b00000
};
byte arrowLeftCode = 2;

byte arrowRightChar[8] = {
	0b00000,
	0b00000,
	0b11000,
	0b11110,
	0b11110,
	0b11000,
	0b00000,
	0b00000
};
byte arrowRightCode = 3;

byte slidingBarChar[8] = {
	0b00000,
	0b11111,
	0b00000,
	0b11111,
	0b00000,
	0b11111,
	0b00000,
	0b00000
};
byte slidingBarCode = 4;

#endif