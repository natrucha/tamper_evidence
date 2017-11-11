//#include <EEPROM.h>

// set the pins for all the components as constants (might need to switch to const int)
#define SEG_PIN_A 2
#define SEG_PIN_B 3
#define SEG_PIN_C 4
#define SEG_PIN_D 5
#define SEG_PIN_E 6
#define SEG_PIN_F 7
#define SEG_PIN_G 8
// reed switch variables
#define REED_PIN 9
// button variables
#define SWITCH_PIN 10
// photoresistor variables
#define PHOTO_PIN A0
int photo_value; // store value from photoresistor (0-1023)

int counter; // sets up the counter that figures out when the box has been tampered with

// initial code for EEPROM
/** the current address in the EEPROM (i.e. which byte we're going to write to next) **/
//int addr = 0;

void setup() {
  // setup for all the 7 segment display LEDs pins
  pinMode(SEG_PIN_A, OUTPUT);
  pinMode(SEG_PIN_B, OUTPUT);
  pinMode(SEG_PIN_C, OUTPUT);
  pinMode(SEG_PIN_D, OUTPUT);
  pinMode(SEG_PIN_E, OUTPUT);
  pinMode(SEG_PIN_F, OUTPUT);
  pinMode(SEG_PIN_G, OUTPUT);
  // setup for the inputs
  pinMode(REED_SWITCH, INPUT);
  pinMode(SWITCH, INPUT);
  pinMode(PHOTO_PIN, INPUT);
}

void loop() {
  photo_value = analogRead(PHOTO_PIN); // read the values of the photoresistor

  if (photo_value > 25 || digitalRead(REED_SWITCH) == HIGH) {
    // if either the photoresistor or the reed switch are triggered
    counter++; // counter value goes up one
    delay(1000); // I'm worried the counter will go crazy if the box if left open
    // might need to rethink exactly how to deal with this...

    if (counter > 9) {
      counter = 0;
      // the 7-segmnet display only goes up to 9, after that it will reset
      // can add an LED to show the attempts go above 9
    }
  }

  if (digitalRead(SWITCH_PIN) == HIGH) {
    seg_display(counter);
  }

}

void seg_display(int counter_number) {
  // lights up correct LED for the 7-segment counter depending on the counter value
  if (counter_number == 0) {
    digitalWrite(SEG_PIN_A, HIGH);
    digitalWrite(SEG_PIN_B, HIGH);
    digitalWrite(SEG_PIN_C, HIGH);
    digitalWrite(SEG_PIN_D, HIGH);
    digitalWrite(SEG_PIN_E, HIGH);
    digitalWrite(SEG_PIN_F, HIGH);
    digitalWrite(SEG_PIN_G, LOW);

    delay(1000); // show the display
    break; // break out of loop so that it cannot be used to tamper with box

  } else if (counter_number == 1) {
    digitalWrite(SEG_PIN_A, LOW);
    digitalWrite(SEG_PIN_B, HIGH);
    digitalWrite(SEG_PIN_C, HIGH);
    digitalWrite(SEG_PIN_D, LOW);
    digitalWrite(SEG_PIN_E, LOW);
    digitalWrite(SEG_PIN_F, LOW);
    digitalWrite(SEG_PIN_G, LOW);

    delay(1000); // show the display
    break; // break out of loop so that it cannot be used to tamper with box

  } else if (counter_number == 2) {
    digitalWrite(SEG_PIN_A, HIGH);
    digitalWrite(SEG_PIN_B, HIGH);
    digitalWrite(SEG_PIN_C, LOW);
    digitalWrite(SEG_PIN_D, HIGH);
    digitalWrite(SEG_PIN_E, HIGH);
    digitalWrite(SEG_PIN_F, LOW);
    digitalWrite(SEG_PIN_G, HIGH);

    delay(1000); // show the display
    break; // break out of loop so that it cannot be used to tamper with box

  } else if (counter_number == 3) {
    digitalWrite(SEG_PIN_A, HIGH);
    digitalWrite(SEG_PIN_B, HIGH);
    digitalWrite(SEG_PIN_C, HIGH);
    digitalWrite(SEG_PIN_D, HIGH);
    digitalWrite(SEG_PIN_E, LOW);
    digitalWrite(SEG_PIN_F, LOW);
    digitalWrite(SEG_PIN_G, HIGH);

    delay(1000); // show the display
    break; // break out of loop so that it cannot be used to tamper with box

  } else if (counter_number == 4) {
    digitalWrite(SEG_PIN_A, LOW);
    digitalWrite(SEG_PIN_B, HIGH);
    digitalWrite(SEG_PIN_C, HIGH);
    digitalWrite(SEG_PIN_D, LOW);
    digitalWrite(SEG_PIN_E, LOW);
    digitalWrite(SEG_PIN_F, HIGH);
    digitalWrite(SEG_PIN_G, HIGH);

    delay(1000); // show the display
    break; // break out of loop so that it cannot be used to tamper with box

  } else if (counter_number == 5) {
    digitalWrite(SEG_PIN_A, HIGH);
    digitalWrite(SEG_PIN_B, LOW);
    digitalWrite(SEG_PIN_C, HIGH);
    digitalWrite(SEG_PIN_D, HIGH);
    digitalWrite(SEG_PIN_E, LOW);
    digitalWrite(SEG_PIN_F, HIGH);
    digitalWrite(SEG_PIN_G, HIGH);

    delay(1000); // show the display
    break; // break out of loop so that it cannot be used to tamper with box

  } else if (counter_number == 6) {
    digitalWrite(SEG_PIN_A, HIGH);
    digitalWrite(SEG_PIN_B, LOW);
    digitalWrite(SEG_PIN_C, HIGH);
    digitalWrite(SEG_PIN_D, HIGH);
    digitalWrite(SEG_PIN_E, HIGH);
    digitalWrite(SEG_PIN_F, HIGH);
    digitalWrite(SEG_PIN_G, HIGH);

    delay(1000); // show the display
    break; // break out of loop so that it cannot be used to tamper with box

  } else if (counter_number == 7) {
    digitalWrite(SEG_PIN_A, HIGH);
    digitalWrite(SEG_PIN_B, HIGH);
    digitalWrite(SEG_PIN_C, HIGH);
    digitalWrite(SEG_PIN_D, LOW);
    digitalWrite(SEG_PIN_E, LOW);
    digitalWrite(SEG_PIN_F, LOW);
    digitalWrite(SEG_PIN_G, LOW);

    delay(1000); // show the display
    break; // break out of loop so that it cannot be used to tamper with box

  } else if (counter_number == 8) {
    digitalWrite(SEG_PIN_A, HIGH);
    digitalWrite(SEG_PIN_B, HIGH);
    digitalWrite(SEG_PIN_C, HIGH);
    digitalWrite(SEG_PIN_D, HIGH);
    digitalWrite(SEG_PIN_E, HIGH);
    digitalWrite(SEG_PIN_F, HIGH);
    digitalWrite(SEG_PIN_G, HIGH);

    delay(1000); // show the display
    break; // break out of loop so that it cannot be used to tamper with box

  } else if (counter_number == 9) {
    digitalWrite(SEG_PIN_A, HIGH);
    digitalWrite(SEG_PIN_B, HIGH);
    digitalWrite(SEG_PIN_C, HIGH);
    digitalWrite(SEG_PIN_D, LOW);
    digitalWrite(SEG_PIN_E, LOW);
    digitalWrite(SEG_PIN_F, HIGH);
    digitalWrite(SEG_PIN_G, HIGH);

    delay(1000); // show the display
    break; // break out of loop so that it cannot be used to tamper with box

  }
}
