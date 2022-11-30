# include "open_flights.h"

using namespace std;

AirportMap::AirportMap(const string& airports, const string& routes)
{
    std::ifstream ap(airports);
    if(!ap.is_open()) {
        throw std::runtime_error("Could not open file");
    }
    string line;
    while(std::getline(ap, line)){
        airport temp;
        vector<string> str = Split(line, ',');
        temp.index = numAirports;
        temp.name = str.at(1).substr(1, str.at(1).size()-2);
        temp.code = str.at(4).substr(1, str.at(4).size()-2);
        if (str.size() > 14) {
            temp.latitude = stod(str.at(7));
            temp.longitude = stod(str.at(8));
        } else {
            temp.latitude = stod(str.at(6));
            temp.longitude = stod(str.at(7));
        }
        

        airportIndex.insert({temp.code, temp});
        idx_.push_back(temp.code);
        numAirports++;
    }
    ap.close();
    line.clear();

    adjacencyMatrix = vector<vector<int>>(numAirports , vector<int> (numAirports, 0)); 
    std::ifstream rt(routes);
    if(!rt.is_open()) {
        throw std::runtime_error("Could not open file");
    }
    while(std::getline(rt, line)){
        vector<string> str = Split(line, ',');
        if (!str.empty()){
            string source = str[2];
            string destination = str[4];
            double distance = findDistance(source, destination);
            adjacencyMatrix.at(airportIndex[source].index).at(airportIndex[destination].index) = distance;
        }
    }
    rt.close();

}

double AirportMap::findDistance(string start, string dest) {
    return distance(airportIndex[start].latitude, airportIndex[start].longitude, 
                    airportIndex[dest].latitude, airportIndex[dest].longitude);
}

void AirportMap::printAirports() {
    for (pair<string, airport> a : airportIndex) {
        cout << a.second.name << ", "  << a.second.code << '\n';
    }
}

void AirportMap::displayAdjList() {
   for (pair<string, airport> a : airportIndex) {
        cout << a.first << "--> ";
        for (size_t i = 0; i < numAirports; i++) {
            if (adjacencyMatrix[a.second.index][i] != 0) {
                cout << idx_[i] << "(" << adjacencyMatrix[a.second.index][i] << ") ";
            }
        }
        cout << '\n';
    }
}

std::vector<std::string> Split(const std::string& str, char delimiter) {
  size_t last = 0;
  std::vector<std::string> substrs;
  for (size_t i = 0; i != str.length(); ++i) {
    if (str.at(i) == delimiter || str.at(i) == '\r') {
      std::string substr = str.substr(last, i - last);
      last = i + 1;
      substrs.push_back(substr);
    }
  }

  if (last != str.size()) {
    std::string substr = str.substr(last, str.length() - last);
    substrs.push_back(substr);
  }

  return substrs;
}

// Utility function for converting degrees to radians
long double toRadians(const long double degree)
{
    // cmath library in C++ defines the constant
    // M_PI as the value of pi accurate to 1e-30
    long double one_deg = (M_PI) / 180;
    return (one_deg * degree);
}
 
long double distance(long double lat1, long double long1,
                     long double lat2, long double long2)
{
    // Convert the latitudes and longitudes from degree to radians.
    lat1 = toRadians(lat1);
    long1 = toRadians(long1);
    lat2 = toRadians(lat2);
    long2 = toRadians(long2);
     
    // Haversine Formula
    long double dlong = long2 - long1;
    long double dlat = lat2 - lat1;
 
    long double ans = pow(sin(dlat / 2), 2) + cos(lat1) * cos(lat2) * pow(sin(dlong / 2), 2);
 
    ans = 2 * asin(sqrt(ans));
 
    // Radius of Earth in Kilometers, R = 6371 Use R = 3956 for miles
    long double R = 6371;
     
    ans = ans * R;
 
    return ans;
}