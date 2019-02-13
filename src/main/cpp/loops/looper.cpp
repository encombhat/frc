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

#include "loops/looper.h"

Looper::Looper() :
    m_running(false),
    m_loops({})
{
    m_notifier = new frc::Notifier([=]() {
        m_mutex.lock();

        if (!m_running) return;

        double now = frc::Timer::GetFPGATimestamp();

        for (Loop* loop : m_loops) loop->onTick(now);

        m_delta = now - m_timestamp;
        m_timestamp = now;

        m_mutex.unlock();
    });
}

Looper::~Looper() {}

void Looper::add(Loop* loop) {
    m_mutex.lock();

    m_loops.push_back(loop);

    m_mutex.unlock();
}

void Looper::start() {
    if (m_running) return;

    std::cout << "Starting loops" << std::endl;

    m_mutex.lock();

    m_timestamp = frc::Timer::GetFPGATimestamp();
    for (Loop* loop : m_loops) loop->onStart(m_timestamp);
    m_running = true;

    m_notifier->StartPeriodic(kPeriod);

    m_mutex.unlock();
}

void Looper::stop() {
    if (!m_running) return;

    std::cout << "Stopping loops" << std::endl;

    m_notifier->Stop();

    m_mutex.lock();

    m_running = false;
    m_timestamp = frc::Timer::GetFPGATimestamp();
    for (Loop* loop : m_loops) {
        std::cout << "Stopping " << loop->toString() << std::endl;

        loop->onStop(m_timestamp);
    }

    m_mutex.unlock();
}