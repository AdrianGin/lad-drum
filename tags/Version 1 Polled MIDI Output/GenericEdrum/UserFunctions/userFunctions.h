#ifndef USERFUNCTIONS_H
#define USERFUNCTIONS_H

#include "Menu/menu.h"
#include "Profiles/profiles.h"
#include "hardwareSpecific.h"

#define GET (0xFF)
#define ANALOGUE_ADJUST (0)
#define DIGITAL_ADJUST (1)

#define DOWNLOAD_FAILED (1)

enum {
	MAIN_SCREEN = 0,
   TECH_SPECS,
   CONTACT_INFO,
	SIZEOFABOUT
};

extern uint8_t SelectedChannel;

void UF_MenuSetInput(uint8_t NewInput);
void UF_stateMachine(uint8_t CurrentState);
void UF_executeState(uint8_t state);
void UF_MenuReset(void);
void UF_MenuNewLine(void);
void UF_MenuChar(uint8_t data);
void UF_MenuPrint_P(PGM_P string);
void UF_MenuPrint(char* string);
void UF_MenuUpOneLevel(Menu_t* menu);

void reset(void* data);
void about(void* data);
void aboutScroll(uint8_t nameIndex);
/* Pass GET to obtain the index, otherwise the index is set to the passed
 * parameter */
uint8_t ThanksIndex(uint8_t mode);

void SysExDisplay(void* data);
void DumpSysEx(void* data);
void GetSysEx(void* data);

void FirmwareInstructions(void* data);
void FirmwareUpgrade(void* data);

/* Play mode disables TimerB2 */
void ControllerMode(void* data);

/* Saves the passed profile into the profileIndex */
void SaveProfile(void* data);
void LoadProfile(void* data);
void ShowProfile(void* data);
void Profile_Error(void);


void SetMIDIRate(void* data);
void EditMIDIRate(void* data);
void PrintMIDIRate(void);


void ChannelSetup(void* data);
void HandleSubMenu(void* data);

void SetThreshold(void* data);
void SetRetrigger(void* data);
void MonitorChannel(void* data);
void SetGainCurves(void* data);

void lcdProgressBar(uint16_t progress, uint16_t maxprogress, uint8_t length);
void LCD_Load_ProgressBar(void);
void SetDualInput(void* data);


void ChangeChannelCode(void* data);


/** Function to setup each individual digial channel */
void DigitalChannelSettings(void* data);
void SetSwitchType(void* data);


/** Keypad setups */
void KeypadButtonSettings(void* data);


/* Amplifer Input Select */
void AmpInputSelect(void* data);
void SensorInputChange(void* data);
void AdjustCrosstalk(void* data);

/* VU Meter */
void VUMeterSetup(void* data);
//void DigitalVUMeterSetup(void* data);

#endif
