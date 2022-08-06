
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

	hWifiModule.controlFlags.flag.configurationNotify = ENABLE;

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

			strcpy(hWifiModule.txBuffer, AT_FIRMWARE_MENU_OPEN);

			hWifiModule.txPacketSize = 1;

			++configStages;
			break;
		case 1:
			hWifiModule.controlFlags.flag.packetToTransmit = ENABLE;

			strcpy(hWifiModule.txBuffer, AT_FIRMWARE_MENU_CONFIRM);

			hWifiModule.txPacketSize = 1;

			++configStages;
			break;
		case 2:
			hWifiModule.controlFlags.flag.packetToTransmit = ENABLE;

			strcpy(hWifiModule.txBuffer, AT_DEFAULT_WiFi_FIRMWARE);

			hWifiModule.txPacketSize = 1;

			++configStages;
			break;
		case 3:
			hWifiModule.controlFlags.flag.packetToTransmit = ENABLE;

			strcpy(hWifiModule.txBuffer, AT_OPERAND_SETTINGS);

			hWifiModule.txPacketSize = strlen(AT_OPERAND_SETTINGS);

			++configStages;
			break;
		case 4:
			hWifiModule.controlFlags.flag.packetToTransmit = ENABLE;

			strcpy(hWifiModule.txBuffer, AT_BAND_SELECT);

			hWifiModule.txPacketSize = strlen(AT_BAND_SELECT);

			++configStages;
			break;
		case 5:
			hWifiModule.controlFlags.flag.packetToTransmit = ENABLE;

			strcpy(hWifiModule.txBuffer, AT_FRAME_SET);

			hWifiModule.txPacketSize = strlen(AT_FRAME_SET);

			++configStages;
			break;
		case 6:
			hWifiModule.controlFlags.flag.packetToTransmit = ENABLE;

			strcpy(hWifiModule.txBuffer, AT_SETTINGS_INIT);


			hWifiModule.txPacketSize = strlen(AT_SETTINGS_INIT);

			++configStages;
			break;
		case 7:
			hWifiModule.controlFlags.flag.packetToTransmit = ENABLE;

			strcpy(hWifiModule.txBuffer, AT_SSID_SCAN);

			hWifiModule.txPacketSize = strlen(AT_SSID_SCAN);
			++configStages;
			break;
		case 8:

			hWifiModule.controlFlags.flag.packetToTransmit = ENABLE;

			strcpy(hWifiModule.txBuffer, AT_PASSWORD_SET);

			strcat(hWifiModule.txBuffer, SSID_PASSWORD);

			strcat(hWifiModule.txBuffer, AT_TERMINATOR);

			hWifiModule.txPacketSize = strlen(hWifiModule.txBuffer);

			++configStages;
			break;

		case 9:
			hWifiModule.controlFlags.flag.packetToTransmit = ENABLE;

			strcpy(hWifiModule.txBuffer, AT_SSID_JOIN);

			strcat(hWifiModule.txBuffer, SSID_NAME);

			strcat(hWifiModule.txBuffer, AT_SSID_JOIN_PARAMETERS);

			hWifiModule.txPacketSize = strlen(hWifiModule.txBuffer);

//			hWifiModule.controlFlags.flag.configurationFase = DISABLE;

			++configStages;
			break;

		case 10:
			hWifiModule.controlFlags.flag.packetToTransmit = ENABLE;

			strcpy(hWifiModule.txBuffer, AT_IP_CONFIG_SET);

			hWifiModule.txPacketSize = strlen(AT_IP_CONFIG_SET);
			//Stop Configuration sequence
			hWifiModule.controlFlags.flag.configurationFase = DISABLE;

			++configStages;
			break;


	}
}

void wifiModuleHttpGetRequest(void)
{
	hWifiModule.controlFlags.flag.packetToTransmit = ENABLE;

	strcpy(hWifiModule.txBuffer, AT_HTTP_GET);

	hWifiModule.txPacketSize = strlen(AT_HTTP_GET);
}
/**************************  Useful Electronics  ****************END OF FILE***/
