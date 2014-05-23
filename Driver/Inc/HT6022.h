/**
  ******************************************************************************
  * @mainpage HT6022 Driver
  * @author  Rodrigo Pedroso Mendes 
  * @email   rpm_2003_rpm@yahoo.com.br
  * @file    HT6022.h
  * @version V1.0
  * @date    04-14-2013
  * @brief   Here you find functions prototypes for the HT6022 driver library.
  ******************************************************************************
  */


/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __HT6022_H
#define __HT6022_H

/* Includes ------------------------------------------------------------------*/
#include <libusb-1.0/libusb.h>

#ifdef __cplusplus
 extern "C" {
#endif

/** @addtogroup HT6022_Driver
  * @{
  */

/* Exported types ------------------------------------------------------------*/
/** 
  * @brief Device Handle
  */
typedef struct 
{
	libusb_device_handle *DeviceHandle;
	unsigned char Address;
}HT6022_DeviceTypeDef;
                                                               
/** 
  * @brief Error Code  
  */   
typedef enum
{ 
     HT6022_SUCCESS  = 0,
     HT6022_ERROR_INVALID_PARAM = -2,
     HT6022_ERROR_ACCESS        = -3,
     HT6022_ERROR_NO_DEVICE     = -4,
     HT6022_ERROR_TIMEOUT       = -7,
     HT6022_ERROR_NO_MEM        = -11, 
     HT6022_ERROR_OTHER         = -99
}HT6022_ErrorTypeDef;
#define  IS_HT6022_ERROR(ERROR) (((ERROR) == HT6022_SUCCESS) || \
				 ((ERROR) == HT6022_ERROR_INVALID_PARAM) || \
				 ((ERROR) == HT6022_ERROR_ACCESS )   || \
				 ((ERROR) == HT6022_ERROR_NO_DEVICE) || \
				 ((ERROR) == HT6022_ERROR_TIMEOUT)   || \
				 ((ERROR) == HT6022_ERROR_NO_MEM)    || \
                 ((ERROR) == HT6022_ERROR_OTHER))
 
/** 
  * @brief  Size of data bufffer
  */   
typedef enum
{ 
  HT6022_1KB   = 0x00000400, /*!< 1024 Bytes */
  HT6022_2KB   = 0x00000800, /*!< 2048 Bytes */
  HT6022_4KB   = 0x00001000, /*!< 4096 Bytes */
  HT6022_8KB   = 0x00002000, /*!< 8192 Bytes */
  HT6022_16KB  = 0x00004000, /*!< 16384 Bytes */
  HT6022_32KB  = 0x00008000, /*!< 32768 Bytes */
  HT6022_64KB  = 0x00010000, /*!< 65536 Bytes */
  HT6022_128KB = 0x00020000, /*!< 131072 Bytes */
  HT6022_256KB = 0x00040000, /*!< 262144 Bytes */
  HT6022_512KB = 0x00080000, /*!< 524288 Bytes */
  HT6022_1MB   = 0x00100000  /*!< 1048576 Bytes */
}HT6022_DataSizeTypeDef;
#define  IS_HT6022_DATASIZE(SIZE) (((SIZE) == HT6022_1KB)  ||\
                                   ((SIZE) == HT6022_2KB)  ||\
                                   ((SIZE) == HT6022_4KB)  ||\
                                   ((SIZE) == HT6022_8KB)  ||\
                                   ((SIZE) == HT6022_16KB) ||\
                                   ((SIZE) == HT6022_32KB) ||\
                                   ((SIZE) == HT6022_64KB) ||\
                                   ((SIZE) == HT6022_128KB)||\
                                   ((SIZE) == HT6022_256KB)||\
                                   ((SIZE) == HT6022_512KB)||\
                                   ((SIZE) == HT6022_1MB))

/** 
  * @brief Size of calibration values buffer 
  */   
typedef enum
{ 
  HT6022_32B   = 0x00000010, /*!< 32 Bytes */
  HT6022_64B   = 0x00000020, /*!< 64 Bytes */
  HT6022_128B  = 0x00000080 /*!< 128 Bytes */
}HT6022_CVSizeTypeDef;
#define  IS_HT6022_CVSIZE(SIZE) (((SIZE) == HT6022_32B)  ||\
                                 ((SIZE) == HT6022_64B)  ||\
                                 ((SIZE) == HT6022_128B))

