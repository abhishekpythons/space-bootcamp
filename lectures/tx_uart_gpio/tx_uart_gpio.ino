const int TX_PIN = 2;
const int BIT_TIME = 104; // ~9600 baud

void uartSendByte(uint8_t data) {
  digitalWrite(TX_PIN, LOW);   // Start bit
  delayMicroseconds(BIT_TIME);

  for (int i = 0; i < 8; i++) {
    digitalWrite(TX_PIN, (data >> i) & 1);
    delayMicroseconds(BIT_TIME);
  }

  digitalWrite(TX_PIN, HIGH);  // Stop bit
  delayMicroseconds(BIT_TIME);
}

void uartSendString(const char *s) {
  while (*s) {
    uartSendByte(*s++);
  }
}

void setup() {
  pinMode(TX_PIN, OUTPUT);
  digitalWrite(TX_PIN, HIGH);

  Serial.begin(115200);
}

void loop() {
  uartSendString("Hello\n");

  Serial.println("Sent: Hello");

  delay(1000);
}
