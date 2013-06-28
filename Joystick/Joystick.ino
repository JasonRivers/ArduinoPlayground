/* Arduino USB Joystick HID demo */

/* Author: Darran Hunt
 * Released into the public domain.
 */

#undef DEBUG;

#define NUM_BUTTONS	14
#define NUM_AXES	8	       // 8 axes, X, Y, Z, etc

typedef struct joyReport_t {
    int16_t axis[NUM_AXES];
    uint8_t button[(NUM_BUTTONS+7)/8]; // 8 buttons per byte
} joyReport_t;

joyReport_t joyReport;


void setup(void);
void loop(void);
void setButton(joyReport_t *joy, uint8_t button);
void clearButton(joyReport_t *joy, uint8_t button);
void sendJoyReport(joyReport_t *report);

// Buttons 1-10

byte buttons[] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13}; //Buttons 1-14 using pins 0-13
byte axisinput[] = {14,15,16,17,18,19}; //axis using A0-A5

void setup() 
{
    Serial.begin(115200);
    delay(200); //wait for everything to be ready...

    for (uint8_t ind=0; ind<8; ind++) {
	joyReport.axis[ind] = ind*1000;
    }
    for (uint8_t ind=0; ind<sizeof(joyReport.button); ind++) {
        joyReport.button[ind] = 0;
    }
    for (uint8_t i=0; i< NUM_BUTTONS; i++){
        pinMode(buttons[i], INPUT);
	digitalWrite(buttons[i], HIGH);
    }
}

// Send an HID report to the USB interface
void sendJoyReport(struct joyReport_t *report)
{
#ifndef DEBUG
    Serial.write((uint8_t *)report, sizeof(joyReport_t));
#else
    // dump human readable output for debugging
//    for (uint8_t ind=0; ind<NUM_AXES; ind++) {
//	Serial.print("axis[");
//	Serial.print(ind);
//	Serial.print("]= ");
//	Serial.print(report->axis[ind]);
//	Serial.print(" ");
//    }
//    Serial.println();
    for (uint8_t ind=0; ind<NUM_BUTTONS/8; ind++) {
	Serial.print("button[");
	Serial.print(ind);
	Serial.print("]= ");
	Serial.print(report->button[ind], HEX);
	Serial.print(" ");
    }
    Serial.println();
#endif
}

// turn a button on
void setButton(joyReport_t *joy, uint8_t button)
{
    uint8_t index = button/8;
    uint8_t bit = button - 8*index;

    joy->button[index] |= 1 << bit;
}

// turn a button off
void clearButton(joyReport_t *joy, uint8_t button)
{
    uint8_t index = button/8;
    uint8_t bit = button - 8*index;

    joy->button[index] &= ~(1 << bit);
}

uint8_t button=0;	// current button
bool press = true;	// turn buttons on?
bool toggle = true;

/* Turn each button on in sequence 1 - 40, then off 1 - 40
 * add values to each axis each loop
 */
void loop() 
{
button = buttons[1];
if (toggle) {
	setButton(&joyReport, button);
	toggle = false;
} else {
	clearButton(&joyReport, button);
	toggle = true;

}
    // Turn on a different button each time
//    if (press) {
//	setButton(&joyReport, button);
//    } else {
//	clearButton(&joyReport, button);
//    }

    /* Move all of the axes */
//    for (uint8_t ind=0; ind<8; ind++) {
//	joyReport.axis[ind] += 10 * (ind+1);
//    }

    sendJoyReport(&joyReport);

//    button++;
//    if (button >= NUM_BUTTONS) {
//       button = 0;
//       press = !press;
//    }
    delay(1000);
}
