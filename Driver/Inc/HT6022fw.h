/**
  ******************************************************************************
  * @file    HT6022fw.c
  * @author  Rodrigo Pedroso Mendes
  * @email   rpm_2003_rpm@yahoo.com.br
  * @version V1.0
  * @date    04-14-2013
  * @brief   This file provides the HT6022 firmware header         
  ******************************************************************************
  */


/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __HT6022FW_H
#define __HT6022FW_H

#ifdef __cplusplus
 extern "C" {
#endif



/** @addtogroup HT6022_Driver
  * @{
  */
/* Private define ------------------------------------------------------------*/ 
#define HT6022_FIRMWARE_SIZE 458
#define HT6022_FIRMWARE_VENDOR_ID    0X4B4
#define HT6022_FIRMWARE_REQUEST_TYPE 0X40
#define HT6022_FIRMWARE_REQUEST      0XA0
#define HT6022_FIRMWARE_INDEX        0X00

/*Exported variables---------------------------------------------------------*/
extern unsigned char HT6022_Firmware[];

/**
  * @}
  */ 

#ifdef __cplusplus
	}
#endif

#endif

/****************************END OF FILE*********************************/
