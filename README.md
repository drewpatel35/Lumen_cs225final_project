# Team Contract

## Communication
1. **Team Meetings** 

    We are going to meet at least once a week on Wednesdays at the CIF. Meetings will be around 2-3 hours, where the first 30 minutes or so will be dedicated to going over what work we completed while not with each other and what work we will have to finish for the rest of our meeting. This part will be recorded by one group member in a shared document. At the end of the meeting, we will go over what needs to be completed by the next meeting and who will do what work.

2. **Assistance** 

    If we need help, we have a group chat and phone numbers to contact each other. We expect to get a response within 2 hours. We understand that everyone in our group has other work and committments, so a reply within this timeframe is fair.

3. **Respect** 

    Every team member will hold each other accountable for respect. If we find that one team member is not being respectful towards another, then we will address it in our team meetings as a group. 

## Collaboration

4. **Work Distribution** 

    We plan to distrubute work based on what we want to complete by the next meeting. Additionally, we will split work in teams of two, that way if someone falls behind or unforeseen work appears, they have someone else to aid them. Having previously worked together, this method of work distribution has worked the best.  
5. **Time Commitment** 

    Each member will be working on this project around 5-6 hours a week, including the weekly team meetings. This number is subject to change, however, based on workloads of each week. When time committments come up for one member it is not as much of a problem because we decided to split work into teams of two. That way if something comes up with one member, it won't set back an entire aspect of the project. 

6. **Conflict Resolution** 

    As stated before, if a conflict arises, we want to resolve it as soon as possible, so we will address it as a team during our weekly team meeting. If a certain member is not doing their work on time and coming to meetings late, then we will make it very clear that there is a problem and it has to come to an end. We find that when the entire group is involved with the issue rather than just one member talking to another, it is much more effective at solving our conflicts.

## Signatures

Drew Patel

Pranav Penaganti

Stefan Ninic

Kaan Yigit

-----------------------------------------------------------------------------------------------------------------------------------------------------------------------
# Final Project Proposal

## Leading Question 

For our final project we will use the OpenFlights dataset to see how people can be better connected using planes. We will find the most optimal path between Chicago and one of the five best vacation spots where the user will see options for the shortest travel distance vs least connected travel using Dijkastras Algorithm and BFS respectively. These vacation spots include South Island, Paris, Maui, Bora Bora, Tahiti, according to US News (https://travel.usnews.com/rankings/worlds-best-vacations/). In addition, we plan to calculate the largest airports based on number of connections an airport has using the Pagerank algorithm.

## Dataset Acquisition and Processing

The first file we are extracting data from is routes.dat, which has all airports, airlines, flight information, beginning and ending airport ID, and much more information. This file has 67663 routes between 3321 airports on 548 airlines. The other file we are extracting data from is airports.dat which contains the name and ID of each airport, and also its location. For our project, we will use the starting and ending airports and their locations to calculate the distance as the weighted edge for our graph. After we parse through all the datasets, we can then use the pagerank algorithm to find the top airports based on connections and add them to a vector.

To deal errors, we will implement an outlier check that isolate data values that are under or over a respective tolerance and set them to an average found from the data set. If there is missing data or too much data based on parsing each line of the data file, we will omit that line/entry from the data.

Each airport and route will be stored in a graph. We will have each airport as a node in our graph and the graph itself will be directed. To find the weight of each edge, we will use the distance between each airport. To aid in the implementation process, we will most likely use util files that will help with creating the graph and loading its data (all data will be loaded from OpenFlights). As we plan to map the airports and routes to a graph, we can estimate that the storage cost will be O(n^2) where n is the number of airports because the weighted graph will be implemented using an adjacency matrix. In addition, there will also be an additional map to store the vacation destinations with their respective airports which will have the only 5 entries. 

## Graph Algorithms/Description

To complete our algorithms, our first step is to create a graph with the airports in the data set and have an array of all the possible routes between them. This is important as we will have all the data possibly needed to complete the project stored in this graph. Each algorithm will take the adjacency matrix as an input however only Djikstra's algorithm will use the weights of the connections as distances whereas BFS and PageRank will only have to check whether the edge value is not zero.

An important algorithm for us to complete our goals is Djikstra’s algorithm. Djikstra’s algorithm is an algorithm used in graphs to find the shortest path by distance between nodes, and the use of this algorithm will be implemented when finding the shortest route between the 5 best vacation spots and Chicago. A BFS traversal will also be important for us to use, as it will provide us with an algorithm that can traverse the graph and find the flight path with the least connections. Djikstras algorithm and BFS traversal will output an array of each airport visited in order along with the total distance traveled. In addition, we can use the data stored in this adjacency matrix to calculate the most important/visited airports with the Pagerank algorithm. The user will be presented with the data for each largest airports from pagerank.

For the BFS traversal and Pagerank algorithm, the expected runtime is O(n+m) where n and m are the number of nodes and edges respectively.  For Dijkstras algorithm, the expected runtime is O(n^2) where n is the number of nodes. The time complexity could be reduced to O((n+m)log(n)) with n and m as nodes and edges respectively, however our implementation is using an adjacency matrix rather than linked list.

## Timeline

November 9: Set-up github files and testing files. Create files for each algorithm used in the project and figure out the structure of the assignment. 
  
November 18: Implement the algorithm to find the shortest path between given nodes. This will be using Djikstra’s algorithm. Also, create the website to display the data onto.

November 31st: Complete Landmark Path algorithm which will be used to calculate the betweenness centrality mapping what airports are most important.

December 6 - Write final tests, complete final debugging, and complete final presentation/other deliverables.
