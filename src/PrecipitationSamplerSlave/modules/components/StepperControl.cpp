#pragma once

#include "../setup/modules.h"

uint8_t zeroProcess = 0;
uint8_t sampleProcess = 0;

void ZeroSteppers() {

    switch (zeroProcess) {
    case 0:
        zeroProcess = Height_Clearing(zeroProcess);
        break;
    case 1:
        zeroProcess = Wheel_Homing(zeroProcess);
        break;
    case 2:

        break;
    }
}

void SampleCycle() {
    switch (sampleProcess) {
    case 0:
        sampleProcess = HeightGotoClearing(sampleProcess);
        break;
    case 1:
        sampleProcess = WheelGotoSampling(sampleProcess);
        break;
    case 2:
        sampleProcess = HeightGotoSampling(sampleProcess);
        break;
    case 3:
        sampleProcess = PumpGotoSampling(sampleProcess);
        break;
    case 4:
        sampleProcess = HeightGotoClearing(sampleProcess);
        break;
    case 5:
        sampleProcess = WheelGotoPurge(sampleProcess);
        break;
    case 6:
        sampleProcess = PumpGotoPurge(sampleProcess);
        break;
    }
}