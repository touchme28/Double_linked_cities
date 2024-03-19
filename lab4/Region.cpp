#include "Region.h"
#include <iostream>

Region::Region(string region, int pop) {
    regionName = region;
    population = pop;
    next = nullptr;
    prev = nullptr;
}

string Region::getRegionName() {
    return regionName;
}

int Region::getPopulationReg() {
    return population;
}

void Region::setPopulationReg(int num) {
    population = num;
}

Region* Region::getNextReg() {
    return next;
}

void Region::setNextReg(Region* n) {
    next = n;
}

Region* Region::getPrevReg() {
    return prev;
}

void Region::setPrevReg(Region* p) {
    prev = p;
}



void Region::displayInfoReg() {
    cout << "Region: " << regionName << endl;
    cout << "Population: " << population << endl;
}