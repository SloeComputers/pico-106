#-------------------------------------------------------------------------------
# Copyright (c) 2024 John D. Haughton
# SPDX-License-Identifier: MIT
#-------------------------------------------------------------------------------

import math
import table

#------------------------------------------------------------------------------
# 16-bit (Q4.12) => 24-bit 2^x table

table.gen('exp_24',
          func       = lambda i,x : int(math.pow(2.0, i / 4096) * 256 + 0.5),
          typename   = 'uint32_t',
          log2_size  = 16,
          fmt        = '06x')
