/** LED mask for the first LED on the board. */
#define LEDS_LED1   (1 << PB7)

/** LED mask for the second LED on the board. */
#define LEDS_LED2   (1 << PC6)

/** LED mask for the third LED on the board. */
#define LEDS_LED3   (1 << PC5)

#define LEDS_GB (LEDS_LED2 | LEDS_LED3)

/** LED mask for all the LEDs on the board. */
#define LEDS_ALL_LEDS    (LEDS_LED1 | LEDS_LED2 | LEDS_LED3)

/** LED mask for none of the board LEDs. */
#define LEDS_NO_LEDS     0

/* Inline Functions: */
static inline void LEDs_Init(void)
{
	// initialize LED port pins as outputs here
	DDRB |= LEDS_LED1;
	DDRC |= LEDS_GB;

	// Initialize to off by driving high
	PORTB |= LEDS_LED1;
	PORTC |= LEDS_GB;
}

static inline void LEDs_Disable(void)
{
	// Clear the LED port pins as high impedance inputs here
	DDRB &= ~LEDS_LED1;
	DDRC &= ~LEDS_GB;

	PORTB &= ~LEDS_LED1;
	PORTC &= ~LEDS_GB;
}

static inline void LEDs_TurnOnLEDs(const uint8_t LEDMask)
{
	// turn on LEDs given in the LEDMask mask here, leave others as-is
	PORTB &= ~(LEDMask & LEDS_LED1);
	PORTC &= ~(LEDMask & LEDS_GB);
}

static inline void LEDs_TurnOffLEDs(const uint8_t LEDMask)
{
	// turn off LEDs given in the LEDMask mask here, leave others as-is
	PORTB |= LEDMask & LEDS_LED1;
	PORTC |= LEDMask & LEDS_GB;
}

static inline void LEDs_SetAllLEDs(const uint8_t LEDMask)
{
	// turn on only LEDs given in the LEDMask mask here, all others off
	PORTB = ( (PORTB | LEDS_LED1) & ~LEDMask);
	PORTC = ( (PORTC | LEDS_GB) & ~LEDMask);
}

static inline void LEDs_ChangeLEDs(const uint8_t LEDMask, const uint8_t ActiveMask)
{
	// set the Leds in the given LEDMask to the status given in ActiveMask here
	PORTB = ( (PORTB | (LEDS_LED1 & LEDMask)) & ~ActiveMask);
	PORTC = ( (PORTC | (LEDS_GB & LEDMask)) & ~ActiveMask);
}

static inline void LEDs_ToggleLEDs(const uint8_t LEDMask)
{
	// toggle the Leds in the given LEDMask, ignoring all others
	PINB = LEDMask & LEDS_LED1;
	PINC = LEDMask & LEDS_GB;
}

static inline uint8_t LEDs_GetLEDs(void)
{
	// return the current LEDs status' here which can be masked against LED_LED* macros
	return ((PORTB & LEDS_LED1) | (PORTC & LEDS_GB));
}