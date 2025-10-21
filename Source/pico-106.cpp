//-------------------------------------------------------------------------------
// Copyright (c) 2024 John D. Haughton
// SPDX-License-Identifier: MIT
//-------------------------------------------------------------------------------

// \brief Synth for Raspberry Pi Pico (based around DCOs like the Juno 106)

#include <cstdio>

#include "Hardware/picoX7/Config.h"

#include "Synth.h"
#include "Voice.h"


static const unsigned NUM_VOICES = 3;    //!< Number of external DCO circuits, max 6
static const bool     MIDI_DEBUG = true;


static Synth<NUM_VOICES> synth{};
static hw::PhysMidi      phys_midi{};
static hw::Led           led{};


#if defined(HW_MIDI_USB_DEVICE)

static hw::MidiUSBDevice midi_usb{synth, 0x9106, "pico-106", MIDI_DEBUG};

extern "C" void IRQ_USBCTRL() { midi_usb.irq(); }

#endif


int main()
{
   // Clear screen and cursor to home
   printf("\e[2J");
   printf("\e[1,1H");

   printf("\n");
   printf("Program  : pico-106 (%u voices)\n", NUM_VOICES);
   printf("Author   : Copyright (c) 2024 John D. Haughton\n");
   printf("License  : MIT\n");
   printf("Version  : %s\n", PLT_VERSION);
   printf("Commit   : %s\n", PLT_COMMIT);
   printf("Built    : %s %s\n", __TIME__, __DATE__);
   printf("Compiler : %s\n", __VERSION__);
   printf("\n");

   phys_midi.setDebug(MIDI_DEBUG);
   phys_midi.attachInstrument(1, synth);

   while(true)
   {
      phys_midi.tick();

#if defined(HW_MIDI_USB_DEVICE)
      midi_usb.tick();
#endif

      led = synth.isAnyVoiceOn();
   }

   return 0;
}