/** 
  * @brief  Sample rate 
  */   
typedef enum
{ 
  	HT6022_24MSa  = 0x30, /*!< 24MSa per channel */
	HT6022_16MSa  = 0x10, /*!< 16MSa per channel */
	HT6022_8MSa   = 0x08, /*!< 8MSa per channel */
	HT6022_4MSa   = 0x04, /*!< 4MSa per channel */
	HT6022_1MSa   = 0x01, /*!< 1MSa per channel */
	HT6022_500KSa = 0x32, /*!< 500KSa per channel */
	HT6022_200KSa = 0x14, /*!< 200KSa per channel */
	HT6022_100KSa = 0x0A  /*!< 100KSa per channel */
}HT6022_SRTypeDef;
#define  IS_HT6022_SR(SR) (((SR) == HT6022_24MSa)  ||\
                          ((SR) == HT6022_16MSa)  ||\
                          ((SR) == HT6022_8MSa)   ||\
                          ((SR) == HT6022_4MSa)   ||\
                          ((SR) == HT6022_1MSa)   ||\
                          ((SR) == HT6022_500KSa) ||\
                          ((SR) == HT6022_200KSa) ||\
                          ((SR) == HT6022_100KSa))

/** 
  * @brief Input range 
  */   
typedef enum
{ 
  	HT6022_10V   = 0x01, /*!< -5V    to 5V    */
  	HT6022_5V    = 0x02, /*!< -2.5V  to 2.5V  */
  	HT6022_2V    = 0x05, /*!< -1V    to 1V    */
  	HT6022_1V    = 0x0A  /*!< -500mv to 500mv */
}HT6022_IRTypeDef;
#define  IS_HT6022_IR(IR)   (((IR) == HT6022_10V) ||\
                             ((IR) == HT6022_5V)  ||\
                             ((IR) == HT6022_2V)  ||\
                             ((IR) == HT6022_1V))


/* Exported constants --------------------------------------------------------*/
/* Exported macro ------------------------------------------------------------*/


/* Exported functions --------------------------------------------------------*/ 
/* Initialization and Configuration functions *********************************/
HT6022_ErrorTypeDef	HT6022_Init (void);
void HT6022_Exit (void);
HT6022_ErrorTypeDef	HT6022_DeviceOpen (HT6022_DeviceTypeDef *Device);
void HT6022_DeviceClose (HT6022_DeviceTypeDef *Device);
HT6022_ErrorTypeDef HT6022_FirmwareUpload (void); 
/* Read functions ********************************************************/
HT6022_ErrorTypeDef	HT6022_ReadData (HT6022_DeviceTypeDef *Device,
									 unsigned char* CH1, unsigned char* CH2,
					 				 HT6022_DataSizeTypeDef DataSize, 
                                     unsigned int  Timeout);
/* Read and Write calibration values functions *********************************/
HT6022_ErrorTypeDef	HT6022_SetCalValues (HT6022_DeviceTypeDef *Device,
					    			 	 unsigned char* CalValues,
                                         HT6022_CVSizeTypeDef CVSize); 
HT6022_ErrorTypeDef	HT6022_GetCalValues (HT6022_DeviceTypeDef *Device,
					    				 unsigned char* CalValues,   
					    				 HT6022_CVSizeTypeDef CVSize); 
/* Sample rate and input range configuration functions *******************************/
HT6022_ErrorTypeDef	HT6022_SetSR (HT6022_DeviceTypeDef *Device,
				      			  HT6022_SRTypeDef SR);
HT6022_ErrorTypeDef HT6022_SetCH1IR (HT6022_DeviceTypeDef *Device,
				          			 HT6022_IRTypeDef IR);
HT6022_ErrorTypeDef HT6022_SetCH2IR (HT6022_DeviceTypeDef *Device,
				                     HT6022_IRTypeDef IR);
#ifdef __cplusplus
}
#endif

#endif

/**
  * @}
  */ 

/**********************************END OF FILE********************************/
