/*

Copyright (c) 2011 Adrian Gin (adrian.gin[at]gmail.com)

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.

*/

#include "Profiles/profiles.h"
#include "MIDICodes/MIDICodes.h"
#include "Sample/analogueSample.h"

#include <stdint.h>

Profile_t Profile0 PROFILE_LOCATION(START)  = { 
/* MIDISettings_t */
{
   /* 15ms output rate */
   DEFAULT_OUTPUT_RATE,
   DEFAULT_BAUD_RATE,
   /* MIDI Channel Instrument # */
   (DEFAULT_MIDI_CHANNEL)
},
/* Channel Settings */
{
   /* Channel Status */
   {0xFF, 0x1F, 0x03, 0x00, 0x00},

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
    MIDI_NOTE_ON, MIDI_NOTE_ON, MIDI_NOTE_ON, MIDI_NOTE_ON,

    /* Keypad MIDI output codes */
//  MIDI_CONTROL_CHANGE, MIDI_CONTROL_CHANGE, MIDI_CONTROL_CHANGE, MIDI_CONTROL_CHANGE,
//  MIDI_CONTROL_CHANGE, MIDI_CONTROL_CHANGE, MIDI_CONTROL_CHANGE, MIDI_CONTROL_CHANGE,
//  MIDI_CONTROL_CHANGE, MIDI_CONTROL_CHANGE, MIDI_CONTROL_CHANGE, MIDI_CONTROL_CHANGE,
//  MIDI_CONTROL_CHANGE, MIDI_CONTROL_CHANGE, MIDI_CONTROL_CHANGE, MIDI_CONTROL_CHANGE
      },


   /* Default Open Keys*/
//Analogue Inputs
   {OPEN_HIGH_HAT, LONG_WHISTLE, ELECTRIC_SNARE, SIDE_STICK,
    HI_MID_TOM, LOW_TOM , LOW_FLOOR_TOM, CRASH_CYMBAL1,
    CRASH_CYMBAL2, SPLASH_CYMBAL, RIDE_CYMBAL2, RIDE_CYMBAL1,
    RIDE_BELL, NO_ITEM, NO_ITEM, NO_ITEM,
//Digital inputs     
    PEDAL_HIGH_HAT, BASS_DRUM1, ACOUSTIC_BASS_DRUM, NO_ITEM, 
    NO_ITEM, NO_ITEM, NO_ITEM, NO_ITEM,

//Metronome inputs 
    BASS_DRUM1, CLOSED_HI_HAT, MUTE_TRIANGLE, ELECTRIC_SNARE,
    RIDE_CYMBAL1, ACOUSTIC_BASS_DRUM, OPEN_TRIANGLE, SIDE_STICK,
//Keypad Inputs
//  REVERB_LEVEL, TREMOLO_LEVEL, CHORUS_LEVEL, CELESTE_LEVEL,
//    GENERAL_PURPOSE_BUTTON1, GENERAL_PURPOSE_BUTTON2, GENERAL_PURPOSE_BUTTON3, GENERAL_PURPOSE_BUTTON4,
//    GENERAL_PURPOSE_BUTTON5, GENERAL_PURPOSE_BUTTON6, GENERAL_PURPOSE_BUTTON7, GENERAL_PURPOSE_BUTTON8,
//    ALL_SOUND_OFF, HOLD_PEDAL_TOGGLE, PORTAMENTO_TOGGLE, LEGATO_PEDAL_TOGGLE},
   },
   
            
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
    {0x03, 0x00, 0x00, 0x00, 0x00},

    /* The Alternate Trigger */
    {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
     0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
     0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
     0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},

   /* Default Closed Keys*/
   {CLOSED_HI_HAT,   SHORT_WHISTLE,    NO_ITEM,       RIDE_CYMBAL2,
    HIGH_FLOOR_TOM,  LOW_FLOOR_TOM,    LOW_MID_TOM,   LOW_TOM,
    NO_ITEM,         NO_ITEM,          CRASH_CYMBAL2, NO_ITEM,
    NO_ITEM,         NO_ITEM,          NO_ITEM,       NO_ITEM,
   /* Digital Closed Keys */ 
    NO_ITEM,         NO_ITEM,          NO_ITEM,       NO_ITEM,
    NO_ITEM,         NO_ITEM,          NO_ITEM,       NO_ITEM,
   /* Metronome Closed Keys */ 
    NO_ITEM,         NO_ITEM,          NO_ITEM,       NO_ITEM,
    NO_ITEM,         NO_ITEM,          NO_ITEM,       NO_ITEM},


  /* Analogue Channel Closed  MIDI output Codes */
   {MIDI_NOTE_ON, MIDI_NOTE_ON, MIDI_NOTE_ON, MIDI_NOTE_ON,
    MIDI_NOTE_ON, MIDI_NOTE_ON, MIDI_NOTE_ON, MIDI_NOTE_ON,
    MIDI_NOTE_ON, MIDI_NOTE_ON, MIDI_NOTE_ON, MIDI_NOTE_ON,
    MIDI_NOTE_ON, MIDI_NOTE_ON, MIDI_NOTE_ON, MIDI_NOTE_ON,

    /* Digital Channel Closed MIDI output Codes */
    MIDI_NOTE_ON, MIDI_NOTE_ON, MIDI_NOTE_ON, MIDI_NOTE_ON,
    MIDI_NOTE_ON, MIDI_NOTE_ON, MIDI_NOTE_ON, MIDI_NOTE_ON,

    /* Metronome Channel Closed MIDI output Codes */
    MIDI_NOTE_ON, MIDI_NOTE_ON, MIDI_NOTE_ON, MIDI_NOTE_ON,
    MIDI_NOTE_ON, MIDI_NOTE_ON, MIDI_NOTE_ON, MIDI_NOTE_ON,
   }


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
    {0x03, 0x00},
},

