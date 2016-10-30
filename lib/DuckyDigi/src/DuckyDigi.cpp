#include <DigiKeyboard.h>
#include <DuckyKeys.cpp>

void ledOn(){
  // turn the LED on (HIGH is the voltage level)
  digitalWrite(0, HIGH);
  digitalWrite(1, HIGH);
}

void ledOff(){
  // turn the LED off by making the voltage LOW
  digitalWrite(0, LOW);
  digitalWrite(1, LOW);
}

void wait(int ms){
  int ds = 10;
  int timer = 0;
  while (timer < ms){
    DigiKeyboard.delay(ds);
    timer += ds;
  }
}

// Pause/Wait/Delay/timing
void DELAY(int ms){
  wait(ms);
}

void setupLED(){
  // LED OUTPUT
  pinMode(0, OUTPUT); //LED on Model B
  pinMode(1, OUTPUT); //LED on Model A
}

void setupDucky(){
  DigiKeyboard.update();
  DigiKeyboard.sendKeyStroke(0); //this is generally not necessary but with some older systems it seems to prevent missing the first character after a delay
  setupLED();
}

// ## DUCKYSCRIPT Commands ##
// Strings
void STRING(String input){
  DigiKeyboard.print(input);
  DELAY(100);
}
void PRINT(String input){
  // alias to STRING
  STRING(input);
};
void PRINTLN(String input){
  DigiKeyboard.println(input);
  DELAY(100);
}
void PRESS(byte key){
  DigiKeyboard.sendKeyStroke(key);
  DELAY(100);
}
void PRESS(byte key, byte modifiers){
  DigiKeyboard.sendKeyStroke(key, modifiers);
  DELAY(100);
}
