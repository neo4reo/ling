/* write-le64.c */

/* nettle, low-level cryptographics library
 *
 * Copyright (C) 2001, 2011, 2012 Niels Möller
 *  
 * The nettle library is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation; either version 2.1 of the License, or (at your
 * option) any later version.
 *
 * The nettle library is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
 * or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public
 * License for more details.
 * 
 * You should have received a copy of the GNU Lesser General Public License
 * along with the nettle library; see the file COPYING.LIB.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02111-1301, USA.
 */

#if HAVE_CONFIG_H
# include "config.h"
#endif

#include "nettle-write.h"

#include "macros.h"

void
_nettle_write_le64(unsigned length, uint8_t *dst,
		   uint64_t *src)
{
  unsigned i;
  unsigned words;
  unsigned leftover;
  
  words = length / 8;
  leftover = length % 8;

  for (i = 0; i < words; i++, dst += 8)
    LE_WRITE_UINT64(dst, src[i]);

  if (leftover)
    {
      uint64_t word;
      
      word = src[i];

      do
	{
	  *dst++ = word & 0xff;
	  word >>= 8;
	}
      while (--leftover);
    }
}
