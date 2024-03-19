#pragma once

#include <iostream>
using namespace std;

class Region {
private:
    string regionName;
    int population;
    Region* next;
    Region* prev;

public:
    Region(string region, int pop);

    string getRegionName();

    int getPopulationReg();
    void setPopulationReg(int num);

    Region* getNextReg();
    void setNextReg(Region* n);

    Region* getPrevReg();
    void setPrevReg(Region* p);

    void displayInfoReg();
};