/* Digital Channel Settings */
{

   /* Hit Velocities */
   {DEFAULT_VELOCITY, DEFAULT_VELOCITY, DEFAULT_VELOCITY, DEFAULT_VELOCITY,
    DEFAULT_VELOCITY, DEFAULT_VELOCITY, DEFAULT_VELOCITY, DEFAULT_VELOCITY,
    DEFAULT_VELOCITY, DEFAULT_VELOCITY, DEFAULT_VELOCITY, DEFAULT_VELOCITY,
    DEFAULT_VELOCITY, DEFAULT_VELOCITY, DEFAULT_VELOCITY, DEFAULT_VELOCITY,
//    DEFAULT_VELOCITY, DEFAULT_VELOCITY, DEFAULT_VELOCITY, DEFAULT_VELOCITY,
//    DEFAULT_VELOCITY, DEFAULT_VELOCITY, DEFAULT_VELOCITY, DEFAULT_VELOCITY,
//    DEFAULT_VELOCITY, DEFAULT_VELOCITY, DEFAULT_VELOCITY, DEFAULT_VELOCITY,
//    DEFAULT_VELOCITY, DEFAULT_VELOCITY, DEFAULT_VELOCITY, DEFAULT_VELOCITY
    },
    
   /* All swtiches are Active low type */
    {0x00, 0x00},
   
   /* All switches use single shot triggering */
    {0x00, 0x00},

   /* All switches to have no release effect */
    {0x00, 0x00},
},

/* Sensor Settings */
{ ADC_CHANNEL(DEFAULT_ADC_CHANNEL), DEFAULT_CROSSTALK }

};


