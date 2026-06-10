const int LED_PIN = 25;
const int BTN_PIN = 16;
const int POT_PIN = 34;

void setup_pins() 
{
  pinMode(LED_PIN, OUTPUT);
  pinMode(BTN_PIN, INPUT_PULLUP);
}

int read_sensor()
{
  return analogRead(POT_PIN);
}

void update_led()
{
  int btn_state = digitalRead(BTN_PIN);

  if (btn_state == LOW)
  {
    digitalWrite(LED_PIN, HIGH);
  }
  else
  {
    digitalWrite(LED_PIN, LOW);
  }
}

void setup() 
{
  Serial.begin(115200);
  setup_pins();
}

void loop() 
{
  update_led();
  Serial.println(read_sensor());
  delay(500);
}