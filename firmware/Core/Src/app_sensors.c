#include "app_sensors.h"
#include "logger.h"
#include "drivers/lsm6dso.h"
#include "drivers/lis2mdl.h"
#include "drivers/lps22hb.h"
#include "drivers/gnss.h"
#include "drivers/rgb_led.h"
#include "cmsis_os.h"
#include <stdio.h>

void AppSensors_Init(void) {
    LSM6DSO_Init();
    LIS2MDL_Init();
    LPS22HB_Init();
    GNSS_Init();
    RGB_LED_Init();

    Logger_Init(); // Init SD Card FATFS last
}

void AppSensors_Task(void) {
    char log_buffer[128];

    // 1. Read all sensors
    LSM6DSO_Read();
    LIS2MDL_Read();
    LPS22HB_Read();
    GNSS_Read();

    // 2. Control LED (Blink or status)
    static int tick = 0;
    tick++;
    RGB_LED_SetColor(0, tick % 255, 0); // Blink demo

    // 3. Format string completely (dummy variables for now until drivers parse data)
    sprintf(log_buffer, "%lu, %.2f, %.2f, %.2f, %.2f, %.2f, %.2f, %.2f, %.4f, %.4f\n",
            HAL_GetTick(), // Time in ms
            0.0, 0.0, 0.0, // Acc
            0.0, 0.0, 0.0, // Mag
            1013.25,       // Press
            0.0, 0.0);     // GPS Lat, Lon

    // 4. Save to SD Card
    Logger_LogData(log_buffer);

    // 5. Task frequency control
    osDelay(100); // 10Hz sampling/logging loop
}
