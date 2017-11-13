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
#define REED_PIN_1 9
#define REED_PIN_2 10
// button variables
#define SWITCH_PIN 11
// photoresistor variables
#define PHOTO_PIN_1 A0
#define PHOTO_PIN_2 A1
#define PHOTO_THRESHOLD 25
#define DISPLAY_DURATION_MILLIS 2000

int prev_photo_value_1 = 0;
int photo_value_1 = 0; // store value from photoresistor (0-1023)
int prev_photo_value_2 = 0;
int photo_value_2 = 0; // store value from photoresistor (0-1023)
int prev_reed_value_1 = HIGH;
int reed_value_1 = HIGH;
int prev_reed_value_2 = HIGH;
int reed_value_2 = HIGH;
int prev_switch_value = HIGH;
int switch_value = HIGH;
int display_on_time_millis = 0;
bool display_on = false;

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
  pinMode(REED_PIN_1, INPUT_PULLUP);
  pinMode(REED_PIN_2, INPUT_PULLUP);
  pinMode(SWITCH_PIN, INPUT_PULLUP);
  //Don't need to set Photo pins, because analogRead does that automatically
}

void loop() {
  reed_value_1 = digitalRead(REED_PIN_1);
  reed_value_2 = digitalRead(REED_PIN_2);
  switch_value = digitalRead(SWITCH_PIN);

  photo_value_1 = analogRead(PHOTO_PIN_1);
  photo_value_2 = analogRead(PHOTO_PIN_2);

  // if any of the reed switches or photo resistors were just triggered
  if ((reed_value_1 == LOW && prev_reed_value_1 == HIGH) ||
      (reed_value_2 == LOW && prev_reed_value_2 == HIGH) ||
      (photo_value_1 > PHOTO_THRESHOLD && prev_photo_value_1 <= PHOTO_THRESHOLD) ||
      (photo_value_2 > PHOTO_THRESHOLD && prev_photo_value_2 <= PHOTO_THRESHOLD)) {
    delay(50); //realllllllllllly simple way to debounce;
    // if either the photoresistor or the reed switch are triggered
    counter++; // counter value goes up one

    if (counter > 9) {
      counter = 0;
      // the 7-segment display only goes up to 9, after that it will reset
      // can add an LED to show the attempts go above 9
    }
  }

  if (switch_value == LOW && prev_switch_value == HIGH) {
    display_on = true;
    seg_display(counter);
    delay(50);
    display_on_time_millis = millis();
  }

  if(display_on && millis() - display_on_time_millis > DISPLAY_DURATION_MILLIS) {
    display_on = false;
    turn_off_seg_display();
  }

  prev_reed_value_1 = reed_value_1;
  prev_reed_value_2 = reed_value_2;
  prev_photo_value_1 = photo_value_1;
  prev_photo_value_2 = photo_value_2;
  prev_switch_value = switch_value;
}

