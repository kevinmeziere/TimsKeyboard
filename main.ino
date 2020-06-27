#include <Bounce.h>


#define OUT_KEYS 6
#define IN_KEY_1 1
#define IN_KEY_2 2
#define IN_KEY_3 3
#define IN_KEY_4 4
#define IN_KEY_5 5
#define IN_KEY_6 6


Bounce key1 = Bounce(IN_KEY_1, 5);  // 5 ms debounce
Bounce key2 = Bounce(IN_KEY_2, 5);  // 5 ms debounce
Bounce key3 = Bounce(IN_KEY_3, 5);  // 5 ms debounce
Bounce key4 = Bounce(IN_KEY_4, 5);  // 5 ms debounce
Bounce key5 = Bounce(IN_KEY_5, 5);  // 5 ms debounce


void setup() {
  Serial.begin(9600);
  delay(1000);
  pinMode(OUT_KEYS, OUTPUT);
  pinMode(IN_KEY_1, INPUT_PULLUP);
  pinMode(IN_KEY_2, INPUT_PULLUP);
  pinMode(IN_KEY_3, INPUT_PULLUP);
  pinMode(IN_KEY_4, INPUT_PULLUP);
  pinMode(IN_KEY_5, INPUT_PULLUP);
}

void loop() {
  key1.update();
  key2.update();
  key3.update();
  key4.update();
  key5.update();

  if (key1.fallingEdge()) {
    Keyboard.press(KEY_MEDIA_MUTE);
    Keyboard.release(KEY_MEDIA_MUTE);
  }
  if (key2.fallingEdge()) {
    Keyboard.press(KEY_MEDIA_VOLUME_DEC);
    Keyboard.release(KEY_MEDIA_VOLUME_DEC);
  }
  if (key3.fallingEdge()) {
    Keyboard.press(KEY_MEDIA_VOLUME_INC);
    Keyboard.release(KEY_MEDIA_VOLUME_INC);
  }
  if (key4.fallingEdge()) {
    Keyboard.println("Layer 1");
  }
  if (key5.fallingEdge()) {
    Keyboard.println("Layer 2");
  }
  
}

