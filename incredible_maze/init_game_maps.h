#ifndef INIT_GAME_MAPS_H
#define INIT_GAME_MAPS_H

void initGameMap() {
  mapX = 0;
  mapY = 0;
  playerX = 1;
  playerY = 1;
  startGameTime = millis();
  easterEggActivated = false;
  easterEggDiscovered = false;

  if(currentLevel == 0) {
    mapSize = 19;
    gameMap[0] = 0b11111111111111111111;
    gameMap[1] = 0b10000000000000000001;
    gameMap[2] = 0b10001111111111111101;
    gameMap[3] = 0b10000111111111111101;
    gameMap[4] = 0b10100011111111111101;
    gameMap[5] = 0b10110001111111111101;
    gameMap[6] = 0b10111000111111111101;
    gameMap[7] = 0b10111100011111111101;
    gameMap[8] = 0b10111110001111111101;
    gameMap[9] = 0b10111111000111111101;
    gameMap[10] = 0b10111011100011111101;
    gameMap[11] = 0b10110001110001111101;
    gameMap[12] = 0b10100000000000111101;
    gameMap[13] = 0b10110001111100011101;
    gameMap[14] = 0b10111011111110001101;
    gameMap[15] = 0b10111111111111000101;
    gameMap[16] = 0b10111111111111100001;
    gameMap[17] = 0b10111111111111110001;
    gameMap[18] = 0b10000000000000000000;
    gameMap[19] = 0b11111111111111111100;

    bombCount = 1;
    nearBomb = false;
    directions = 8;
    bombX[0] = 12; bombY[0] = 5;
  }

  else if(currentLevel == 1) {
    easterEggMinusTime = 10;

    mapSize = 11;
    easterEggX = 1;
    easterEggY = 10;
    gameMap[0] = 0b111111111111;
    gameMap[1] = 0b100000000001;
    gameMap[2] = 0b111100110111;
    gameMap[3] = 0b100000000001;
    gameMap[4] = 0b110111100101;
    gameMap[5] = 0b110000000101;
    gameMap[6] = 0b110101110111;
    gameMap[7] = 0b100000000001;
    gameMap[8] = 0b101111111011;
    gameMap[9] = 0b101101111001;
    gameMap[10] = 0b110000000000;
    gameMap[11] = 0b111111111100;

    bombCount = 5;
    nearBomb = false;
    directions = 8;
    bombX[0] = 1; bombY[0] = 10;
    bombX[1] = 5; bombY[1] = 4;
    bombX[2] = 5; bombY[2] = 10;
    bombX[3] = 7; bombY[3] = 1;
    bombX[4] = 9; bombY[4] = 4;
  }

  else if(currentLevel == 2) {
    easterEggMinusTime = 10;

    mapSize = 11;
    easterEggX = 1;
    easterEggY = 10;
    gameMap[0] = 0b111111111111;
    gameMap[1] = 0b101110001001;
    gameMap[2] = 0b101110100011;
    gameMap[3] = 0b101000111001;
    gameMap[4] = 0b101010010001;
    gameMap[5] = 0b100010000111;
    gameMap[6] = 0b111000000001;
    gameMap[7] = 0b101110000111;
    gameMap[8] = 0b100000000101;
    gameMap[9] = 0b101111111101;
    gameMap[10] = 0b100000000000;
    gameMap[11] = 0b111111111100;

    bombCount = 5;
    nearBomb = false;
    directions = 8;
    bombX[0] = 1; bombY[0] = 10;
    bombX[0] = 5; bombY[0] = 5;
    bombX[1] = 5; bombY[1] = 6;
    bombX[2] = 6; bombY[2] = 5;
    bombX[3] = 6; bombY[3] = 6;
  }

  else if(currentLevel == 3) {
    easterEggMinusTime = 15;

    mapSize = 15;
    easterEggX = 1;
    easterEggY = 14;
    gameMap[0] = 0b1111111111111111;
    gameMap[1] = 0b1000000000000001;
    gameMap[2] = 0b1111111001111101;
    gameMap[3] = 0b1000000000000001;
    gameMap[4] = 0b1011111000001111;
    gameMap[5] = 0b1000000000000001;
    gameMap[6] = 0b1101011111111001;
    gameMap[7] = 0b1000000000000001;
    gameMap[8] = 0b1011111011100001;
    gameMap[9] = 0b1000000000000001;
    gameMap[10] = 0b1111011111111101;
    gameMap[11] = 0b1000000000000001;
    gameMap[12] = 0b1011111000111111;
    gameMap[13] = 0b1011000011100001;
    gameMap[14] = 0b1000011000001100;
    gameMap[15] = 0b1111111111111100;

    bombCount = 7;
    nearBomb = false;
    directions = 8;
    bombX[0] = 1; bombY[0] = 14;
    bombX[1] = 3; bombY[1] = 10;
    bombX[2] = 7; bombY[2] = 1;
    bombX[3] = 8; bombY[3] = 14;
    bombX[4] = 9; bombY[4] = 1;
    bombX[5] = 11; bombY[5] = 1;
    bombX[6] = 13; bombY[6] = 4;
  }

  else if(currentLevel == 4) {
    easterEggMinusTime = 15;

    mapSize = 15;
    easterEggX = 1;
    easterEggY = 14;
    gameMap[0] = 0b1111111111111111;
    gameMap[1] = 0b1000001000000001;
    gameMap[2] = 0b1011001010000001;
    gameMap[3] = 0b1010101011001001;
    gameMap[4] = 0b1010101010001001;
    gameMap[5] = 0b1000000000111001;
    gameMap[6] = 0b1011111111100001;
    gameMap[7] = 0b1010100010001101;
    gameMap[8] = 0b1000001010000001;
    gameMap[9] = 0b1111111010101011;
    gameMap[10] = 0b1000000010111111;
    gameMap[11] = 0b1000000010000011;
    gameMap[12] = 0b1000000010100011;
    gameMap[13] = 0b1000000010100001;
    gameMap[14] = 0b1000000000111000;
    gameMap[15] = 0b1111111111111100;

    bombCount = 10;
    nearBomb = false;
    directions = 8;
    bombX[0] = 1; bombY[0] = 5;
    bombX[1] = 1; bombY[1] = 14;
    bombX[2] = 2; bombY[2] = 9;
    bombX[3] = 3; bombY[3] = 3;
    bombX[4] = 7; bombY[4] = 3;
    bombX[5] = 9; bombY[5] = 11;
    bombX[6] = 9; bombY[6] = 13;
    bombX[7] = 12; bombY[7] = 3;
    bombX[8] = 12; bombY[8] = 7;
    bombX[9] = 12; bombY[9] = 12;
  }

  else if(currentLevel == 5) {
    easterEggMinusTime = 20;

    mapSize = 19;
    easterEggX = 1;
    easterEggY = 18;
    gameMap[0] = 0b11111111111111111111;
    gameMap[1] = 0b10000000000001000001;
    gameMap[2] = 0b10111110011001010001;
    gameMap[3] = 0b10100000110000011001;
    gameMap[4] = 0b10100011100011111011;
    gameMap[5] = 0b10111000110000000011;
    gameMap[6] = 0b10010000011101111001;
    gameMap[7] = 0b10110000000001001101;
    gameMap[8] = 0b10100010111111001001;
    gameMap[9] = 0b10110010001100000001;
    gameMap[10] = 0b10010110100110111111;
    gameMap[11] = 0b10110010110010000001;
    gameMap[12] = 0b10100010100010100011;
    gameMap[13] = 0b10110010001010110001;
    gameMap[14] = 0b10011010101110100001;
    gameMap[15] = 0b10110000100000100001;
    gameMap[16] = 0b10111111111111100001;
    gameMap[17] = 0b10011011101000111101;
    gameMap[18] = 0b10000000000000000000;
    gameMap[19] = 0b11111111111111111100;

    bombCount = 25;
    nearBomb = false;
    directions = 8;
    bombX[0] = 1; bombY[0] = 9;
    bombX[1] = 1; bombY[1] = 12;
    bombX[2] = 1; bombY[2] = 18;
    bombX[3] = 3; bombY[3] = 3;
    bombX[4] = 4; bombY[4] = 3;
    bombX[5] = 4; bombY[5] = 9;
    bombX[6] = 5; bombY[6] = 7;
    bombX[7] = 5; bombY[7] = 15;
    bombX[8] = 6; bombY[8] = 2;
    bombX[9] = 7; bombY[9] = 15;
    bombX[10] = 8; bombY[10] = 3;
    bombX[11] = 9; bombY[11] = 12;
    bombX[12] = 10; bombY[12] = 2;
    bombX[13] = 11; bombY[13] = 17;
    bombX[14] = 12; bombY[14] = 3;
    bombX[15] = 13; bombY[15] = 13;
    bombX[16] = 13; bombY[16] = 18;
    bombX[17] = 14; bombY[17] = 2;
    bombX[18] = 15; bombY[18] = 6;
    bombX[19] = 16; bombY[19] = 15;
    bombX[20] = 17; bombY[20] = 2;
    bombX[21] = 17; bombY[21] = 5;
    bombX[22] = 17; bombY[22] = 9;
    bombX[23] = 17; bombY[23] = 12;
    bombX[24] = 18; bombY[24] = 12;
  }

  else if(currentLevel == 6) {
    easterEggMinusTime = 20;

    mapSize = 19;
    easterEggX = 1;
    easterEggY = 18;
    gameMap[0] = 0b11111111111111111111;
    gameMap[1] = 0b10000001000000000001;
    gameMap[2] = 0b10000101001101100001;
    gameMap[3] = 0b11110000000100101001;
    gameMap[4] = 0b10000011100010100101;
    gameMap[5] = 0b10010010001000000101;
    gameMap[6] = 0b10010000101000000101;
    gameMap[7] = 0b10010001001100001001;
    gameMap[8] = 0b10001000001000001001;
    gameMap[9] = 0b10100001001000101001;
    gameMap[10] = 0b10000101001010101001;
    gameMap[11] = 0b10100101001000100001;
    gameMap[12] = 0b10000101001010110001;
    gameMap[13] = 0b10100100010000100001;
    gameMap[14] = 0b10000100000000100001;
    gameMap[15] = 0b10100101101111000111;
    gameMap[16] = 0b10000100000000000001;
    gameMap[17] = 0b10101001111111111001;
    gameMap[18] = 0b10000000000000000000;
    gameMap[19] = 0b11111111111111111100;

    bombCount = 32;
    nearBomb = false;
    directions = 4;
    bombX[0] = 1; bombY[0] = 3;
    bombX[1] = 1; bombY[1] = 18;
    bombX[2] = 2; bombY[2] = 9;
    bombX[3] = 2; bombY[3] = 12;
    bombX[4] = 2; bombY[4] = 15;
    bombX[5] = 3; bombY[5] = 4;
    bombX[6] = 3; bombY[6] = 7;
    bombX[7] = 3; bombY[7] = 17;
    bombX[8] = 5; bombY[8] = 1;
    bombX[9] = 5; bombY[9] = 8;
    bombX[10] = 5; bombY[10] = 12;
    bombX[11] = 5; bombY[11] = 15;
    bombX[12] = 6; bombY[12] = 4;
    bombX[13] = 8; bombY[13] = 7;
    bombX[14] = 8; bombY[14] = 11;
    bombX[15] = 8; bombY[15] = 14;
    bombX[16] = 8; bombY[16] = 17;
    bombX[17] = 9; bombY[17] = 1;
    bombX[18] = 9; bombY[18] = 5;
    bombX[19] = 10; bombY[19] = 8;
    bombX[20] = 11; bombY[20] = 3;
    bombX[21] = 11; bombY[21] = 16;
    bombX[22] = 13; bombY[22] = 8;
    bombX[23] = 13; bombY[23] = 11;
    bombX[24] = 14; bombY[24] = 3;
    bombX[25] = 14; bombY[25] = 13;
    bombX[26] = 14; bombY[26] = 15;
    bombX[27] = 14; bombY[27] = 18;
    bombX[28] = 15; bombY[28] = 1;
    bombX[29] = 16; bombY[29] = 14;
    bombX[30] = 18; bombY[30] = 3;
    bombX[31] = 18; bombY[31] = 17;
  }

  gameState = runGS;
}

#endif