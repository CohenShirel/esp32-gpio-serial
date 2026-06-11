const int LED_PIN = 25;
const int BTN_PIN = 16;
const int POT_PIN = 34;

bool led_state = false;

void setup_pins()
{
    pinMode(LED_PIN, OUTPUT);
    pinMode(BTN_PIN, INPUT_PULLUP);
}

int read_sensor()
{
    return analogRead(POT_PIN);
}

void setup()
{
    Serial.begin(115200);
    setup_pins();
}

void loop()
{
    int sensor_val  = read_sensor();
    int btn_raw     = digitalRead(BTN_PIN);
    int btn_state   = (btn_raw == LOW) ? 1 : 0;

    int blink_delay = map(sensor_val, 0, 4095, 1000, 50);

    if (btn_state == 1)
    {
        digitalWrite(LED_PIN, HIGH);
        led_state = true;
        delay(blink_delay);
    }
    else
    {
        digitalWrite(LED_PIN, HIGH);
        led_state = true;
        delay(blink_delay / 2);

        digitalWrite(LED_PIN, LOW);
        led_state = false;
        delay(blink_delay / 2);
    }

    Serial.printf("sensor=%d,button=%d,led=%s\n",
                  sensor_val, btn_state, led_state ? "ON" : "OFF");
}