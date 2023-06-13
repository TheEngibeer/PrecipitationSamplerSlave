#pragma once

#include "./modules.h"

// System
void InitAllPins();
void GotoSleep();

// Sampling
void SamplingProcess();
void DoSampling();

// Heating
void InitHeating();
void HeatingProcess();
void HeatingWait();

// Steppers
void InitStepperWheel();
void InitStepperHeight();
void InitStepperPump();

void HeatStepper_Wheel();
void HeatStepper_Pump();
void HeatStepper_Height();

void HeightGotoClearing();
void HeightGotoSampling();
void ReadHeightSwitch();

void WheelGotoHome();
void ReadWheelSwitches();

void PumpGotoSampling();
