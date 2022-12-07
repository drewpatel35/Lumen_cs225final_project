#pragma once

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <queue>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <stdexcept>
#include <vector>
#include <cmath>
#include <cctype>
#include <algorithm>
#include <stdio.h>


using namespace std;

struct airport {
    int index;
    string name;
    double latitude;
    double longitude;
    string code;

    bool operator==(const airport& a) const {
        return (a.index == index &&
            a.name == name &&
            a.latitude == latitude &&
            a.longitude == longitude &&
            a.code == code);
    }
};

struct adjacent {
    string code;
    double distance;

    bool operator==(const adjacent& a) const {
        return (code == a.code && distance == a.distance);
    }
};

class AirportMap {
    public:
        
        AirportMap() = default;
        AirportMap(const string& airports, const string& routes);
        unordered_map<string, airport> airportIndex;
        unordered_map<string, vector<adjacent>> adjacencyList;
        vector<string> idx_;
        void printAirports();
        void displayAdjList();
        double findDistance(string start, string dest);
        vector<string> bfsShortestPath(const string& start, const string& dest);
        vector<string> djikstrasShortestPath(const string& start, const string& dest, double& distance);
        vector<double> pagerank();
    private:
        
        bool VertexInGraph(string code);
        size_t numAirports = 0;
        
};

std::vector<std::string> Split(const std::string& str, char delimiter);
long double distance(long double lat1, long double long1, long double lat2, long double long2);
long double toRadians(const long double degree);
vector<string> reverse(vector<string> s);
void print_2d_vector(const vector< vector<double> > & matrix);
vector<vector<double>> matrixMultiplication(const vector<vector<double>>& l, const vector<vector<double>>& r);