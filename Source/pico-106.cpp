//-------------------------------------------------------------------------------
// Copyright (c) 2024 John D. Haughton
// SPDX-License-Identifier: MIT
//-------------------------------------------------------------------------------

// \brief Synth for Raspberry Pi Pico (based around DCOs like the Juno 106)

#include <cstdio>

#include "Hardware/picoX7/Config.h"
#include "Hardware/FilePortal.h"

#include "Synth.h"
#include "Voice.h"


static const unsigned NUM_VOICES = 3;    //!< Number of external DCO circuits, max 6
static const bool     MIDI_DEBUG = true;


static hw::FilePortal file_portal{"pico-106",
                                  "https://github.com/AnotherJohnH/pico-106"};
static Synth<NUM_VOICES> synth{};

// --- Physical MIDI -----------------------------------------------------------

static hw::PhysMidi phys_midi{};


// --- USB MIDI ----------------------------------------------------------------

static hw::UsbFileMidi usb{0x91C0, "picoChippy", file_portal};

extern "C" void IRQ_USBCTRL() { usb.irq(); }


// --- LED ---------------------------------------------------------------------

static hw::Led led{};


int main()
{
   // Clear screen and cursor to home
   printf("\e[2J");
   printf("\e[1,1H");

   printf("\n");
   puts(file_portal.addREADME("pico-106"));
   printf("\n");

   phys_midi.setDebug(MIDI_DEBUG);
   phys_midi.attachInstrument(1, synth);

   usb.setDebug(MIDI_DEBUG);
   usb.attachInstrument(1, synth);

   while(true)
   {
      phys_midi.tick();
      usb.tick();

      led = synth.isAnyVoiceOn();
   }

   return 0;
}
