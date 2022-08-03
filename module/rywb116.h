
/**
 ******************************************************************************
 * @Channel Link    :  https://www.youtube.com/user/wardzx1
 * @file    		:  rywb116.h
 * @author  		:  Ward Almasarani - Useful Electronics
 * @version 		:  v.1.0
 * @date    		:  Aug 2, 2022
 * @brief   		:
 *
 ******************************************************************************/

#ifndef RYWB116_H_
#define RYWB116_H_


/* INCLUDES ------------------------------------------------------------------*/
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#include "stm32f4xx_hal.h"
/* MACROS --------------------------------------------------------------------*/
#define AT_FIRMWARE_MENU_OPEN		  	"\x1C"
#define AT_FIRMWARE_MENU_CONFIRM		"U"
#define AT_DEFAULT_WiFi_FIRMWARE		"1"
#define AT_OPERAND_SETTINGS				"at+rsi_opermode=851968,21,2148600726,2147483648,2150629376,3221225472,131072,1075773440\r\n"
#define AT_BAND_SELECT					"at+rsi_band=0\r\n"
#define AT_FRAME_SET					"at+rsi_feat_frame=0,1,0,0,1,49\r\n"
#define AT_SETTINGS_INIT				"at+rsi_init\r\n"
#define	AT_SSID_SCAN					"at+rsi_scan=0\r\n"
#define AT_PASSWORD_SET					"at+rsi_psk=1,"			//Must be appended with the SSID password and terminator characters
#define AT_IP_CONFIG_SET				"at+rsi_ipconf=1,0,0,0\r\n"
#define AT_TERMINATOR					"\r\n"

#define WIFI_MODULE_BUFFER_SIZE			300

#define WIFI_MODULE_RESET_PIN			GPIO_PIN_14
#define WIFI_MODULE_RESET_GPIO_PORT		GPIOB


/* ENUMORATIONS --------------------------------------------------------------*/

/* STRUCTURES & TYPEDEFS -----------------------------------------------------*/

typedef union
{	uint8_t all;
	struct
	{
		uint8_t packetReceived		:1,
				packetToTransmit	:1,
				reserved			:7;

	}flag;

}controlFlags_t;

typedef struct
{
	controlFlags_t	controlFlags;
	uint16_t txPacketSize;
	uint16_t rxPacketSize;
	char txBuffer[WIFI_MODULE_BUFFER_SIZE];
	char rxBuffer[WIFI_MODULE_BUFFER_SIZE];
}hWifiModule_t;
/* VARIABLES -----------------------------------------------------------------*/
extern hWifiModule_t hWifiModule;
/* FUNCTIONS DECLARATION -----------------------------------------------------*/
void wifiModuleInit(void);



#endif /* RYWB116_H_ */

/**************************  Useful Electronics  ****************END OF FILE***/
