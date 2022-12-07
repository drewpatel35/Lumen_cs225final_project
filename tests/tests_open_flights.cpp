#include <catch2/catch_test_macros.hpp>

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <locale>

#include "open_flights.h"

TEST_CASE("Constructor airportIndex", "[airportIndex]") {
  AirportMap test1("/workspaces/cs225/MPs/release-f22/Lumen_cs225final_project-main/entry/airportTest.dat", 
                     "/workspaces/cs225/MPs/release-f22/Lumen_cs225final_project-main/entry/routeTest.dat");
                     
  airport gka = {0,"Goroka Airport", -6.081689834590001, 145.391998291, "GKA"};
  airport mag = {1,"Madang Airport", -5.20707988739, 145.789001465, "MAG"};
  airport hgu = {2,"Mount Hagen Kagamuga Airport", -5.826789855957031, 144.29600524902344, "HGU"};
  airport lae = {3,"Nadzab Airport", -6.569803, 146.725977, "LAE"};
  airport pom = {4,"Port Moresby Jacksons International Airport", -9.443380355834961, 147.22000122070312, "POM"};
  airport wwk = {5,"Wewak International Airport", -3.58383011818,143.669006348, "WWK"};
  airport uak = {6,"Narsarsuaq Airport", 61.1604995728,-45.4259986877, "UAK"};
  airport goh = {7,"Godthaab / Nuuk Airport", 64.19090271,-51.6781005859, "GOH"};
  airport sfj = {8,"Kangerlussuaq Airport", 67.0122218992,-50.7116031647, "SFJ"};
  airport thu = {9,"Thule Air Base", 76.5311965942,-68.7032012939, "THU"};
  airport eve = {10,"Harstad/Narvik Airport", 68.491302490234,16.678100585938, "EVE"};
  REQUIRE(gka == test1.airportIndex["GKA"]);
  REQUIRE(mag == test1.airportIndex["MAG"]);
  REQUIRE(hgu==test1.airportIndex["HGU"]);
  REQUIRE(lae==test1.airportIndex["LAE"]);
  REQUIRE(pom == test1.airportIndex["POM"]);
  REQUIRE(wwk == test1.airportIndex["WWK"]);
  REQUIRE(uak == test1.airportIndex["UAK"]);
  REQUIRE(goh == test1.airportIndex["GOH"]);
  REQUIRE(sfj == test1.airportIndex["SFJ"]);
  REQUIRE(thu == test1.airportIndex["THU"]);
  REQUIRE(eve == test1.airportIndex["EVE"]);
}
TEST_CASE("Constructor adjecencyMatrix", "[airportIndex]") {
  AirportMap test1("/workspaces/cs225/MPs/release-f22/Lumen_cs225final_project-main/entry/airportTest.dat", 
                     "/workspaces/cs225/MPs/release-f22/Lumen_cs225final_project-main/entry/routeTest.dat");
  vector<adjacent>  gka = {{"MAG",test1.findDistance("GKA", "MAG")},
                           {"HGU",test1.findDistance("GKA", "HGU")},
                           {"LAE",test1.findDistance("GKA", "LAE")},
                           {"POM",test1.findDistance("GKA", "POM")}};
  vector<adjacent>  mag = {{"HGU",test1.findDistance("MAG", "HGU")},
                           {"LAE",test1.findDistance("MAG", "LAE")}};
  vector<adjacent>  hgu = {{"MAG",test1.findDistance("MAG", "HGU")}, 
                           {"THU",test1.findDistance("THU", "HGU")}};
  vector<adjacent>  lae = {{"SFJ",test1.findDistance("LAE", "SFJ")}};
  vector<adjacent>  pom = {{"SFJ",test1.findDistance("POM", "SFJ")}};
  vector<adjacent>  wwk = {{"UAK",test1.findDistance("WWK", "UAK")}};
  vector<adjacent>  uak = {{"WWK",test1.findDistance("WWK", "UAK")}};
  vector<adjacent>  goh = {};
  vector<adjacent>  sfj = {{"MAG",test1.findDistance("SFJ", "MAG")}};
  vector<adjacent>  thu = {{"MAG",test1.findDistance("THU", "MAG")},
                           {"HGU",test1.findDistance("THU", "HGU")}};
  vector<adjacent>  eve = {};
  REQUIRE(gka == test1.adjacencyList["GKA"]);
  REQUIRE(mag == test1.adjacencyList["MAG"]);
  REQUIRE(hgu == test1.adjacencyList["HGU"]);
  REQUIRE(lae == test1.adjacencyList["LAE"]);
  REQUIRE(pom == test1.adjacencyList["POM"]);
  REQUIRE(wwk == test1.adjacencyList["WWK"]);
  REQUIRE(uak == test1.adjacencyList["UAK"]);
  REQUIRE(goh == test1.adjacencyList["GOH"]);
  REQUIRE(sfj == test1.adjacencyList["SFJ"]);
  REQUIRE(thu == test1.adjacencyList["THU"]);
  REQUIRE(eve == test1.adjacencyList["EVE"]);
}