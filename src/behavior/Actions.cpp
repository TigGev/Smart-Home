#include "../../include/behavior/Actions.hpp"
#include <iostream>

void Gradualy::doAlgorithm(Device* dev) {
    dev->weakenTheDevice(); // turn off
}

void Instantly::doAlgorithm(Device* dev) {
    if (dev->isTurnOn()) {
        dev->setTurnOff();
        return;
    }
    dev->setTurnOn();
}

void Signal::doAlgorithm(Device* dev) {
    std::cout << "\033[31m" << "Warning!!!" << "\033[0m";
    if (dev->isTurnOn()) {
        dev->setTurnOff();
        return;
    }
    dev->setTurnOn();
}
