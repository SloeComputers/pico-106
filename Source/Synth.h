//-------------------------------------------------------------------------------
// Copyright (c) 2024 John D. Haughton
// SPDX-License-Identifier: MIT
//-------------------------------------------------------------------------------

#pragma once

#include "STB/MIDIInstrument.h"

#include "DCO.h"
#include "Voice.h"


template <unsigned NUM_VOICES>
class Synth : public MIDI::Instrument
{
public:
   Synth()
      : MIDI::Instrument(NUM_VOICES)
   {
      voice[0].setDCO(dco1);
      voice[1].setDCO(dco2);
      voice[2].setDCO(dco3);
      voice[3].setDCO(dco4);
      voice[4].setDCO(dco5);
      voice[5].setDCO(dco6);
   }

private:
   void voiceOn(unsigned index_, uint8_t note_, uint8_t velocity_) override
   {
      voice[index_].noteOn(note_);
   }

   void voiceOff(unsigned index_, uint8_t velocity_) override
   {
      voice[index_].noteOff();
   }

   // Provision for 6 DCOs
   static const unsigned MAX_VOICES = 6;

   Voice voice[MAX_VOICES];

   DCO_PWM<MTL::Pio0, MTL::IO_PIN_2>  dco1;
   DCO_PWM<MTL::Pio0, MTL::IO_PIN_4>  dco2;
   DCO_PWM<MTL::Pio0, MTL::IO_PIN_6>  dco3;
   DCO_PWM<MTL::Pio1, MTL::IO_PIN_8>  dco4;
   DCO_PWM<MTL::Pio1, MTL::IO_PIN_10> dco5;
   DCO_PWM<MTL::Pio1, MTL::IO_PIN_12> dco6;
};