#if NUMBER_OF_PROFILES > 1
Profile_t Profile1 PROFILE_LOCATION(START) = { 
      /* MIDISettings_t */
      {
         /* 15ms output rate */
         DEFAULT_OUTPUT_RATE,
         DEFAULT_BAUD_RATE,
         /* MIDI Channel Instrument # */
         (DEFAULT_MIDI_CHANNEL)
      },
      /* Channel Settings */
      {
         /* Channel Status */
         {0xFF, 0x1F, 0x03, 0x00, 0x00},

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
          MIDI_NOTE_ON, MIDI_NOTE_ON, MIDI_NOTE_ON, MIDI_NOTE_ON,

          /* Keypad MIDI output codes */
      //  MIDI_CONTROL_CHANGE, MIDI_CONTROL_CHANGE, MIDI_CONTROL_CHANGE, MIDI_CONTROL_CHANGE,
      //  MIDI_CONTROL_CHANGE, MIDI_CONTROL_CHANGE, MIDI_CONTROL_CHANGE, MIDI_CONTROL_CHANGE,
      //  MIDI_CONTROL_CHANGE, MIDI_CONTROL_CHANGE, MIDI_CONTROL_CHANGE, MIDI_CONTROL_CHANGE,
      //  MIDI_CONTROL_CHANGE, MIDI_CONTROL_CHANGE, MIDI_CONTROL_CHANGE, MIDI_CONTROL_CHANGE
            },


         /* Default Open Keys*/
      //Analogue Inputs
         {OPEN_HIGH_HAT, LONG_WHISTLE, ELECTRIC_SNARE, SIDE_STICK,
          HI_MID_TOM, LOW_TOM , LOW_FLOOR_TOM, CRASH_CYMBAL1,
          CRASH_CYMBAL2, SPLASH_CYMBAL, RIDE_CYMBAL2, RIDE_CYMBAL1,
          RIDE_BELL, NO_ITEM, NO_ITEM, NO_ITEM,
      //Digital inputs
          PEDAL_HIGH_HAT, BASS_DRUM1, ACOUSTIC_BASS_DRUM, NO_ITEM,
          NO_ITEM, NO_ITEM, NO_ITEM, NO_ITEM,

      //Metronome inputs
          BASS_DRUM1, CLOSED_HI_HAT, MUTE_TRIANGLE, ELECTRIC_SNARE,
          RIDE_CYMBAL1, ACOUSTIC_BASS_DRUM, OPEN_TRIANGLE, SIDE_STICK,
      //Keypad Inputs
      //  REVERB_LEVEL, TREMOLO_LEVEL, CHORUS_LEVEL, CELESTE_LEVEL,
      //    GENERAL_PURPOSE_BUTTON1, GENERAL_PURPOSE_BUTTON2, GENERAL_PURPOSE_BUTTON3, GENERAL_PURPOSE_BUTTON4,
      //    GENERAL_PURPOSE_BUTTON5, GENERAL_PURPOSE_BUTTON6, GENERAL_PURPOSE_BUTTON7, GENERAL_PURPOSE_BUTTON8,
      //    ALL_SOUND_OFF, HOLD_PEDAL_TOGGLE, PORTAMENTO_TOGGLE, LEGATO_PEDAL_TOGGLE},
         },


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
          {0x03, 0x00, 0x00, 0x00, 0x00},

          /* The Digital Trigger */
          {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
           0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
           0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
           0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},

         /* Default Closed Keys*/
         {CLOSED_HI_HAT,   SHORT_WHISTLE,    NO_ITEM,       RIDE_CYMBAL2,
          HIGH_FLOOR_TOM,  LOW_FLOOR_TOM,    LOW_MID_TOM,   LOW_TOM,
          NO_ITEM,         NO_ITEM,          CRASH_CYMBAL2, NO_ITEM,
          NO_ITEM,         NO_ITEM,          NO_ITEM,       NO_ITEM,
         /* Digital Closed Keys */
          NO_ITEM,         NO_ITEM,          NO_ITEM,       NO_ITEM,
          NO_ITEM,         NO_ITEM,          NO_ITEM,       NO_ITEM,
         /* Metronome Closed Keys */
          NO_ITEM,         NO_ITEM,          NO_ITEM,       NO_ITEM,
          NO_ITEM,         NO_ITEM,          NO_ITEM,       NO_ITEM},


        /* Analogue Channel Closed  MIDI output Codes */
         {MIDI_NOTE_ON, MIDI_NOTE_ON, MIDI_NOTE_ON, MIDI_NOTE_ON,
          MIDI_NOTE_ON, MIDI_NOTE_ON, MIDI_NOTE_ON, MIDI_NOTE_ON,
          MIDI_NOTE_ON, MIDI_NOTE_ON, MIDI_NOTE_ON, MIDI_NOTE_ON,
          MIDI_NOTE_ON, MIDI_NOTE_ON, MIDI_NOTE_ON, MIDI_NOTE_ON,

          /* Digital Channel Closed MIDI output Codes */
          MIDI_NOTE_ON, MIDI_NOTE_ON, MIDI_NOTE_ON, MIDI_NOTE_ON,
          MIDI_NOTE_ON, MIDI_NOTE_ON, MIDI_NOTE_ON, MIDI_NOTE_ON,

          /* Metronome Channel Closed MIDI output Codes */
          MIDI_NOTE_ON, MIDI_NOTE_ON, MIDI_NOTE_ON, MIDI_NOTE_ON,
          MIDI_NOTE_ON, MIDI_NOTE_ON, MIDI_NOTE_ON, MIDI_NOTE_ON,
         }


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
          {0x03, 0x00},
      },

      /* Digital Channel Settings */
      {

         /* Hit Velocities */
         {DEFAULT_VELOCITY, DEFAULT_VELOCITY, DEFAULT_VELOCITY, DEFAULT_VELOCITY,
          DEFAULT_VELOCITY, DEFAULT_VELOCITY, DEFAULT_VELOCITY, DEFAULT_VELOCITY,
          DEFAULT_VELOCITY, DEFAULT_VELOCITY, DEFAULT_VELOCITY, DEFAULT_VELOCITY,
          DEFAULT_VELOCITY, DEFAULT_VELOCITY, DEFAULT_VELOCITY, DEFAULT_VELOCITY,
      //    DEFAULT_VELOCITY, DEFAULT_VELOCITY, DEFAULT_VELOCITY, DEFAULT_VELOCITY,
      //    DEFAULT_VELOCITY, DEFAULT_VELOCITY, DEFAULT_VELOCITY, DEFAULT_VELOCITY,
      //    DEFAULT_VELOCITY, DEFAULT_VELOCITY, DEFAULT_VELOCITY, DEFAULT_VELOCITY,
      //    DEFAULT_VELOCITY, DEFAULT_VELOCITY, DEFAULT_VELOCITY, DEFAULT_VELOCITY
          },

         /* All swtiches are Active low type */
          {0x00, 0x00},

          /* All switches use single shot triggering */
           {0x00, 0x00},

          /* All switches to have no release effect */
           {0x00, 0x00},
      },

      /* Sensor Settings */
      { ADC_CHANNEL(DEFAULT_ADC_CHANNEL), DEFAULT_CROSSTALK }

};
#endif

