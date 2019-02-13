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

#include <list>
#include <mutex>

#include <frc/Notifier.h>
#include <frc/Timer.h>

#include "const.h"
#include "loops/loop.h"

#include "tracker/tracking_callable.h"

class Looper {
    public:
        Looper();

        ~Looper();

        void add(Loop* loop);
        void start();
        void stop();
        void outputToDashboard();

        const double kPeriod = K_LOOPER_DELTA;

    private:
        bool m_running;
        frc::Notifier* m_notifier;
        std::list<Loop*> m_loops;
        double m_timestamp = 0;
        double m_delta = 0;

        std::mutex m_mutex;
};