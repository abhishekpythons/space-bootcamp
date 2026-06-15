const int RX_PIN = 2;
const int BIT_TIME = 104;  // ~9600 baud

uint8_t uartReceiveByte() {
  uint8_t data = 0;

  // Wait for start bit
  while (digitalRead(RX_PIN) == HIGH);

  // Move to middle of first data bit
  delayMicroseconds(BIT_TIME + BIT_TIME / 2);

  // Read 8 bits
  for (int i = 0; i < 8; i++) {
    if (digitalRead(RX_PIN))
      data |= (1 << i);

    delayMicroseconds(BIT_TIME);
  }

  // Skip stop bit
  delayMicroseconds(BIT_TIME);

  return data;
}

void setup() {
  pinMode(RX_PIN, INPUT_PULLUP);
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  char c = uartReceiveByte();

  if (c == 'H') {
    digitalWrite(LED_BUILTIN, HIGH);
    delay(100);
    digitalWrite(LED_BUILTIN, LOW);
  }
}