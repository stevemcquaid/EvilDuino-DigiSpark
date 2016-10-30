#include <Arduino.h>
#include <DuckyDigi.cpp>

int led = 0;  // Change to pin 1 for MODEL A
int flag = 0;

void runScript(); //declare function

void setup(){
  setupDucky();
}

void loop() {
  if (flag == 0) {
    ledOff();
    ledOn();
    runScript();
    ledOff();

    flag = 1; // Dont want to run again
  }
}

void runScript(){
  // Just need to know KEY_A - KEYZ, KEY_0 - KEY_9, KEY_F1 - KEY_F12
  PRESS(SPACE, CMD);
  PRINT("finder.app");
  DELAY(1000);
  PRESS(ENTER);
  PRESS(KEY_D, CMD + SHIFT);

  PRESS(SPACE, CMD);
  PRINT("terminal.app");
  DELAY(1000);
  PRESS(ENTER);
  DELAY(1000);
  PRINTLN("ipconfig getifaddr en0");
}
