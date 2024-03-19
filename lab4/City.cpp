#include "City.h"
#include <iostream>

City::City(string name, string region, int pop) {
    cityName = name;
    regionName = region;
    population = pop;
    next = nullptr;
    prev = nullptr;
    hook = true;
}

string City::getRegionName() {
    return regionName;
}

int City::getPopulation() {
    return population;
}

void City::setPopulation(int num) {
    population = num;
}

City* City::getNext() {
    return next;
}

void City::setNext(City* n) {
    next = n;
}

City* City::getPrev() {
    return prev;
}

void City::setPrev(City* p) {
    prev = p;
}

bool City::getHook() {
    return hook;
}
void City::setHook(bool value) {
    hook = value;
}

void City::displayInfo() {
    cout << "City: " << cityName << endl;
    cout << "Region: " << regionName << endl;
    cout << "Population: " << population << endl;
}