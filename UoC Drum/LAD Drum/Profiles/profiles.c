
#include <io.h>
#include <mspgcc/flash.h>
#include <string.h>
#include "profiles.h"


Profile_t CurrentProfile = { 
/* MIDISettings_t */
{	
	/* 15ms output rate */
	15,
	DEFAULT_BAUD_RATE,
	/* MIDI Channel Instrument # */
	(0x09 | MIDI_NOTE_ON)
},

/* Channel Settings */
{
	/* Channel Status */
	0x0000000F,
	
	/* Analogue Channel MIDI output Codes */
	{MIDI_NOTE_ON, MIDI_NOTE_ON, MIDI_NOTE_ON, MIDI_NOTE_ON,
	 MIDI_NOTE_ON, MIDI_NOTE_ON, MIDI_NOTE_ON, MIDI_NOTE_ON,
	 MIDI_NOTE_ON, MIDI_NOTE_ON, MIDI_NOTE_ON, MIDI_NOTE_ON,
	 MIDI_NOTE_ON, MIDI_NOTE_ON, MIDI_NOTE_ON, MIDI_NOTE_ON,
	 
	 /* Digital Channel MIDI output Codes */
	 MIDI_NOTE_ON, MIDI_NOTE_ON, MIDI_NOTE_ON, MIDI_NOTE_ON,
	 MIDI_NOTE_ON, MIDI_NOTE_ON, MIDI_NOTE_ON, MIDI_NOTE_ON,
	 
	 /* Metronome Channel MIDI output Codes */
	 MIDI_NOTE_ON, MIDI_NOTE_ON, MIDI_NOTE_ON, MIDI_NOTE_ON,
	 MIDI_NOTE_ON, MIDI_NOTE_ON, MIDI_NOTE_ON, MIDI_NOTE_ON},
	 
	
	/* Default Open Keys*/
//Analogue Inputs	
	{OPEN_HIGH_HAT, ELECTRIC_SNARE, ACOUSTIC_BASS_DRUM, HAND_CLAP,
    LOW_FLOOR_TOM, HIGH_FLOOR_TOM, LOW_TOM, LOW_MID_TOM,
    HI_MID_TOM, HIGH_TOM, CRASH_CYMBAL1, RIDE_CYMBAL1,
    CHINESE_CYMBAL, SPLASH_CYMBAL, HIGH_TIMBALE, CLAVES,
//Digital inputs     
    PEDAL_HIGH_HAT, NO_ITEM, BASS_DRUM1, NO_ITEM, 
    MUTE_HI_CONGA, OPEN_HI_CONGA, LOW_CONGA, LOW_TIMBALE,

//Metronome inputs 
    BASS_DRUM1, CLOSED_HI_HAT, MUTE_TRIANGLE, ELECTRIC_SNARE,
    RIDE_CYMBAL1, ACOUSTIC_BASS_DRUM, OPEN_TRIANGLE, SIDE_STICK},
   
            
	/* Default Thresholds */
	{DEFAULT_THRESHOLD, DEFAULT_THRESHOLD, DEFAULT_THRESHOLD, DEFAULT_THRESHOLD, 
	 DEFAULT_THRESHOLD, DEFAULT_THRESHOLD, DEFAULT_THRESHOLD, DEFAULT_THRESHOLD,
	 DEFAULT_THRESHOLD, DEFAULT_THRESHOLD, DEFAULT_THRESHOLD, DEFAULT_THRESHOLD,
	 DEFAULT_THRESHOLD, DEFAULT_THRESHOLD, DEFAULT_THRESHOLD, DEFAULT_THRESHOLD},
	 
	{DEFAULT_RETRIGGER, DEFAULT_RETRIGGER, DEFAULT_RETRIGGER, DEFAULT_RETRIGGER,
	 DEFAULT_RETRIGGER, DEFAULT_RETRIGGER, DEFAULT_RETRIGGER, DEFAULT_RETRIGGER,
	 DEFAULT_RETRIGGER, DEFAULT_RETRIGGER, DEFAULT_RETRIGGER, DEFAULT_RETRIGGER,
	 DEFAULT_RETRIGGER, DEFAULT_RETRIGGER, DEFAULT_RETRIGGER, DEFAULT_RETRIGGER,
 	 DEFAULT_RETRIGGER, DEFAULT_RETRIGGER, DEFAULT_RETRIGGER, DEFAULT_RETRIGGER,
	 DEFAULT_RETRIGGER, DEFAULT_RETRIGGER, DEFAULT_RETRIGGER, DEFAULT_RETRIGGER,
  	 DEFAULT_RETRIGGER, DEFAULT_RETRIGGER, DEFAULT_RETRIGGER, DEFAULT_RETRIGGER,
	 DEFAULT_RETRIGGER, DEFAULT_RETRIGGER, DEFAULT_RETRIGGER, DEFAULT_RETRIGGER},
	 
	 /* Has Dual Input */
	 0x0000,
	 
	 /* The Digital Trigger */
	 {0x00000000,
	  0x00000000},
	  
	/* Default Closed Keys*/
	{CLOSED_HI_HAT, SIDE_STICK, NO_ITEM, RIDE_CYMBAL2,
    HIGH_FLOOR_TOM, LOW_FLOOR_TOM, LOW_MID_TOM, LOW_TOM,
    NO_ITEM, NO_ITEM, CRASH_CYMBAL2, NO_ITEM,
    NO_ITEM, NO_ITEM, NO_ITEM, NO_ITEM}
},

/* Gain Settings */
{
	/* Default Gains */                                     
	{DEFAULT_GAIN,DEFAULT_GAIN,DEFAULT_GAIN,DEFAULT_GAIN,
    DEFAULT_GAIN,DEFAULT_GAIN,DEFAULT_GAIN,DEFAULT_GAIN,
    DEFAULT_GAIN,DEFAULT_GAIN,DEFAULT_GAIN,DEFAULT_GAIN,
    DEFAULT_GAIN,DEFAULT_GAIN,DEFAULT_GAIN,DEFAULT_GAIN},
    
	/* Default 2nd Slope Gains */                                     
	{DEFAULT_GAIN,DEFAULT_GAIN,DEFAULT_GAIN,DEFAULT_GAIN,
    DEFAULT_GAIN,DEFAULT_GAIN,DEFAULT_GAIN,DEFAULT_GAIN,
    DEFAULT_GAIN,DEFAULT_GAIN,DEFAULT_GAIN,DEFAULT_GAIN,
    DEFAULT_GAIN,DEFAULT_GAIN,DEFAULT_GAIN,DEFAULT_GAIN},
	 
	/* Crossover Level */                                     
	{300,300,300,300,
    300,300,300,300,
    300,300,300,300,
    300,300,300,300},
	 
	 /* Gain Type (Linear or Non Linear) */
	 0x0000
},

/* Digital Channel Settings */
{

	/* Hit Velocities */
	{DEFAULT_VELOCITY, DEFAULT_VELOCITY, DEFAULT_VELOCITY, DEFAULT_VELOCITY,
    DEFAULT_VELOCITY, DEFAULT_VELOCITY, DEFAULT_VELOCITY, DEFAULT_VELOCITY,
    DEFAULT_VELOCITY, DEFAULT_VELOCITY, DEFAULT_VELOCITY, DEFAULT_VELOCITY,
    DEFAULT_VELOCITY, DEFAULT_VELOCITY, DEFAULT_VELOCITY, DEFAULT_VELOCITY},
    
   /* All swtiches are Active low type */
   0x00,
   
   /* All switches use single shot triggering */
   0x00
},



/* Sensor Settings */
{ SENSOR_OUTPUT2, DEFAULT_CROSSTALK }

};


