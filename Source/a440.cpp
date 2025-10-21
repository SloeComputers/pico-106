//-------------------------------------------------------------------------------
// Copyright (c) 2024 John D. Haughton
// SPDX-License-Identifier: MIT
//-------------------------------------------------------------------------------

#include <cstdio>

#include "DCO.h"


// -----------------------------------------------------------------------------

int MTL_main()
{
   DCO_PWM<MTL::Pio0, MTL::PIN_4>  dco1;

   dco1.noteOn(69);

   while(true);

   return 0;
}
