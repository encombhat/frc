/* 
 * This file is part of the Construct distribution.
 * Copyright (c) 2019 Haolan Li.
 * 
 * This program is free software: you can redistribute it and/or modify  
 * it under the terms of the GNU General Public License as published by  
 * the Free Software Foundation, version 3.
 *
 * This program is distributed in the hope that it will be useful, but 
 * WITHOUT ANY WARRANTY; without even the implied warranty of 
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU 
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License 
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#include <string>
#include <cstdlib>

//*Adapted from https://gist.github.com/ne-sachirou/882192
//*std::rand() can be replaced with other algorithms as Xorshift for better perfomance
//*Random seed must be initialized by user

namespace Utils {
  const std::string CHARS = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

  std::string generateUUID(){
    std::string uuid = std::string(36,' ');
    int rnd = 0;
    int r = 0;
    
    uuid[8] = '-';
    uuid[13] = '-';
    uuid[18] = '-';
    uuid[23] = '-';

    uuid[14] = '4';

    for(int i=0; i<36; i++){
      if (i != 8 && i != 13 && i != 18 && i != 14 && i != 23) {
        if (rnd <= 0x02) {
            rnd = 0x2000000 + (std::rand() * 0x1000000) | 0;
        }
        rnd >>= 4;
        uuid[i] = CHARS[(i == 19) ? ((rnd & 0xf) & 0x3) | 0x8 : rnd & 0xf];
      }
    }
    return uuid;
  }
}
