void setup() {
  // Set pin 9 (PB1) as output
  pinMode(9, OUTPUT);

  // Clear Timer/Counter Control Registers
  TCCR1A = 0;
  TCCR1B = 0;

  // Set Fast PWM mode, with ICR1 as top value
  TCCR1A |= (1 << WGM11);
  TCCR1B |= (1 << WGM13) | (1 << WGM12);

  // Set non-inverting mode for OC1A (Pin 9)
  TCCR1A |= (1 << COM1A1);

  // Set ICR1 (top value) for desired frequency
  // Formula: Frequency = (Clock Speed) / (Prescaler * (ICR1 + 1))
  // For 18.5 kHz with 16 MHz clock and prescaler 1:
  // ICR1 = (16,000,000 / (1 * 18,500)) - 1 = 864
  ICR1 = 864;

  // Set OCR1A for desired duty cycle
  // For 5 us on-time with 16 MHz clock and prescaler 1:
  // OCR1A = (5 us * 16,000,000) / 1 = 80
  OCR1A = 80;

  // Start Timer1 with no prescaler
  TCCR1B |= (1 << CS10);
}

void loop() {
  // Main loop does nothing, Timer1 controls the PWM output
}