This repo is just meant to be a collection of my favorite Arduino projects that I've completed and will hopefully grow larger over time. If you want to try these projects for yourself, make sure to connect all the components to the correct PINs and use the correct resistors/capacitors etc. as shown in the schematics of every project.

# Arduino-Buzzer-Song-Player
This is a small Arduino project which uses a buzzer module to play any simple musical melody.
The **notes, pauses and tempo** of the song **must be manually defined** in the script. Per default it plays the Nintendo Mii Theme and Never Gonna Give You Up by Rick Astley. The sheet music used can be found here: 

https://musescore.com/user/16403456/scores/4984153

https://musescore.com/chlorondria_5/never-gonna-give-you-up_alto-sax

https://user-images.githubusercontent.com/63166690/166967573-4b58b5ab-6aa4-4238-9f22-d8d7c55acc64.mov

The circuit used is a very simple buzzer circuit which looks like this:

(Make sure you use PIN 5 for the buzzer or change the buzzer integer in script to a different PIN.)
<img src="https://user-images.githubusercontent.com/63166690/166476836-02270979-d89d-446f-9485-253145414c78.png" width="400" height="300">


# LED Matrix Connect 4 Game
This project recreates the classic game Connect 4 using a **8x8 LED Matrix**. It is intended as a two-player game were you take turns using the same button controls. The left and right buttons allow the player to move their dot from left to right and the button in the center is used to confirm the position and send the dot downwards. 

This is probably one the most complex Arduino projects I've done since this was also pretty much my first time using an LED Matrix.

<img src="https://user-images.githubusercontent.com/63166690/166999177-61801394-735d-483e-941e-e405ddc9b6c1.png" width="400" height="350">
<img src="https://user-images.githubusercontent.com/63166690/166990364-e390ed3c-c8b6-4d08-81c3-12b2accb6529.png" width="400" height="350">

# LED Reaction-Game
This project is a two-player **reaction time game** in which a red LED randomly lights up, after which the two players try to press their respective button as quickly as possible. The person who presses their button first wins the round. The result is then announced by one of the two green LEDs. The first player to win **5 rounds** is the overall winner and the game can be restarted, resetting the scoreboard. A premature button press disqualifies the player for that round and awards the point to the other player. Everytime the players want to start the next game/round both buttons must be pressed at the same time. To track the players score every round, you can open the **Serial Monitor** in the Arduino IDE.

This was one of my first projects and although it's pretty simple, I really like it because it challenged my knowledge at the time and gave me that eurika moment when I finished it.

<img src="https://user-images.githubusercontent.com/63166690/167148301-59498fd7-1388-4c18-aa5b-d5d005996586.png" width="400" height="350">
<img src="https://user-images.githubusercontent.com/63166690/167153770-f395dd22-13bf-4a68-9f70-3db08b1339f1.png" width="400" height="350">