#if NUMBER_OF_PROFILES > 2
Profile_t Profile2 PROFILE_LOCATION(START) = { 
      /* MIDISettings_t */
      {
         /* 15ms output rate */
         DEFAULT_OUTPUT_RATE,
         DEFAULT_BAUD_RATE,
         /* MIDI Channel Instrument # */
         (DEFAULT_MIDI_CHANNEL)
      },
      /* Channel Settings */
      {
         /* Channel Status */
         {0xFF, 0x1F, 0x03, 0x00, 0x00},

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
          MIDI_NOTE_ON, MIDI_NOTE_ON, MIDI_NOTE_ON, MIDI_NOTE_ON,

          /* Keypad MIDI output codes */
      //  MIDI_CONTROL_CHANGE, MIDI_CONTROL_CHANGE, MIDI_CONTROL_CHANGE, MIDI_CONTROL_CHANGE,
      //  MIDI_CONTROL_CHANGE, MIDI_CONTROL_CHANGE, MIDI_CONTROL_CHANGE, MIDI_CONTROL_CHANGE,
      //  MIDI_CONTROL_CHANGE, MIDI_CONTROL_CHANGE, MIDI_CONTROL_CHANGE, MIDI_CONTROL_CHANGE,
      //  MIDI_CONTROL_CHANGE, MIDI_CONTROL_CHANGE, MIDI_CONTROL_CHANGE, MIDI_CONTROL_CHANGE
            },


         /* Default Open Keys*/
      //Analogue Inputs
         {OPEN_HIGH_HAT, LONG_WHISTLE, ELECTRIC_SNARE, SIDE_STICK,
          HI_MID_TOM, LOW_TOM , LOW_FLOOR_TOM, CRASH_CYMBAL1,
          CRASH_CYMBAL2, SPLASH_CYMBAL, RIDE_CYMBAL2, RIDE_CYMBAL1,
          RIDE_BELL, NO_ITEM, NO_ITEM, NO_ITEM,
      //Digital inputs
          PEDAL_HIGH_HAT, BASS_DRUM1, ACOUSTIC_BASS_DRUM, NO_ITEM,
          NO_ITEM, NO_ITEM, NO_ITEM, NO_ITEM,

      //Metronome inputs
          BASS_DRUM1, CLOSED_HI_HAT, MUTE_TRIANGLE, ELECTRIC_SNARE,
          RIDE_CYMBAL1, ACOUSTIC_BASS_DRUM, OPEN_TRIANGLE, SIDE_STICK,
      //Keypad Inputs
      //  REVERB_LEVEL, TREMOLO_LEVEL, CHORUS_LEVEL, CELESTE_LEVEL,
      //    GENERAL_PURPOSE_BUTTON1, GENERAL_PURPOSE_BUTTON2, GENERAL_PURPOSE_BUTTON3, GENERAL_PURPOSE_BUTTON4,
      //    GENERAL_PURPOSE_BUTTON5, GENERAL_PURPOSE_BUTTON6, GENERAL_PURPOSE_BUTTON7, GENERAL_PURPOSE_BUTTON8,
      //    ALL_SOUND_OFF, HOLD_PEDAL_TOGGLE, PORTAMENTO_TOGGLE, LEGATO_PEDAL_TOGGLE},
         },


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
          {0x03, 0x00, 0x00, 0x00, 0x00},

          /* The Digital Trigger */
          {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
           0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
           0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
           0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},

         /* Default Closed Keys*/
         {CLOSED_HI_HAT,   SHORT_WHISTLE,    NO_ITEM,       RIDE_CYMBAL2,
          HIGH_FLOOR_TOM,  LOW_FLOOR_TOM,    LOW_MID_TOM,   LOW_TOM,
          NO_ITEM,         NO_ITEM,          CRASH_CYMBAL2, NO_ITEM,
          NO_ITEM,         NO_ITEM,          NO_ITEM,       NO_ITEM,
         /* Digital Closed Keys */
          NO_ITEM,         NO_ITEM,          NO_ITEM,       NO_ITEM,
          NO_ITEM,         NO_ITEM,          NO_ITEM,       NO_ITEM,
         /* Metronome Closed Keys */
          NO_ITEM,         NO_ITEM,          NO_ITEM,       NO_ITEM,
          NO_ITEM,         NO_ITEM,          NO_ITEM,       NO_ITEM},


        /* Analogue Channel Closed  MIDI output Codes */
         {MIDI_NOTE_ON, MIDI_NOTE_ON, MIDI_NOTE_ON, MIDI_NOTE_ON,
          MIDI_NOTE_ON, MIDI_NOTE_ON, MIDI_NOTE_ON, MIDI_NOTE_ON,
          MIDI_NOTE_ON, MIDI_NOTE_ON, MIDI_NOTE_ON, MIDI_NOTE_ON,
          MIDI_NOTE_ON, MIDI_NOTE_ON, MIDI_NOTE_ON, MIDI_NOTE_ON,

          /* Digital Channel Closed MIDI output Codes */
          MIDI_NOTE_ON, MIDI_NOTE_ON, MIDI_NOTE_ON, MIDI_NOTE_ON,
          MIDI_NOTE_ON, MIDI_NOTE_ON, MIDI_NOTE_ON, MIDI_NOTE_ON,

          /* Metronome Channel Closed MIDI output Codes */
          MIDI_NOTE_ON, MIDI_NOTE_ON, MIDI_NOTE_ON, MIDI_NOTE_ON,
          MIDI_NOTE_ON, MIDI_NOTE_ON, MIDI_NOTE_ON, MIDI_NOTE_ON,
         }


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
          {0x03, 0x00},
      },

      /* Digital Channel Settings */
      {

         /* Hit Velocities */
         {DEFAULT_VELOCITY, DEFAULT_VELOCITY, DEFAULT_VELOCITY, DEFAULT_VELOCITY,
          DEFAULT_VELOCITY, DEFAULT_VELOCITY, DEFAULT_VELOCITY, DEFAULT_VELOCITY,
          DEFAULT_VELOCITY, DEFAULT_VELOCITY, DEFAULT_VELOCITY, DEFAULT_VELOCITY,
          DEFAULT_VELOCITY, DEFAULT_VELOCITY, DEFAULT_VELOCITY, DEFAULT_VELOCITY,
      //    DEFAULT_VELOCITY, DEFAULT_VELOCITY, DEFAULT_VELOCITY, DEFAULT_VELOCITY,
      //    DEFAULT_VELOCITY, DEFAULT_VELOCITY, DEFAULT_VELOCITY, DEFAULT_VELOCITY,
      //    DEFAULT_VELOCITY, DEFAULT_VELOCITY, DEFAULT_VELOCITY, DEFAULT_VELOCITY,
      //    DEFAULT_VELOCITY, DEFAULT_VELOCITY, DEFAULT_VELOCITY, DEFAULT_VELOCITY
          },

          /* All switches use single shot triggering */
           {0x00, 0x00},

           /* All switches use single shot triggering */
            {0x00, 0x00},

           /* All switches to have no release effect */
            {0x00, 0x00},
      },

      /* Sensor Settings */
      { ADC_CHANNEL(DEFAULT_ADC_CHANNEL), DEFAULT_CROSSTALK }

      };
