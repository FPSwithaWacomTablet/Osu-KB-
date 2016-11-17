/* Big shoutout to Thnikk @ http://thnikk.moe/
 * He has made some major contributions in the creation of my small little project
 * May peppy bless his soul.
 * 
 * Also thanks to the DME labs at Ryerson University for providing access to other resources in this project
 * May they never run out of filament or wire :)
 */

#include <Bounce.h> // this is needed to use the debouncer library

/* The key bindings can be changed here

According to pin assignments,

KEYP_1 is the leftmost button
KEYP_2 is the middle left button
KEYP_3 is the middle right button
KEYP_4 is the rightmost button

*/

#define KEYP_1 KEY_Z // 
#define KEYP_2 KEY_X // 
#define KEYP_3 KEY_C //
#define KEYP_4 KEY_ESC //

/*

To change the key binds, follow this template:

#define KEYP_(some number) KEY_(WHATEVER YOU WANT SENT)

The keyboard chart can be found at: https://www.pjrc.com/teensy/td_keyboard.html
Bear in mind that these keys should speak for themselves.

*/

// Pins that read your buttons

const int key_1 = 0;
const int key_2 = 1;  
const int key_3 = 2;
const int key_4 = 3;

Bounce button1 = Bounce(0, 8); // first number is pin number and second number is debounce time
Bounce button2 = Bounce(1, 8); // Must pay attention to debounce times of your switch
Bounce button3 = Bounce(2, 8); // Cherry MX is rated for 5 ms debounce (please verify via datasheet), though I would personally use a little bit more
Bounce button4 = Bounce(3, 8);

/*

Template: Bounce 'object' = Bounce( 'pin your button reads from', 'debounce time');

*/

void setup() {
  pinMode(key_1, INPUT_PULLUP); // Here we are telling the teensy what pin 0 is being used for
  pinMode(key_2, INPUT_PULLUP); // Input pullup assumes the board has internal resistors, otherwise use an external resistor in pullup configuration
  pinMode(key_3, INPUT_PULLUP); 
  pinMode(key_4, INPUT_PULLUP);

}

void loop() {

  button1.update(); // T
  his is reqired for your code to  actually send the keypress to the computer
  button2.update();
  button3.update();
  button4.update();
  
  if (button1.fallingEdge()) { // fallingEdge is when the key is pressed; presses 'key' as soon as the voltage drops, rather than waiting to settle to 0V
    Keyboard.press(KEYP_1);
  }
  if (button1.risingEdge()) { // risingEdge is when the key is not pressed; releases 'key' as soon as the voltage rises, rather than waiting to rise to 3.3V
    Keyboard.release(KEYP_1);
  }

  if (button2.fallingEdge()) { //Rinse and repeat for the rest of the keys
    Keyboard.press(KEYP_2);
  }
  if (button2.risingEdge()) { 
    Keyboard.release(KEYP_2);
  }
  
  if (button3.fallingEdge()) {
    Keyboard.press(KEYP_3);
  }
  if (button3.risingEdge()) { 
    Keyboard.release(KEYP_3);
  }
  
  if (button4.fallingEdge()) {
    Keyboard.press(KEYP_4);
  }
  if (button4.risingEdge()) { 
    Keyboard.release(KEYP_4);
  }
}
