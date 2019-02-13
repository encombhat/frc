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

#include "Robot.h"

#include <iostream>

#include <frc/smartdashboard/SmartDashboard.h>
#include <frc/Timer.h>
#include <frc/Notifier.h>

#include "loops/looper.h"
#include "tracker/tracker.h"

using namespace std;

void Robot::RobotInit() {
  std::srand(std::time(nullptr));

  m_chooser.SetDefaultOption(kAutoNameDefault, kAutoNameDefault);
  m_chooser.AddOption(kAutoNameConstruct, kAutoNameConstruct);
  frc::SmartDashboard::PutData("Auto Modes", &m_chooser);

  CrashTracker::logRobotInit();
}

/**
 * This function is called every robot packet, no matter the mode. Use
 * this for items like diagnostics that you want ran during disabled,
 * autonomous, teleoperated and test.
 *
 * <p> This runs after the mode specific periodic functions, but before
 * LiveWindow and SmartDashboard integrated updating.
 */
void Robot::RobotPeriodic() {}

/**
 * This autonomous (along with the chooser code above) shows how to select
 * between different autonomous modes using the dashboard. The sendable chooser
 * code works with the Java SmartDashboard. If you prefer the LabVIEW Dashboard,
 * remove all of the chooser code and uncomment the GetString line to get the
 * auto name from the text box below the Gyro.
 *
 * You can add additional auto modes by adding additional comparisons to the
 * if-else structure below with additional strings. If using the SendableChooser
 * make sure to add them to the chooser code above as well.
 */
void Robot::AutonomousInit() {
  m_autoSelected = m_chooser.GetSelected();
  // m_autoSelected = SmartDashboard::GetString("Auto Selector",
  //     kAutoNameDefault);
  cout << "Auto selected: " << m_autoSelected << endl;

  if (m_autoSelected == kAutoNameDefault) {
    return;
  }
  if (m_autoSelected == kAutoNameConstruct) {
    return;
  }
}

void Robot::AutonomousPeriodic() {
  if (m_autoSelected == kAutoNameDefault) {
    return;
  }
  if (m_autoSelected == kAutoNameConstruct) {
    return;
  }
}

void Robot::TeleopInit() {}

void Robot::TeleopPeriodic() {}

void Robot::TestPeriodic() {}

#ifndef RUNNING_FRC_TESTS
int main() {
  return frc::StartRobot<Robot>();
}
#endif
