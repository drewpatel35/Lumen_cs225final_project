#include <catch2/catch_test_macros.hpp>

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <locale>


#include "tests_part1.h"


bool equals(airport a, airport b) {
  return a.index == b.index &&
         a.name == b.name &&
         a.latitude == b.latitude &&
         a.longitude == b.longitude &&
         a.code == b.code;
}

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
  REQUIRE(equals(gka, test1.airportIndex["GKA"]));
  REQUIRE(equals(mag, test1.airportIndex["MAG"]));
  REQUIRE(equals(hgu, test1.airportIndex["HGU"]));
  REQUIRE(equals(lae, test1.airportIndex["LAE"]));
  REQUIRE(equals(pom, test1.airportIndex["POM"]));
  REQUIRE(equals(wwk, test1.airportIndex["WWK"]));
  REQUIRE(equals(uak, test1.airportIndex["UAK"]));
  REQUIRE(equals(goh, test1.airportIndex["GOH"]));
  REQUIRE(equals(sfj, test1.airportIndex["SFJ"]));
  REQUIRE(equals(thu, test1.airportIndex["THU"]));
}
TEST_CASE("Constructor adjecencyMatrix", "[airportIndex]") {
  AirportMap test1("/workspaces/cs225/MPs/release-f22/Lumen_cs225final_project-main/entry/airportTest.dat", 
                     "/workspaces/cs225/MPs/release-f22/Lumen_cs225final_project-main/entry/routeTest.dat");
  vector<int>  gka = {0,static_cast<int>(test1.findDistance("GKA", "MAG")),static_cast<int>(test1.findDistance("GKA", "HGU")),static_cast<int>(test1.findDistance("GKA", "LAE")),static_cast<int>(test1.findDistance("GKA", "POM")),0,0,0,0,0};
  vector<int>  mag = {0,0,static_cast<int>(test1.findDistance("MAG", "HGU")),static_cast<int>(test1.findDistance("MAG", "LAE")),0,0,0,0,0,0};
  vector<int>  hgu = {0,static_cast<int>(test1.findDistance("MAG", "HGU")),0,0,0,0,0,0,0,static_cast<int>(test1.findDistance("THU", "HGU"))};
  vector<int>  lae = {0,0,0,0,0,0,0,0,static_cast<int>(test1.findDistance("LAE", "SFJ")),0};
  vector<int>  pom = {0,0,0,0,0,0,0,0,static_cast<int>(test1.findDistance("POM", "SFJ")),0};
  vector<int>  wwk = {0,0,0,0,0,0,static_cast<int>(test1.findDistance("WWK", "UAK")),0,0,0};
  vector<int>  uak = {0,0,0,0,0,static_cast<int>(test1.findDistance("WWK", "UAK")),0,0,0,0};
  vector<int>  goh = {0,0,0,0,0,0,0,0,0,0};
  vector<int>  sfj = {0,static_cast<int>(test1.findDistance("SFJ", "MAG")),0,0,0,0,0,0,0,0};
  vector<int>  thu = {0,static_cast<int>(test1.findDistance("THU", "MAG")),static_cast<int>(test1.findDistance("THU", "HGU")),0,0,0,0,0,0,0};
  REQUIRE(gka == test1.adjacencyMatrix[0]);
  REQUIRE(mag == test1.adjacencyMatrix[1]);
  REQUIRE(hgu == test1.adjacencyMatrix[2]);
  REQUIRE(lae == test1.adjacencyMatrix[3]);
  REQUIRE(pom == test1.adjacencyMatrix[4]);
  REQUIRE(wwk == test1.adjacencyMatrix[5]);
  REQUIRE(uak == test1.adjacencyMatrix[6]);
  REQUIRE(goh == test1.adjacencyMatrix[7]);
  REQUIRE(sfj == test1.adjacencyMatrix[8]);
  REQUIRE(thu == test1.adjacencyMatrix[9]);

}