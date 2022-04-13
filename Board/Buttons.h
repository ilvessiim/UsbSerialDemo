#define BUTTONS_BUTTON1 (1 << PD1)
#define BUTTONS_BUTTON2 (1 << PD4)
#define BUTTONS_BUTTON3 (1 << PD7)

#define BUTTONS_ALL (BUTTONS_BUTTON1 | BUTTONS_BUTTON2 | BUTTONS_BUTTON3)

static inline void Buttons_Init(void)
{
	// Initialize the appropriate port pins as an inputs here, with pull-ups
	// See Atmel doc 7799, section 12.2.3
	DDRD &= ~BUTTONS_ALL;
	PORTD |= BUTTONS_ALL;
}

static inline void Buttons_Disable(void)
{
	// Clear the appropriate port pins as high impedance inputs here
	DDRD &= ~BUTTONS_ALL;
	PORTD &= ~BUTTONS_ALL;
}

static inline uint8_t Buttons_GetStatus(void)
{
	// Return current button status here, debounced if required
	return ((PIND & BUTTONS_ALL) ^ BUTTONS_ALL);
}