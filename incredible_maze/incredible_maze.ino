#include "variables.h"
#include "functions.h"
#include "init_game_maps.h"
#include "joystick_move.h"

#include "settings_menu.h"
#include "main_menu.h"

#include "core.h"
#include "game.h"

unsigned long timp = 0;

void setup() {
  initialization();
}

void loop() {
  buzzer.loop();
  inputData();
  changeState();
}