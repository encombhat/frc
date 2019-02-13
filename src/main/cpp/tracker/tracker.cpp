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

#include "tracker/tracker.h"

#include <fstream>
#include <chrono>
#include <ctime>

#include "utils/uuid.h"

const std::string CrashTracker::RUN_INSTANCE_UUID = Utils::generateUUID();

void CrashTracker::logRobotStartup() {
    logMarker("robot startup");
}

void CrashTracker::logRobotConstruction() {
    logMarker("robot startup");
}

void CrashTracker::logRobotInit() {
    logMarker("robot init");
}

void CrashTracker::logTeleopInit() {
    logMarker("teleop init");
}

void CrashTracker::logAutoInit() {
    logMarker("auto init");
}

void CrashTracker::logDisabledInit() {
    logMarker("disabled init");
}

void CrashTracker::logException(std::exception e) {
    logMarker("Exception", e);
}

void CrashTracker::logMarker(const std::string& mark) {
    std::ofstream logFile("/home/lvuser/crash_tracking.txt");

    if (logFile.fail()) {
        std::cout << "File open failed!" << std::endl;
        return;
    }

    auto currentTime = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());

    logFile << RUN_INSTANCE_UUID << "/" << std::ctime(&currentTime) << ": " << mark << std::endl;
}

void CrashTracker::logMarker(const std::string& mark, std::exception e) {
    std::ofstream logFile("/home/lvuser/crash_tracking.txt");

    if (logFile.fail()) {
        std::cout << "File open failed!" << std::endl;
        return;
    }

    auto currentTime = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());

    logFile << RUN_INSTANCE_UUID << "/" << std::ctime(&currentTime) << ": " << mark << std::endl << "Exception: " << e.what() << std::endl;
}
