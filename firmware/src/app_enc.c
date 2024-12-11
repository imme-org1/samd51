/*******************************************************************************
  File Name:
    app_enc.c

  Summary:
    Encoder task. Encoder, buttons and leds.

  Description:
 *******************************************************************************/
#include "app_enc.h"


/*******************************************************************************
 * Leds
 *******************************************************************************/
// RED LED
void led_red_init()
{
    TC7_Compare8bitMatch1Set(0);
    TC7_CompareStart();
}
void led_red_pwm(uint8_t pwm)
{
    TC7_CompareStop();
    TC7_Compare8bitMatch1Set(pwm);
    TC7_CompareStart();
}
// GREEN LED
void led_green_init()
{
    TC4_Compare8bitMatch1Set(0);
    TC4_CompareStart();
}
void led_green_pwm(uint8_t pwm)
{
    TC4_CompareStop();
    TC4_Compare8bitMatch1Set(pwm);
    TC4_CompareStart();
}

/*******************************************************************************
 * Task initializations.
 * This function runs BEFORE task is created and scheduler started!.
 */
void APP_ENC_Initialize ( void )
{
}


/******************************************************************************
 * The task.
 */
void APP_ENC_Tasks ( void )
{
    uint8_t led_cntr = 0;

    led_red_init();
    led_green_init();

    while(1) {
        osDelayMs(1000);
        led_cntr = (led_cntr + 1) % 3;
        switch (led_cntr) {
            case 0:
                led_green_pwm(0xFF);
                led_red_pwm(0x00);
                break;
            case 1:
                led_green_pwm(0x00);
                led_red_pwm(0xFF);
                break;
            case 2:
            default:
                led_green_pwm(0x00);
                led_red_pwm(0x00);
                break;
        }
    }
}
