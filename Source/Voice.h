//-------------------------------------------------------------------------------
// Copyright (c) 2024 John D. Haughton
// SPDX-License-Identifier: MIT
//-------------------------------------------------------------------------------

#pragma once

#include "DCO.h"

class Voice
{
public:
   Voice() = default;

   void setDCO(DCO& dco_)
   {
      dco = &dco_;
   }

   bool isActive() const { return active; }

   bool isPlaying(uint8_t note_) const { return active && (note == note_); }

   void noteOn(uint8_t note_)
   {
      active = true;
      note   = note_;
      dco->noteOn(note_);
   }

   void noteOff()
   {
      active = false;
      dco->noteOff();
   }

private:
   bool    active{false};
   uint8_t note{};
   DCO*    dco{nullptr};
};

