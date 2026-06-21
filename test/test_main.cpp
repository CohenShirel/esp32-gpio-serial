#include <Arduino.h>
#include <unity.h>
#include "logic.h"

void setUp(void) 
{
    // runs before every test
}

void tearDown(void) 
{
    // runs after every test
}

void test_compute_blink_delay_min(void) 
{
    int delay_ms = compute_blink_delay(0);
    TEST_ASSERT_EQUAL(1000, delay_ms);
}

void test_compute_blink_delay_max(void) 
{
    int delay_ms = compute_blink_delay(4095);
    TEST_ASSERT_EQUAL(50, delay_ms);
}

void setup() 
{
    delay(2000);
    UNITY_BEGIN();
    RUN_TEST(test_compute_blink_delay_min);
    RUN_TEST(test_compute_blink_delay_max);
    UNITY_END();
}

void loop() 
{
    // not used in tests
}