void seg_display(int counter_number) {
  int last_digit = counter_number % 10;

  switch(last_digit) {
  // lights up correct LED for the 7-segment counter depending on the counter value
  case 0 :
    digitalWrite(SEG_PIN_A, HIGH);
    digitalWrite(SEG_PIN_B, HIGH);
    digitalWrite(SEG_PIN_C, HIGH);
    digitalWrite(SEG_PIN_D, HIGH);
    digitalWrite(SEG_PIN_E, HIGH);
    digitalWrite(SEG_PIN_F, HIGH);
    digitalWrite(SEG_PIN_G, LOW);
    break; // break out of loop so that it cannot be used to tamper with box
  case 1 :
    digitalWrite(SEG_PIN_A, LOW);
    digitalWrite(SEG_PIN_B, HIGH);
    digitalWrite(SEG_PIN_C, HIGH);
    digitalWrite(SEG_PIN_D, LOW);
    digitalWrite(SEG_PIN_E, LOW);
    digitalWrite(SEG_PIN_F, LOW);
    digitalWrite(SEG_PIN_G, LOW);
    break; // break out of loop so that it cannot be used to tamper with box
  case 2 :
    digitalWrite(SEG_PIN_A, HIGH);
    digitalWrite(SEG_PIN_B, HIGH);
    digitalWrite(SEG_PIN_C, LOW);
    digitalWrite(SEG_PIN_D, HIGH);
    digitalWrite(SEG_PIN_E, HIGH);
    digitalWrite(SEG_PIN_F, LOW);
    digitalWrite(SEG_PIN_G, HIGH);
    break; // break out of loop so that it cannot be used to tamper with box
  case 3 :
    digitalWrite(SEG_PIN_A, HIGH);
    digitalWrite(SEG_PIN_B, HIGH);
    digitalWrite(SEG_PIN_C, HIGH);
    digitalWrite(SEG_PIN_D, HIGH);
    digitalWrite(SEG_PIN_E, LOW);
    digitalWrite(SEG_PIN_F, LOW);
    digitalWrite(SEG_PIN_G, HIGH);
    break; // break out of loop so that it cannot be used to tamper with box
  case 4 :
    digitalWrite(SEG_PIN_A, LOW);
    digitalWrite(SEG_PIN_B, HIGH);
    digitalWrite(SEG_PIN_C, HIGH);
    digitalWrite(SEG_PIN_D, LOW);
    digitalWrite(SEG_PIN_E, LOW);
    digitalWrite(SEG_PIN_F, HIGH);
    digitalWrite(SEG_PIN_G, HIGH);
    break; // break out of loop so that it cannot be used to tamper with box
  case 5 :
    digitalWrite(SEG_PIN_A, HIGH);
    digitalWrite(SEG_PIN_B, LOW);
    digitalWrite(SEG_PIN_C, HIGH);
    digitalWrite(SEG_PIN_D, HIGH);
    digitalWrite(SEG_PIN_E, LOW);
    digitalWrite(SEG_PIN_F, HIGH);
    digitalWrite(SEG_PIN_G, HIGH);
    break; // break out of loop so that it cannot be used to tamper with box
  case 6 :
    digitalWrite(SEG_PIN_A, HIGH);
    digitalWrite(SEG_PIN_B, LOW);
    digitalWrite(SEG_PIN_C, HIGH);
    digitalWrite(SEG_PIN_D, HIGH);
    digitalWrite(SEG_PIN_E, HIGH);
    digitalWrite(SEG_PIN_F, HIGH);
    digitalWrite(SEG_PIN_G, HIGH);
    break; // break out of loop so that it cannot be used to tamper with box
  case 7 :
    digitalWrite(SEG_PIN_A, HIGH);
    digitalWrite(SEG_PIN_B, HIGH);
    digitalWrite(SEG_PIN_C, HIGH);
    digitalWrite(SEG_PIN_D, LOW);
    digitalWrite(SEG_PIN_E, LOW);
    digitalWrite(SEG_PIN_F, LOW);
    digitalWrite(SEG_PIN_G, LOW);
    break; // break out of loop so that it cannot be used to tamper with box
  case 8 :
    digitalWrite(SEG_PIN_A, HIGH);
    digitalWrite(SEG_PIN_B, HIGH);
    digitalWrite(SEG_PIN_C, HIGH);
    digitalWrite(SEG_PIN_D, HIGH);
    digitalWrite(SEG_PIN_E, HIGH);
    digitalWrite(SEG_PIN_F, HIGH);
    digitalWrite(SEG_PIN_G, HIGH);
    break; // break out of loop so that it cannot be used to tamper with box
  case 9 :
    digitalWrite(SEG_PIN_A, HIGH);
    digitalWrite(SEG_PIN_B, HIGH);
    digitalWrite(SEG_PIN_C, HIGH);
    digitalWrite(SEG_PIN_D, LOW);
    digitalWrite(SEG_PIN_E, LOW);
    digitalWrite(SEG_PIN_F, HIGH);
    digitalWrite(SEG_PIN_G, HIGH);
    break; // break out of loop so that it cannot be used to tamper with box
  }
}

void turn_off_seg_display() {
  digitalWrite(SEG_PIN_A, LOW);
  digitalWrite(SEG_PIN_B, LOW);
  digitalWrite(SEG_PIN_C, LOW);
  digitalWrite(SEG_PIN_D, LOW);
  digitalWrite(SEG_PIN_E, LOW);
  digitalWrite(SEG_PIN_F, LOW);
  digitalWrite(SEG_PIN_G, LOW);
}
