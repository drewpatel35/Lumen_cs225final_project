#pragma once

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include <map>
#include <stdexcept>
#include <vector>
#include <cmath>
#include <cctype>
#include <algorithm>


using namespace std;

struct airport {
    int index;
    string name;
    double latitude;
    double longitude;
    string code;
};

class AirportMap {
    public:
        
        AirportMap() = default;
        AirportMap(const string& airports, const string& routes);
        map<string, airport> airportIndex;
        vector<vector<int>> adjacencyMatrix;
        void printAirports();
        void displayAdjList();
        string getCode(int idx) { return airportIndex[idx_[idx]].code; }
        double findDistance(string start, string dest);
    private:

        vector<string> idx_;
        size_t numAirports = 0;
        
};

std::vector<std::string> Split(const std::string& str, char delimiter);
long double distance(long double lat1, long double long1, long double lat2, long double long2);
long double toRadians(const long double degree);