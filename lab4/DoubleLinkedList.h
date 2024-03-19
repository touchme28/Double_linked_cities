#pragma once

#include "City.h"
#include "Region.h"
#include <iostream>
using namespace std;

class DoubleLinkedList {
private:
    City* head_city;
    Region* head_reg;

public:
    DoubleLinkedList();

    DoubleLinkedList convertReg();

    void insertCity(string name, string region, int pop);
    void insertRegion(string region, int pop);

    void displayRegionsByPopulation();

    Region* mergeSort(Region* head);

    Region* getMiddle(Region* head);


    Region* merge(Region* first, Region* second);
    
    void deleteCitiesByRegion(string region);

    void deleteCities();

    void displayCities();
    void displayRegion();
};