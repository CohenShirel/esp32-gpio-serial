# Manual Test Cases

This document defines the expected behavior of the system under both edge cases and standard operating conditions. Before any new release or significant firmware change, verify that the system correctly passes the following scenarios.

## Scenario 1: Minimum Sensor Reading (Sensor = 0)
* **Test Action:** Rotate the potentiometer to its absolute minimum value.
* **Expected Input:** The analog reading from the sensor is approximately 0 (accounting for minor signal noise).
* **Expected Hardware Behavior:** The LED blinks at the slowest rate (1000ms delay between toggles).
* **Expected Serial Output:** `sensor=0,button=0,led=ON` (alternating with `led=OFF` at the same interval).

## Scenario 2: Maximum Sensor Reading (Sensor = 4095)
* **Test Action:** Rotate the potentiometer to its absolute maximum value.
* **Expected Input:** The analog reading from the sensor is approximately 4095.
* **Expected Hardware Behavior:** The LED blinks at the fastest rate (50ms delay between toggles).
* **Expected Serial Output:** `sensor=4095,button=0,led=ON` (alternating rapidly with `led=OFF`).

## Scenario 3: Button Pressed
* **Test Action:** Press and hold the push button.
* **Expected Input:** The digital reading from the button pin goes LOW (`btn_state=1`).
* **Expected Hardware Behavior:** The LED remains steadily ON without blinking for the duration of the press. Upon release, the LED resumes blinking at the rate dictated by the potentiometer.
* **Expected Serial Output:** `sensor=[current_value],button=1,led=ON` consistently while held.