#endif


#if NUMBER_OF_PROFILES > 3
Profile_t Profile3 PROFILE_LOCATION(START) = { 
      /* MIDISettings_t */
      {
         /* 15ms output rate */
         DEFAULT_OUTPUT_RATE,
         DEFAULT_BAUD_RATE,
         /* MIDI Channel Instrument # */
         (DEFAULT_MIDI_CHANNEL)
      },
      /* Channel Settings */
      {
         /* Channel Status */
         {0xFF, 0x1F, 0x03, 0x00, 0x00},

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
          MIDI_NOTE_ON, MIDI_NOTE_ON, MIDI_NOTE_ON, MIDI_NOTE_ON,

          /* Keypad MIDI output codes */
      //  MIDI_CONTROL_CHANGE, MIDI_CONTROL_CHANGE, MIDI_CONTROL_CHANGE, MIDI_CONTROL_CHANGE,
      //  MIDI_CONTROL_CHANGE, MIDI_CONTROL_CHANGE, MIDI_CONTROL_CHANGE, MIDI_CONTROL_CHANGE,
      //  MIDI_CONTROL_CHANGE, MIDI_CONTROL_CHANGE, MIDI_CONTROL_CHANGE, MIDI_CONTROL_CHANGE,
      //  MIDI_CONTROL_CHANGE, MIDI_CONTROL_CHANGE, MIDI_CONTROL_CHANGE, MIDI_CONTROL_CHANGE
            },


         /* Default Open Keys*/
      //Analogue Inputs
         {OPEN_HIGH_HAT, LONG_WHISTLE, ELECTRIC_SNARE, SIDE_STICK,
          HI_MID_TOM, LOW_TOM , LOW_FLOOR_TOM, CRASH_CYMBAL1,
          CRASH_CYMBAL2, SPLASH_CYMBAL, RIDE_CYMBAL2, RIDE_CYMBAL1,
          RIDE_BELL, NO_ITEM, NO_ITEM, NO_ITEM,
      //Digital inputs
          PEDAL_HIGH_HAT, BASS_DRUM1, ACOUSTIC_BASS_DRUM, NO_ITEM,
          NO_ITEM, NO_ITEM, NO_ITEM, NO_ITEM,

      //Metronome inputs
          BASS_DRUM1, CLOSED_HI_HAT, MUTE_TRIANGLE, ELECTRIC_SNARE,
          RIDE_CYMBAL1, ACOUSTIC_BASS_DRUM, OPEN_TRIANGLE, SIDE_STICK,
      //Keypad Inputs
      //  REVERB_LEVEL, TREMOLO_LEVEL, CHORUS_LEVEL, CELESTE_LEVEL,
      //    GENERAL_PURPOSE_BUTTON1, GENERAL_PURPOSE_BUTTON2, GENERAL_PURPOSE_BUTTON3, GENERAL_PURPOSE_BUTTON4,
      //    GENERAL_PURPOSE_BUTTON5, GENERAL_PURPOSE_BUTTON6, GENERAL_PURPOSE_BUTTON7, GENERAL_PURPOSE_BUTTON8,
      //    ALL_SOUND_OFF, HOLD_PEDAL_TOGGLE, PORTAMENTO_TOGGLE, LEGATO_PEDAL_TOGGLE},
         },


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
          {0x03, 0x00, 0x00, 0x00, 0x00},

          /* The Digital Trigger */
          {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
           0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
           0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
           0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},

         /* Default Closed Keys*/
         {CLOSED_HI_HAT,   SHORT_WHISTLE,    NO_ITEM,       RIDE_CYMBAL2,
          HIGH_FLOOR_TOM,  LOW_FLOOR_TOM,    LOW_MID_TOM,   LOW_TOM,
          NO_ITEM,         NO_ITEM,          CRASH_CYMBAL2, NO_ITEM,
          NO_ITEM,         NO_ITEM,          NO_ITEM,       NO_ITEM,
         /* Digital Closed Keys */
          NO_ITEM,         NO_ITEM,          NO_ITEM,       NO_ITEM,
          NO_ITEM,         NO_ITEM,          NO_ITEM,       NO_ITEM,
         /* Metronome Closed Keys */
          NO_ITEM,         NO_ITEM,          NO_ITEM,       NO_ITEM,
          NO_ITEM,         NO_ITEM,          NO_ITEM,       NO_ITEM},


        /* Analogue Channel Closed  MIDI output Codes */
         {MIDI_NOTE_ON, MIDI_NOTE_ON, MIDI_NOTE_ON, MIDI_NOTE_ON,
          MIDI_NOTE_ON, MIDI_NOTE_ON, MIDI_NOTE_ON, MIDI_NOTE_ON,
          MIDI_NOTE_ON, MIDI_NOTE_ON, MIDI_NOTE_ON, MIDI_NOTE_ON,
          MIDI_NOTE_ON, MIDI_NOTE_ON, MIDI_NOTE_ON, MIDI_NOTE_ON,

          /* Digital Channel Closed MIDI output Codes */
          MIDI_NOTE_ON, MIDI_NOTE_ON, MIDI_NOTE_ON, MIDI_NOTE_ON,
          MIDI_NOTE_ON, MIDI_NOTE_ON, MIDI_NOTE_ON, MIDI_NOTE_ON,

          /* Metronome Channel Closed MIDI output Codes */
          MIDI_NOTE_ON, MIDI_NOTE_ON, MIDI_NOTE_ON, MIDI_NOTE_ON,
          MIDI_NOTE_ON, MIDI_NOTE_ON, MIDI_NOTE_ON, MIDI_NOTE_ON,
         }


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
          {0x03, 0x00},
      },

      /* Digital Channel Settings */
      {

         /* Hit Velocities */
         {DEFAULT_VELOCITY, DEFAULT_VELOCITY, DEFAULT_VELOCITY, DEFAULT_VELOCITY,
          DEFAULT_VELOCITY, DEFAULT_VELOCITY, DEFAULT_VELOCITY, DEFAULT_VELOCITY,
          DEFAULT_VELOCITY, DEFAULT_VELOCITY, DEFAULT_VELOCITY, DEFAULT_VELOCITY,
          DEFAULT_VELOCITY, DEFAULT_VELOCITY, DEFAULT_VELOCITY, DEFAULT_VELOCITY,
      //    DEFAULT_VELOCITY, DEFAULT_VELOCITY, DEFAULT_VELOCITY, DEFAULT_VELOCITY,
      //    DEFAULT_VELOCITY, DEFAULT_VELOCITY, DEFAULT_VELOCITY, DEFAULT_VELOCITY,
      //    DEFAULT_VELOCITY, DEFAULT_VELOCITY, DEFAULT_VELOCITY, DEFAULT_VELOCITY,
      //    DEFAULT_VELOCITY, DEFAULT_VELOCITY, DEFAULT_VELOCITY, DEFAULT_VELOCITY
          },

          /* All switches use single shot triggering */
           {0x00, 0x00},

           /* All switches use single shot triggering */
            {0x00, 0x00},

           /* All switches to have no release effect */
            {0x00, 0x00},
      },

      /* Sensor Settings */
      { ADC_CHANNEL(DEFAULT_ADC_CHANNEL), DEFAULT_CROSSTALK }

      };
#endif
