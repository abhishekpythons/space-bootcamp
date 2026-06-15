const int TX_PIN = 2;
const int BIT_TIME = 104;  // ~9600 baud (104 µs)

void uartSendByte(uint8_t data) {
  // Start bit
  digitalWrite(TX_PIN, LOW);
  delayMicroseconds(BIT_TIME);

  // Data bits
  for (int i = 0; i < 8; i++) {
    digitalWrite(TX_PIN, (data >> i) & 1);
    delayMicroseconds(BIT_TIME);
  }

  // Stop bit
  digitalWrite(TX_PIN, HIGH);
  delayMicroseconds(BIT_TIME);
}

void setup() {
  pinMode(TX_PIN, OUTPUT);
  digitalWrite(TX_PIN, HIGH);  // Idle state
}

void loop() {
  uartSendByte('H');
  uartSendByte('i');
  uartSendByte('\n');
  delay(1000);
}