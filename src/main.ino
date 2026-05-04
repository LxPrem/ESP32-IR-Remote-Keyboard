#include <IRremote.hpp>
#include <BleKeyboard.h>

BleKeyboard bleKeyboard("IR Remote PC", "ESP32", 100);

#define IR_RECEIVE_PIN 15

void setup() {
  Serial.begin(115200);
  IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK);
  bleKeyboard.begin();
}

void loop() {
  if (IrReceiver.decode()) {

    unsigned long code = IrReceiver.decodedIRData.decodedRawData;
    Serial.println(code, HEX);

    if (bleKeyboard.isConnected()) {

      switch(code) {

        case 0xED127F80: // Power → Shutdown
          bleKeyboard.press(KEY_LEFT_GUI);
          bleKeyboard.press('x');
          bleKeyboard.releaseAll();
          delay(500);
          bleKeyboard.write('u');
          break;

        case 0xF50A7F80: // Open Chrome
          bleKeyboard.press(KEY_LEFT_GUI);
          bleKeyboard.press('r');
          bleKeyboard.releaseAll();
          delay(500);
          bleKeyboard.print("chrome");
          bleKeyboard.write(KEY_RETURN);
          break;

        case 0xE41B7F80: // YouTube
          bleKeyboard.press(KEY_LEFT_GUI);
          bleKeyboard.press('r');
          bleKeyboard.releaseAll();
          delay(500);
          bleKeyboard.print("https://youtube.com");
          bleKeyboard.write(KEY_RETURN);
          break;

        case 0xE01F7F80:
        case 0xFE017F80:
          bleKeyboard.write(' '); // Play/Pause
          break;

        case 0xF30C7F80:
          bleKeyboard.write(KEY_MEDIA_PREVIOUS_TRACK);
          break;

        case 0xF20D7F80:
          bleKeyboard.write(KEY_MEDIA_NEXT_TRACK);
          break;

        case 0xF10E7F80:
        case 0xE11E7F80:
          bleKeyboard.write(KEY_MEDIA_MUTE);
          break;

        case 0xFF007F80:
          bleKeyboard.press(KEY_LEFT_GUI);
          bleKeyboard.press(KEY_DOWN_ARROW);
          bleKeyboard.releaseAll();
          break;

        case 0xF00F7F80:
          bleKeyboard.press(KEY_LEFT_GUI);
          bleKeyboard.press(KEY_UP_ARROW);
          bleKeyboard.releaseAll();
          break;

        case 0xE6197F80:
          bleKeyboard.press(KEY_LEFT_CTRL);
          bleKeyboard.press('w');
          bleKeyboard.releaseAll();
          break;

        case 0xF8077F80:
          bleKeyboard.press(KEY_LEFT_ALT);
          bleKeyboard.press(KEY_F4);
          bleKeyboard.releaseAll();
          break;

        case 0xF9067F80:
          bleKeyboard.write(KEY_MEDIA_VOLUME_UP);
          break;

        case 0xFA057F80:
          bleKeyboard.write(KEY_MEDIA_VOLUME_DOWN);
          break;

        case 0xE51A7F80:
          bleKeyboard.press(KEY_LEFT_CTRL);
          bleKeyboard.press(KEY_LEFT_SHIFT);
          bleKeyboard.press(KEY_ESC);
          bleKeyboard.releaseAll();
          break;

        case 0xFD027F80:
          bleKeyboard.write(KEY_LEFT_ARROW);
          break;

        case 0xFC037F80:
          bleKeyboard.write(KEY_RIGHT_ARROW);
          break;
      }
    }

    IrReceiver.resume();
  }
}
