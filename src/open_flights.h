#pragma once

#include <string>
#include <fstream>
#include <unordered_map>
#include <map>
#include <stdexcept>
#include <vector>
#include <cmath>
#include <cctype>
#include <algorithm>


using namespace std;

struct airport {
    string name;
    double latitude;
    double longitude;
};

class AirportMap {
    public:
        vector<airport> airportIndex;
        vector<vector<int>> adjacencyMatrix;

        airportMap() = default;
        airportMap(string airports, string routes);

        void insertAirport(vector<string> line);
        void insertRoute(vector<string> line);

    private:
        double findDistance(int start, int dest);
};
