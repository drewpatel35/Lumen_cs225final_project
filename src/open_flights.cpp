# include "open_flights.h"
#include "utilities.h"

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
        string country;
        if (str.size() > 14) {
            temp.name = str.at(1).substr(1, str.at(1).size()-1);
            country = str.at(4).substr(1, str.at(4).size()-2);
            temp.code = str.at(5).substr(1, str.at(5).size()-2);
            temp.latitude = stod(str.at(7));
            temp.longitude = stod(str.at(8));
        } else {
            temp.name = str.at(1).substr(1, str.at(1).size()-2);
            country = str.at(3).substr(1, str.at(3).size()-2);
            temp.code = str.at(4).substr(1, str.at(4).size()-2);
            temp.latitude = stod(str.at(6));
            temp.longitude = stod(str.at(7));
        }
        idx_.push_back(temp.code);
        adjacencyList.insert({temp.code, {}});
        airportIndex.insert({temp.code, temp});
        numAirports++; 
        
    }
    ap.close();
    line.clear();

    std::ifstream rt(routes);
    if(!rt.is_open()) {
        throw std::runtime_error("Could not open file");
    }
    while(std::getline(rt, line)){
        vector<string> str = Split(line, ',');
        if (str.size() == 9){
            string source = str[2];
            // std::cout << source;
            adjacent dest = {str[4], findDistance(source, str[4])};
            // std::cout << dest.code;
            //if (adjacencyList.find(source) != adjacencyList.end())
            adjacencyList[source].push_back(dest);
        }
    }
    rt.close();

}

vector<string> AirportMap::bfsShortestPath(const string& start, const string& dest) {
    std::unordered_set<string> seen;
    std::queue<string> next;
    std::map<string, int> dist;
    std::map<string, string> par;
    if (!VertexInGraph(start) || !VertexInGraph(dest)) {
        return {"-1"};
    }
    next.push(start);
    seen.insert(start);
    par.insert({start, "-1"});
    while (!next.empty()) {
        string n = next.front();
        next.pop();
        if (!VertexInGraph(n)) {
            return{"-1"};
        }
        if (n == dest) {
            vector<string> ret = {};
            string val = n;
            while (val != "-1") {
                ret.push_back(val);
                val = par[val];
            }
            return reverse(ret);
        }
        for (const adjacent& hey : adjacencyList[n]) {
            if (seen.find(hey.code) == seen.end()) {
                seen.insert(hey.code);
                par.insert({hey.code, n});
                next.push(hey.code);
            }
        }
    }
    return {"-1"};
}

vector<string> AirportMap::djikstrasShortestPath(const string& start,const string& dest, double& distance) {
    std::unordered_set<string> seen;
    PriorityQueue next;
    vector<double> dist(idx_.size(), std::numeric_limits<int>::max());
    std::map<string, string> par;
    if (!VertexInGraph(start) || !VertexInGraph(dest)) {
        return {"-1"};
    }
    next.push({start, 0});
    seen.insert(start);
    dist[airportIndex[start].index] = 0;
    par.insert({start, "-1"});
    while (!next.empty()) {
        pair<string, double> n = next.front();
        next.pop();
        if (!VertexInGraph(n.first)) {
            return{"-1 gay"};
        }
        if (n.first == dest) {
            vector<string> ret;
            string val = n.first;
            distance = dist[airportIndex[n.first].index];
            while (val != "-1") {
                ret.push_back(val);
                val = par[val];
            }
            return reverse(ret);
        }
        for (const adjacent& hey : adjacencyList.at(n.first)) {
            if (seen.find(hey.code) == seen.end()) {
                if (dist[airportIndex[hey.code].index] > dist[airportIndex[n.first].index] + hey.distance) {
                    dist[airportIndex[hey.code].index] = dist[airportIndex[n.first].index] + hey.distance;
                    par[hey.code] = n.first;
                }
                next.push({hey.code, dist[airportIndex[hey.code].index]});
            }
        }
        seen.insert(n.first);
    }
    return {"-1"};
}

vector<string> AirportMap::pagerank() {
    vector<vector<double>> matrix(numAirports, vector<double>(numAirports, 0.0));
    for (pair<string, airport> pr : airportIndex) {
        vector<adjacent> adj = adjacencyList[pr.first];
        int idx1 = pr.second.index;
        if (adj.empty()) {
            for (size_t i = 0; i<numAirports; i++) {
                matrix[i][idx1] = 1.0/numAirports;
            }
        }
        for (adjacent a : adj) {
            int idx2 = airportIndex[a.code].index;
            matrix[idx2][idx1] = 1.0/adj.size();
        }
    }
    for (size_t i = 0; i<numAirports;i++) {
        for (size_t j = 0;j<numAirports;j++) {
            matrix[i][j] = (0.85 * matrix[i][j]) + (.15 / numAirports);
        }
    }
    vector<vector<double>> steadystate(numAirports, vector<double>(1, 0.0));
    steadystate[0][0] = 1.0;
    for (size_t i=0;i<200;i++)
        steadystate = matrixMultiplication(matrix, steadystate);
    vector<pair<double, string>> temp(numAirports, {0.0, ""});
    for (size_t i = 0;i<numAirports;i++) {
        temp[i] = {steadystate[i][0], idx_[i]};
    }
    sort(temp.rbegin(), temp.rend());
    vector<string> ret;
    for (size_t i = 0;i<5;i++) {
        ret.push_back(temp[i].second);
    }
    return ret;
}


bool AirportMap::VertexInGraph(string code) {
    if (airportIndex.find(code) == airportIndex.end()) {
        return false;
    }
    return true;
}   

double AirportMap::findDistance(string start, string dest) {
    return distance(airportIndex[start].latitude, airportIndex[start].longitude, 
                    airportIndex[dest].latitude, airportIndex[dest].longitude);
}

void AirportMap::printAirports() {
    for (size_t i = 0; i<idx_.size(); i++) {
        cout << airportIndex[idx_[i]].name << ", "  << idx_[i] << '\n';
    }
}

void AirportMap::displayAdjList() {
   for (pair<string, vector<adjacent>> a : adjacencyList) {
        cout << a.first << "--> ";
        for (const adjacent& b : a.second) {
            cout << b.code << "(" << b.distance << ") ";
        }
        cout << '\n';
    }
}
// bool sortbysec(const pair<string, double> &a,
//               const pair<string, double> &b) {
//     return (a.second < b.second);
// }

void PriorityQueue::push(pair<string, double> element) {
    if (q_.empty()) {
        q_.push_back(element);
        return;
    }
    size_t i = 0;
    while (i < q_.size() && q_[i].second < element.second) {
        i++;
    }
    q_.insert(q_.begin() + i, element);
}
pair<string, double> PriorityQueue::front() {
    if (q_.empty()) return {};

    return q_.front();
}
void PriorityQueue::pop() {
    if (q_.empty()) return;

    q_.erase(q_.begin());
}

void PriorityQueue::print() {
    cout << "[ ";
    for (pair<string, double> pr : q_) {
        cout << pr.first  << ":" << pr.second << " ";
    }
    cout << "] \n \n";
}