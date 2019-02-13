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

#include "loops/looper.h"

class Service {
    public:
        virtual void writeToLog();
        virtual void readPeriodicInputs();
        virtual void writePeriodicOutputs();

        virtual bool checkSystem();
        virtual void outputTelemetry();
        virtual void stop();

        virtual void zeroSensors();

        virtual void registerEnabledLoops(Looper* looper);
};
