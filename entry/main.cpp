#include "open_flights.h"

int main() {
    AirportMap test("/workspaces/cs225/MPs/release-f22/Lumen_cs225final_project-main/entry/airports.dat",
                    "/workspaces/cs225/MPs/release-f22/Lumen_cs225final_project-main/entry/routes.dat");
    test.printAirports();
    test.displayAdjList();
}
