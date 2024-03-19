#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include"DoubleLinkedList.h"
using namespace std;

int main(int argc, char* argv[]) {
    DoubleLinkedList cityList;
    DoubleLinkedList regionList;

    string path;
    path = string(argv[1]);

    ifstream fin(path);

    string x,regionToDelete;
    
    while (getline(fin,x)) {
        istringstream istream(x);

        string s,cityName = "", regionName = "";
        int population = 0;

        while (istream >> s) {
            if (population == 0 && regionName != "" && cityName != "") {
                population = stoi(s);
            }

            if (regionName == "" && cityName != "") {
                regionName = s;
            }

            if (cityName == "") {
                cityName = s;
            }
            
            
        }
        cityList.insertCity(cityName, regionName, population);
    }

    cout << "B:" << endl;
    regionList = cityList.convertReg();
    regionList.displayRegionsByPopulation();
    cout << endl;

    cout << "Enter the region to delete cities from: ";
    cin >> regionToDelete;
    cityList.deleteCitiesByRegion(regionToDelete);
    cout << endl;

    cityList.displayCities();

    cityList.deleteCities();
    return 0;
}
