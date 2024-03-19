#include "DoubleLinkedList.h"
#include <iostream>

DoubleLinkedList::DoubleLinkedList() {
    head_city = nullptr;
    head_reg = nullptr;
}

void DoubleLinkedList::insertCity(string name, string region, int pop) {
    City* newCity = new City(name, region, pop);

    if (head_city == nullptr) {
        head_city = newCity;
    }
    else {
        City* current = head_city;
        while (current->getNext() != nullptr) {
            current = current->getNext();
        }
        current->setNext(newCity);
        newCity->setPrev(current);
    }
}

void DoubleLinkedList::insertRegion(string region, int pop) {
    Region* newRegion = new Region(region, pop);

    if (head_reg == nullptr) {
        head_reg = newRegion;
    }
    else {
        Region* current = head_reg;
        while (current->getNextReg() != nullptr) {
            current = current->getNextReg();
        }
        current->setNextReg(newRegion);
        newRegion->setPrevReg(current);
    }
}


DoubleLinkedList DoubleLinkedList::convertReg() {
    DoubleLinkedList regionList;
    City* x = head_city;
    while (x != nullptr) {
        City* y = x->getNext();

        while (y != nullptr) {
            if (x->getRegionName() == y->getRegionName()) {
                x->setPopulation(x->getPopulation() + y->getPopulation());
                y->setHook(false);
            }
            y = y->getNext();
        }
        if (x->getHook() == true) {
            regionList.insertRegion(x->getRegionName(),x->getPopulation());
            x->setHook(false);
        }
        x->setHook(true);
        x = x->getNext();
    }

    return regionList;
}


void DoubleLinkedList::displayRegionsByPopulation() {
    Region* sortedList = mergeSort(head_reg);
    head_reg = sortedList;

    cout << "Regions in descending order of population:" << endl;
    while (sortedList != nullptr) {
        cout << sortedList->getRegionName() << " - " << sortedList->getPopulationReg() << " residents" << endl;
        sortedList = sortedList->getNextReg();
    }
}

Region* DoubleLinkedList::mergeSort(Region* head) {
    if (head == nullptr || head->getNextReg() == nullptr) {
        return head;
    }

    Region* middle = getMiddle(head);
    Region* secondHalf = middle->getNextReg();
    middle->setNextReg(nullptr);

    Region* firstHalf = mergeSort(head);
    secondHalf = mergeSort(secondHalf);

    return merge(firstHalf, secondHalf);
}

Region* DoubleLinkedList::getMiddle(Region* head) {
    Region* slow = head;
    Region* fast = head;

    while (fast->getNextReg() != nullptr && fast->getNextReg()->getNextReg() != nullptr) {
        slow = slow->getNextReg();
        fast = fast->getNextReg()->getNextReg();
    }

    return slow;
}


Region* DoubleLinkedList::merge(Region* first, Region* second) {
    if (first == nullptr) {
        return second;
    }
    if (second == nullptr) {
        return first;
    }

    Region* result = nullptr;
    if (first->getPopulationReg() >= second->getPopulationReg()) {
        result = first;
        result->setNextReg(merge(first->getNextReg(), second));
    }
    else {
        result = second;
        result->setNextReg(merge(first, second->getNextReg()));
    }

    return result;
}

//##################################################
void DoubleLinkedList::deleteCitiesByRegion(string region) {
    City* current = head_city;
    while (current != nullptr) {
        City* next = current->getNext();
        if (current->getRegionName() == region) {

            if (current->getPrev() != nullptr) {
                current->getPrev()->setNext(current->getNext());
            }
            else {
                head_city = current->getNext();
            }

            if (current->getNext() != nullptr) {
                current->getNext()->setPrev(current->getPrev());
            }
            else {
                current->getPrev()->setNext(nullptr);
            }
            delete current;
        }
        current = next;        
    }

}

//###############################################
void DoubleLinkedList::deleteCities() {
    City* current = head_city;
    while (current != nullptr) {
        City* temp = current;
        current = current->getNext();
        delete temp;
    }
    head_city = nullptr;
}

void DoubleLinkedList::displayCities() {
    City* current = head_city;
    while (current != nullptr) {
        current->displayInfo();
        cout << endl;
        current = current->getNext();
    }
}

void DoubleLinkedList::displayRegion() {

    Region* current = head_reg;

    //cout << "ZASHEL" << endl;
    //current->displayInfoReg();
    while (current != nullptr) {
        current->displayInfoReg();
        cout << endl;
        current = current->getNextReg();
    }
}