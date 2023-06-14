#pragma once

#include "./modules.h"

// SYSTEM
void InitAllPins();
void GotoSleep();

// SAMPLING
void SamplingProcess();
void DoSampling();

// HEATING
void InitHeating();
void HeatingProcess();
void HeatingWait();

// Stepper Control
uint8_t ZeroSteppers(uint8_t process);
uint8_t SampleCycle(uint8_t process);

// Wheel
void InitStepperWheel();
void ReadWheelSwitches();
void HeatStepper_Wheel();
uint8_t WheelGotoHome(uint8_t process);
uint8_t WheelGotoSampling(uint8_t process);
uint8_t WheelGotoPurge(uint8_t process);

// Height
void InitStepperHeight();
void HeatStepper_Height();
uint8_t HeightGotoClearing(uint8_t process);
uint8_t HeightGotoSampling(uint8_t process);
void ReadHeightSwitch();

// Pump
void InitStepperPump();
void HeatStepper_Pump();
uint8_t PumpGotoSampling(uint8_t process);
uint8_t PumpGotoPurge(uint8_t process);
