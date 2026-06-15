const int RX_PIN = 3;
const int BIT_TIME = 104; // ~9600 baud

uint8_t uartReceiveByte() {
  uint8_t data = 0;

  while (digitalRead(RX_PIN) == HIGH);

  delayMicroseconds(BIT_TIME + BIT_TIME / 2);

  for (int i = 0; i < 8; i++) {
    if (digitalRead(RX_PIN))
      data |= (1 << i);

    delayMicroseconds(BIT_TIME);
  }

  delayMicroseconds(BIT_TIME);

  return data;
}

void setup() {
  pinMode(RX_PIN, INPUT_PULLUP);

  Serial.begin(115200);
}

void loop() {
  char c = uartReceiveByte();

  Serial.print("Received: ");
  Serial.println(c);
}
