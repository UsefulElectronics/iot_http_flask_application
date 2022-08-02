
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
/* ENUMORATIONS --------------------------------------------------------------*/

/* STRUCTURES & TYPEDEFS -----------------------------------------------------*/

/* VARIABLES -----------------------------------------------------------------*/

/* FUNCTIONS DECLARATION -----------------------------------------------------*/



#endif /* RYWB116_H_ */

/**************************  Useful Electronics  ****************END OF FILE***/
