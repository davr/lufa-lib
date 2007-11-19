/*
             MyUSB Library
     Copyright (C) Dean Camera, 2007.
              
  dean [at] fourwalledcubicle [dot] com
      www.fourwalledcubicle.com

 Released under the GPL Licence, Version 3
*/

#ifndef __HOSTCHAP9_H__
#define __HOSTCHAP9_H__

	/* Includes: */
		#include <avr/io.h>
		#include <avr/pgmspace.h>
		#include <stdbool.h>
		
		#include "LowLevel.h"
		#include "StdRequestType.h"

	/* Public Interface - May be used in end-application: */
		/* Macros: */
			#define HOST_SEND_CONTROL_OK      false
			#define HOST_SEND_CONTROL_ERROR   true
	
		/* Type Defines: */
			typedef struct
			{
				uint8_t  RequestType;
				uint8_t  RequestData;
				
				union
				{
					uint16_t Value;
					
					struct
					{
						uint8_t Value_LowByte;
						uint8_t Value_HighByte;
					};
				};

				uint16_t Index;
				uint16_t Length;
			} USB_Host_Request_Header_t;
		
		/* Global Variables: */
			extern USB_Host_Request_Header_t USB_HostRequest;
			
		/* Function Prototypes: */
			bool USB_Host_SendControlRequest(uint8_t* DataBuffer);

#endif
