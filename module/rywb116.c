
/**
 ******************************************************************************
 * @Channel Link    :  https://www.youtube.com/user/wardzx1
 * @file    		:  rywb116.c
 * @author  		:  Ward Almasarani - Useful Electronics
 * @version 		:  v.1.0
 * @date    		:  Aug 2, 2022
 * @brief   		:
 *
 ******************************************************************************/


/* INCLUDES ------------------------------------------------------------------*/
#include "rywb116.h"
#include "stm32f4xx_hal.h"
/* PRIVATE STRUCTRES ---------------------------------------------------------*/

/* VARIABLES -----------------------------------------------------------------*/
hWifiModule_t hWifiModule;
/* DEFINITIONS ---------------------------------------------------------------*/

/* MACROS --------------------------------------------------------------------*/

/* PRIVATE FUNCTIONS DECLARATION ---------------------------------------------*/

/* FUNCTION PROTOTYPES -------------------------------------------------------*/
void wifiModuleInit(void)
{
	memset(&hWifiModule, 0, sizeof(hWifiModule_t));

	HAL_GPIO_WritePin(WIFI_MODULE_RESET_GPIO_PORT, WIFI_MODULE_RESET_PIN, ENABLE);
}

void wifiModuleConfigSequence(void)
{

}
/**************************  Useful Electronics  ****************END OF FILE***/
