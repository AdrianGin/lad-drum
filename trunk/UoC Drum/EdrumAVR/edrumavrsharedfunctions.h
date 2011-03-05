#ifndef _EDRUM_AVR_SHARED_FUNCTIONS
#define _EDRUM_AVR_SHARED_FUNCTIONS

#include <stdint.h>
#include "hardwareSpecific.h"


typedef void (*PF_VOID)(void);
typedef void (*PF_USBMIDI_PutByte)(uint8_t);
typedef void (*PF_usbSetInterrupt)(uint8_t*, uint8_t);
typedef uint8_t (*PF_USBMIDI_GetByte)(void);

#define JUMP_TABLE_FUNCTION(x) ((JUMP_TABLE_LOCATION + (4*x))/2)


#define usbPoll()                      ((PF_VOID)(JUMP_TABLE_FUNCTION(0)))()
#define usbFunctionWriteOut(data, len) ((PF_VOID)(JUMP_TABLE_FUNCTION(1)))(data, len)
#define usbSetInterrupt(data, len)     ((PF_usbSetInterrupt)(JUMP_TABLE_FUNCTION(2)))(data, len)
#define bootloader_enter()             ((PF_VOID)(JUMP_TABLE_FUNCTION(3)))()
#define usbInit()                      ((PF_VOID)(JUMP_TABLE_FUNCTION(4)))()
#define USBMIDI_PutByte(inbyte)        ((PF_USBMIDI_PutByte)(JUMP_TABLE_FUNCTION(5)))(inbyte)
#define USBMIDI_OutputData()           ((PF_VOID)(JUMP_TABLE_FUNCTION(6)))()
#define USBMIDI_EnableRequests()       ((PF_VOID)(JUMP_TABLE_FUNCTION(7)))()
#define USBMIDI_GetByte()              ((PF_USBMIDI_GetByte)(JUMP_TABLE_FUNCTION(8)))()



#endif