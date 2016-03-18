/**
  @file  main.c
  @brief main entry of the BLE stack sample application.
*/

// XDC, RTOS, driverlib
#include <xdc/runtime/Error.h>
#include <ti/sysbios/family/arm/cc26xx/Power.h>
#include <ti/sysbios/family/arm/cc26xx/PowerCC2650.h>
#include <ti/sysbios/BIOS.h>
#include <driverlib/vims.h>

// BLE
#include "bcomdef.h"

// Modules with their own tasks
#include "SensorTag.h"
#include "SensorTag_Tmp.h"
#include "SensorTag_Hum.h"
#include "SensorTag_Bar.h"

#ifndef USE_DEFAULT_USER_CFG

#include "bleUserConfig.h"

// BLE user defined configuration
//bleUserCfg_t user0Cfg = BLE_USER_CFG;

#endif // USE_DEFAULT_USER_CFG

int main()
{
  //PIN_init(BoardGpioInitTable);

#ifndef POWER_SAVING
  /* Set constraints for Standby and Idle mode */
  Power_setConstraint(Power_SB_DISALLOW);
  Power_setConstraint(Power_IDLE_PD_DISALLOW);
#endif // POWER_SAVING

  /* Initialize ICall module */
  //ICall_init();

  /* Start tasks of external images - Priority 5 */
  //ICall_createRemoteTasks();

  /* Kick off profile - Priority 3 */
  //GAPRole_createTask();

  /* Kick off application - Priority 1 */
  //SensorTag_createTask();
  //SensorTagTmp_createTask();
  //SensorTagHum_createTask();
  //SensorTagBar_createTask();

  //BIOS_start();     /* enable interrupts and start SYS/BIOS */
  
  
  ///// TEST MAIN WITHOUT DOING ANYTHING
  
  int debug = 1;
  
  while(debug >= 1){
      debug++;
  }
  
  
  

  return 0;
}

/**
 * Error handlers to be hooked into TI-RTOS
 */
Void smallErrorHook(Error_Block *eb)
{
  for (;;);
}

void exceptionHandler()
{
	volatile uint8_t i = 1;

  while(i){}
}
