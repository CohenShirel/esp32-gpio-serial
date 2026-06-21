#include <Arduino.h>
#include "logic.h"

const int LED_PIN = 25;
const int BTN_PIN = 16;
const int POT_PIN = 34;

bool led_state = false;
unsigned long last_toggle_ms = 0;

struct Inputs 
{
    int sensor_value;
    int button_state;
};

void setup_pins()
{
    pinMode(LED_PIN, OUTPUT);
    pinMode(BTN_PIN, INPUT_PULLUP);
}

Inputs read_inputs()
{
    int sensor_val = analogRead(POT_PIN);
    int btn_raw = digitalRead(BTN_PIN);
    int btn_state = (btn_raw == LOW) ? 1 : 0;
    return {sensor_val, btn_state};
}


void update_led(int button_state, int blink_delay, unsigned long now_ms)
{
    if (button_state == 1) 
    {
        digitalWrite(LED_PIN, HIGH);
        led_state = true;
        return;
    }

    if (now_ms - last_toggle_ms >= (unsigned long)(blink_delay / 2)) 
    {
        led_state = !led_state;
        digitalWrite(LED_PIN, led_state ? HIGH : LOW);
        last_toggle_ms = now_ms;
    }
}

void print_telemetry(int sensor_value, int button_state, bool led_is_on, unsigned long now_ms)
{
    static unsigned long last_print_ms = 0;
    if (now_ms - last_print_ms >= 100) 
    {
        Serial.printf("sensor=%d,button=%d,led=%s\n",
                      sensor_value, button_state, led_is_on ? "ON" : "OFF");
        last_print_ms = now_ms;
    }
}

void setup()
{
    Serial.begin(115200);
    setup_pins();
}

void loop()
{
    unsigned long now_ms = millis();
    
    Inputs inputs = read_inputs();
    
    int blink_delay = compute_blink_delay(inputs.sensor_value);
    
    update_led(inputs.button_state, blink_delay, now_ms);
    
    print_telemetry(inputs.sensor_value, inputs.button_state, led_state, now_ms);
    
    delay(20);
}