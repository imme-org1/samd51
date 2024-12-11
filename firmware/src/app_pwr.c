/*******************************************************************************
  File Name:
    app_pwr.c

  Summary:
    Power task.

  Description:
 *******************************************************************************/
#include "app_pwr.h"

extern void dsp_init();
extern void dsp_setup();
extern void air_init();

// .............................................................................

// Enable 1.8V general power rail (including right board)
void PowerEnable_1V8()
{
    osDelayMs(10);
    VDD_1V8_EN_Set();
}
// Enable 3.3V general power rail (including right board)
void PowerEnable_3V3()
{
    osDelayMs(10);
    U3V3_VDD_EN_Set();
}
// Enable 3.3V power for DSP AMP
// It needs the general 3V3 rail as the source.
void PowerEnable_AMP()
{
    osDelayMs(10);
    DSP_PWR_EN_Set();
    osDelayMs(10);
    ADAU1860_PD_Set(); // wake dsp up from power down
    osDelayMs(50);

}
// Airoha power control
void PowerEnable_Airoha()
{
    //RESET_77_Clear();   // keep the airoha in reset
    REGEN_77_Set();     // airoha regulator enable
    osDelayMs(1000);
    REGEN_77_Clear();     // release the airoha from reset
    //REGEN_77_Set();
    // Activate the 5V boost for the little batt charger in Airoha
    osDelayMs(10);
    U5V_DC_DC_EN_Set();
}

/*******************************************************************************
 * Task initializations.
 * This function runs BEFORE task is created and scheduler started!.
 */
void APP_PWR_Initialize ( void )
{
}

// .............................................................................
// power up everything, and delay for a short time at the end, to allow
// wear sensor to initialise.
// .............................................................................
void power_state_power_on()
{
    // Full power up as before
    PowerEnable_1V8();
    PowerEnable_3V3();
    PowerEnable_AMP();
    PowerEnable_Airoha();
    GlobalPowerOn = 1;
}

/******************************************************************************
 * The task.
 */
void APP_PWR_Tasks ( void )
{
    // Power up everything up
    power_state_power_on();

    while(1) {
        osDelayMs(100); 
    }
}
