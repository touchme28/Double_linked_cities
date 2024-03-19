#pragma once

#include <iostream>
using namespace std;

class City {
private:
    string cityName;
    string regionName;
    int population;
    City* next;
    City* prev;

    bool hook;

public:
    City(string name, string region, int pop);

    string getRegionName();

    int getPopulation();
    void setPopulation(int num);

    City* getNext();
    void setNext(City* n);

    City* getPrev();
    void setPrev(City* p);

    bool getHook();
    void setHook(bool value);

    void displayInfo();
};