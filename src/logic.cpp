#include "logic.h"

int compute_blink_delay(int sensor_value)
{
    return map(sensor_value, 0, 4095, 1000, 50);
}