/* Sets up the clock with MCLK*/
void ProfileInit(void)
{
   /* Divide 8MHZ by 20 as clk range must be within 257 -> 457kHz*/
   FCTL2 = FWKEY | FSSEL_MCLK | 0x1F;
   
   MIDISettings = &CurrentProfile.midiSettings;
   ChannelSettings = &CurrentProfile.channelSettings;
   DigitalSettings = &CurrentProfile.digitalSettings;
   GainSettings = &CurrentProfile.gainSettings;
   SensorSettings = &CurrentProfile.sensorSettings;
   /* Setup profile pointer */
   /*CurrentProfile.channelSettings = &ChannelSettings;
   CurrentProfile.midiSettings = &MIDISettings;
   CurrentProfile.digitalSettings = &DigitalSettings;	
   CurrentProfile.sensorSettings = &SensorSettings;
   CurrentProfile.gainSettings = &GainSettings;*/
   
}


void Profile_Copy(void)
{
   uint16_t i;
   for( i = 0 ; i < SEGMENTS_TO_USE; i++ )
   {
      flash_erase_segment( (uint16_t*)PROFILE_IMAGE_ADDRESS(i)); 
      
      flash_write((uint16_t*)PROFILE_IMAGE_ADDRESS(i), 
                  (uint16_t*)PROFILE_FLASH_ADDRESS(i), 
                   FLASH_BLOCK_SIZE);        
   }				  					             
}


/* Writes profile data to the profile Index,
   Profile Index (0 -> 3) */
void Profile_Write(Profile_t* profile, uint8_t profileIndex)
{
   uint16_t i;
   
   Profile_Copy();   
   for( i = 0 ; i < SEGMENTS_TO_USE; i++ )
   {
      flash_erase_segment( (uint16_t*)PROFILE_FLASH_ADDRESS(i));
   }	   

   for( i = 0; i < NUMBER_OF_PROFILES; i++ )
   {
      if( i == profileIndex )
      {
			
         flash_write((uint16_t*)(PROFILE(i)), 
                     profile, 
                     sizeof(Profile_t));
				      
      }
      else
      {
         flash_write((uint16_t*)(PROFILE(i)), 
                     (uint16_t*)(IMAGE_PROFILE(i)), 
                     sizeof(Profile_t));
                   
      }
   }
}

/* Reads the passed profileIndex into the settings */
void Profile_Read(uint8_t profileIndex)
{
	memcpy((uint16_t*)&CurrentProfile,
		    (uint16_t*)PROFILE(profileIndex), sizeof(Profile_t));
			 	  		 
}
