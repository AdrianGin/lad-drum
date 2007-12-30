
#include <stdint.h>
#include <string.h>
#include "Sample/sample.h"
#include "UART/uart.h"
#include "midi.h"
#include "VUMeter/vumeter.h"

#define MIDI_Tx(x)   UART_Tx(x)

const char MIDI_NOTES[] = "C C#D D#E F F#G G#A A#B ";
const char MIDI_BAUD[][8] = {"31.25k",
									  "38.4k",
									  "115.2k"};


MidiSettings_t MIDISettings = {	
	/* 15ms output rate */
	15,
	DEFAULT_BAUD_RATE,
	/* MIDI Channel Instrument # */
	(0x09 | MIDI_NOTE_ON)
};


void MIDI_Output(void)
{
   uint8_t i;
   /* Do digital inputs then do analogue inputs  */
   for( i = 0; i < NUMBER_OF_INPUTS; i++)
   {      
      if( GetChannelStatus(i) && 
          (RetriggerPeriod[i].timerEnable == 0) && 
          (SignalPeak[i] > GetChannelThresh(i)) )
      {
			uint16_t conditionedSignal = (SignalPeak[i] - GetChannelThresh(i));
			
			if ( GetChannelGain(i) > 0 )
			{
				conditionedSignal = conditionedSignal << GetChannelGain(i);
			}
			else
			{
				conditionedSignal = conditionedSignal >> (-GetChannelGain(i));
			}
			
			if( conditionedSignal )
			{
	         /* Send a NOTE ON | Channel */
	         MIDI_Tx(MIDISettings.MIDI_ChannelCode);
	         MIDI_Tx(GetChannelKey(i));
	         if( conditionedSignal > 127 )
	         {
	            MIDI_Tx( 127 );   
	         }
	         else
	         {
	            MIDI_Tx( conditionedSignal );
	         } 
	         SoftTimerStart(RetriggerPeriod[i]);
	         
         	if( SoftTimer2[SC_VUMeterUpdate].timerEnable == 1)
				{
					UpdateVUValues(SignalPeak);
				}	         
	         
			}
      }  
   }
}


void MIDI_FastOutput(void)
{
   uint8_t i;
   for( i = 0; i < NUMBER_OF_INPUTS; i++)
   {      
      if( GetChannelStatus(i) )
      {
   		uint16_t conditionedSignal = (SignalPeak[i] >> GetChannelGain(i));
         /* Send a NOTE ON | Channel */
         MIDI_Tx(MIDISettings.MIDI_ChannelCode);
         MIDI_Tx(GetChannelKey(i));
         if( conditionedSignal > 127 )
         {
            MIDI_Tx( 127 );   
         }
         else
         {
            MIDI_Tx( conditionedSignal );
         } 
      }
   }
}



uint16_t MIDI_GetRate(void)
{
   return MIDISettings.MIDI_OutputRate;
}

void MIDI_SetRate(uint16_t newRate)
{
	MIDISettings.MIDI_OutputRate = newRate;
   SoftTimer1[SC_MIDIOutput].timeCompare = newRate;
}

void MIDI_SetBaud(uint16_t newBaud)
{

   MIDISettings.MIDI_BaudRate = newBaud; 
   UART_SetBaudRate( newBaud >> 8, newBaud & 0xFF );
}


uint16_t MIDI_GetBaud(void)
{
   return MIDISettings.MIDI_BaudRate;
}

uint8_t MIDI_GetChannelCode(void)
{
	return (MIDISettings.MIDI_ChannelCode & 0x0F);
}

void MIDI_SetChannelCode(uint8_t newCode)
{
   if( newCode < 0x0F )
   {
		MIDISettings.MIDI_ChannelCode = MIDI_NOTE_ON | newCode;
   }
}




/* Pass any number from 0->127 and obtain the corresponding note in a string format */
void MIDI_NoteString(uint8_t note, char* buffer)
{
   note = note - (NOTE_COUNT * MIDI_Octave(note));
   strncpy(buffer, &MIDI_NOTES[note*2] , 2);
   /* Append a NULL */
   buffer[2] = '\0';
}

/* Returns the octave of the passed note */
uint8_t MIDI_Octave(uint8_t note)
{
  return (note / NOTE_COUNT);
}





