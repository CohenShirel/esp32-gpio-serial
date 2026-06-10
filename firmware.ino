const int LED_PIN = 25;

void setup_pins() 
{
  pinMode(LED_PIN, OUTPUT);
}

void update_led() 
{
  digitalWrite(LED_PIN, HIGH);
  delay(500);                  
  digitalWrite(LED_PIN, LOW);  
  delay(500);                 
}

void setup() 
{
  Serial.begin(115200);
  setup_pins();
}

void loop() 
{
  update_led(); 
}