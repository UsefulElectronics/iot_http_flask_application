
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
#include "ssid_config.h"
#include "stm32f4xx_hal.h"
/* PRIVATE STRUCTRES ---------------------------------------------------------*/

/* VARIABLES -----------------------------------------------------------------*/
hWifiModule_t hWifiModule;
/* DEFINITIONS ---------------------------------------------------------------*/

/* MACROS --------------------------------------------------------------------*/

/* PRIVATE FUNCTIONS DECLARATION ---------------------------------------------*/

/* FUNCTION PROTOTYPES -------------------------------------------------------*/
/**
 * @brief
 *
 */
void wifiModuleInit(void)
{
	memset(&hWifiModule, 0, sizeof(hWifiModule_t));

	hWifiModule.controlFlags.flag.configurationFase = ENABLE;

	HAL_GPIO_WritePin(WIFI_MODULE_RESET_GPIO_PORT, WIFI_MODULE_RESET_PIN, ENABLE);
}
/**
 * @brief
 *
 */
void wifiModuleConfigSequence(void)
{
	static uint8_t configStages = 0;

	switch(configStages)
	{
		case 0:
			hWifiModule.controlFlags.flag.packetToTransmit = ENABLE;

			strcpy(hWifiModule.rxBuffer, AT_FIRMWARE_MENU_OPEN);

			hWifiModule.rxPacketSize = 1;

			++configStages;
			break;
		case 1:
			hWifiModule.controlFlags.flag.packetToTransmit = ENABLE;

			strcpy(hWifiModule.rxBuffer, AT_FIRMWARE_MENU_CONFIRM);

			hWifiModule.rxPacketSize = 1;

			++configStages;
			break;
		case 2:
			hWifiModule.controlFlags.flag.packetToTransmit = ENABLE;

			strcpy(hWifiModule.rxBuffer, AT_DEFAULT_WiFi_FIRMWARE);

			hWifiModule.rxPacketSize = 1;

			++configStages;
			break;
		case 3:
			hWifiModule.controlFlags.flag.packetToTransmit = ENABLE;

			strcpy(hWifiModule.rxBuffer, AT_OPERAND_SETTINGS);

			hWifiModule.rxPacketSize = strlen(AT_OPERAND_SETTINGS);

			++configStages;
			break;
		case 4:
			hWifiModule.controlFlags.flag.packetToTransmit = ENABLE;

			strcpy(hWifiModule.rxBuffer, AT_BAND_SELECT);

			hWifiModule.rxPacketSize = strlen(AT_BAND_SELECT);

			++configStages;
			break;
		case 5:
			hWifiModule.controlFlags.flag.packetToTransmit = ENABLE;

			strcpy(hWifiModule.rxBuffer, AT_FRAME_SET);

			hWifiModule.rxPacketSize = strlen(AT_FRAME_SET);

			++configStages;
			break;
		case 6:
			hWifiModule.controlFlags.flag.packetToTransmit = ENABLE;

			strcpy(hWifiModule.rxBuffer, AT_SETTINGS_INIT);

			hWifiModule.rxPacketSize = strlen(AT_SETTINGS_INIT);

			++configStages;
			break;
		case 7:

			hWifiModule.controlFlags.flag.packetToTransmit = ENABLE;

			strcpy(hWifiModule.rxBuffer, AT_PASSWORD_SET);

			strcat(hWifiModule.rxBuffer, SSID_PASSWORD);

			strcat(hWifiModule.rxBuffer, AT_TERMINATOR);

			hWifiModule.rxPacketSize = strlen(hWifiModule.rxBuffer);

			++configStages;
			break;

		case 8:
			hWifiModule.controlFlags.flag.packetToTransmit = ENABLE;

			strcpy(hWifiModule.rxBuffer, AT_IP_CONFIG_SET);

			hWifiModule.rxPacketSize = strlen(AT_IP_CONFIG_SET);

			++configStages;
			break;

		case 9:
			hWifiModule.controlFlags.flag.packetToTransmit = ENABLE;

			strcpy(hWifiModule.rxBuffer, AT_SSID_JOIN);

			strcat(hWifiModule.rxBuffer, SSID_NAME);

			strcpy(hWifiModule.rxBuffer, AT_SSID_JOIN_PARAMETERS);

			hWifiModule.rxPacketSize = strlen(hWifiModule.rxBuffer);
			//Stop Configuration sequence
			hWifiModule.controlFlags.flag.configurationFase = DISABLE;

			++configStages;
			break;


	}
}
/**************************  Useful Electronics  ****************END OF FILE***/
