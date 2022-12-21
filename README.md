# Incredible-maze
Project for introduction to robotics optional course


## Game description
In this panning-camera maze game, players must navigate from the top-left corner to the bottom-right corner of the LED matrix display as quickly as possible using a joystick. The game is played by moving the joystick in different directions to move through the maze. The maze consists of a series of puzzles, obstacles and challenges that the player must overcome.

However, there is a catch: the maze is filled with invisible bombs that will explode if the player comes too close! To help navigate the maze, a LED will turn on if the player is in a bomb-afected area, alerting them to the danger. The player must avoid touching the walls of the maze and the invisible bombs at all costs, as a single mistake will result in the game being over.

The game is won by successfully navigating through the entire maze and reaching the bottom-right corner without touching any walls or bombs. The LED matrix display provides a unique and visually stunning way to experience the maze, as the camera pans and shifts to follow the cursor's movements through the twists and turns of the game. With its fast-paced gameplay and challenging obstacles, this panning-camera maze game is sure to keep players on the edge of their seats.

## Photo of setup:

![asd](/Images/setup.jpg)

## Components:<br>
- 1 Arduino UNO board
- 1 breadboard medium
- 1 breadboard small
- 1 LCD display
- 1 8x8 LED matrix
- 1 MAX7219 driver
- 1 joystick
- 1 buzzer
- 1 potentiometer
- resistors and wires (per logic)

## [Demo Video](https://www.youtube.com/watch?v=MXymNoPZde8)<br>

## Game backstory
I had the idea to create a maze game that used the panning camera feature to give players a more immersive experience. Futhermore, I was particularly interested in the idea of using invisible bombs as a way to add an element of surprise and challenge to the game. I felt that this would give players a sense of tension and excitement as they navigated the maze, wondering when the next bomb might appear and how to avoid it.

I decided to create this game because I wanted to offer players a unique and exciting gaming experience that they couldn't find anywhere else. I knew that the combination of the simplicity of Arduino control and LED matrix display and the complexity of the puzles would allow you to create a game that was visually stunning and highly immersive, and you were excited to see how players would react to the challenge of navigating the maze and avoiding the invisible bombs.

## Game instructions
As the player begins the game, they will find themselves spawning in the top-left corner of the map. Their objective is to navigate through the walls of the maze, carefully avoiding any hidden bombs, until they reach the bottom-right corner. As the game progresses, the levels will become increasingly difficult, requiring the player to exercise great caution in order to succeed. The final level will be the ultimate test of their skills, as they must navigate through the maze with the utmost care in order to emerge victorious.

### Level 0
Level 0 serves as a tutorial for players to familiarize themselves with the game. The routes in this level are straightforward and easy to follow, with a single bomb placed as a demonstration for players to understand how to avoid them. This level is designed to help players become comfortable with the gameplay mechanics before moving on to the more challenging levels that follow.

**Bomb logic:** bomb areas are represented by a 3x3 square on the map, with the bomb located at the center. If the player comes into contact with any of the 8 cells adjacent to the bomb, the LED will turn on to alert the player of the danger. 

![asd](/Images/bomb-area-1.jpg)

### Levels 1-5
This levels are designed to provide a enjoyable and challenging gameplay experience. Each level contains a series of puzzles that will require players to think critically and concentrate in order to solve them. These levels are designed to be fun and engaging, providing a satisfying challenge for players as they progress through the game.

**Bomb logic:** same as level 0

### Level 6 - FINAL ROOM
The final level of the game is the most difficult by far. The bombs have been placed strategically in such a way that they can only be detected through careful logical reasoning. Some paths may appear safe, but are actually traps, while others may lead to victory. Can you outwit the game and emerge victorious, or will the bombs be your downfall? This level will test your skills and determination to the limit.

**Bomb logic:** the bomb area has been reduced and has now only 4 adjacent cells activating the LED to alert the player of the danger. This change adds an extra layer of challenge to the game, as players must be more precise in their movements in order to avoid the bombs and successfully navigate the maze.

![asd](/Images/bomb-area-2.jpg)
