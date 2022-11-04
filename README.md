# Team Contract & Final Project Proposal

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

For our final project we will use the OpenFlights dataset to see how people can be better connected using planes. We will find the most optimal path between the five best vacation spots according to US News (https://travel.usnews.com/rankings/worlds-best-vacations/) . These vacation spots include South Island, Paris, Maui, Bora Bora, Tahiti. In addition, we plan to calculate the most important airports and which airports are used the most. Using algorithms such as BFS search, DFS search, and AVL trees, we will create a website that is able to calculate the shortest path between the locations stated above, and also calculate which airports are considered the most important in the world currently.

## Dataset Acquisition and Processing

Each airport and route will be stored in a graph. We will have each airport as a node in our graph and the graph itself will be directed. To find the weight of each edge, we will use the distance between each airport. To aid in the implementation process, we will most likely use util files that will help with creating the graph and loading its data (all data will be loaded from OpenFlights). The first file we are extracting data from is routes.dat, which has all airports, airlines, flight information, beginning and ending airport ID, and much more information. This file has 67663 routes between 3321 airports on 548 airlines. The other file we are extracting data from is airports.dat which contains the name and ID of each airport, and also its location. For our project, we will use the starting and ending airports and their locations to calculate the distance as the weighted edge for our graph. After we parse through all the datasets, we can then create a page rank matrix. Then we can choose the top airports from a vector that contains the “rank” of each airport. Finally, we will traverse through our graph and map them on our application.

## Graph Algorithms/Description

To complete our algorithms, our first step is to create a graph with the airports in the data set and have an array of all the possible routes between them. This is important as we will have all the data possibly needed to complete the project stored in this graph. An important algorithm that is imperative for us to use to complete our tasks is Djikstra’s algorithm. Djikstra’s algorithm is an algorithm used in graphs to find the shortest path between nodes, and the use of this algorithm will be implemented when finding the shortest route between the 5 best vacation spots. A BFS traversal will also be important for us to use, as it will provide us with an algorithm that can traverse the graph and visit all the airports stored. This is how we will create the original graph with the airports, as stated above. Lastly, we are looking into the use of AVL trees or Binary search trees to come up with a way to store the possible paths between nodes. Using these structures will provide us with a way to store these paths, particularly in the form of an adjacency matrix. In addition, we can use the data stored in this adjacency matrix to calculate the most important/visited airports.

We can find the shortest path between any two airports by using Djikstra’s shortest path algorithm. Additionally, the project will require us to pass over multiple airports at a time, meaning we would use the Landmark Path algorithm to solve this task. Both algorithms would allow us to find the shortest path, however, the Landmark Path will be useful in finding the shortest path that includes certain airports that we may want to pass through. Ultimately, both algorithms will be used to create effective vacation spot routes for users. Additionally, we are going to use our Page Rank algorithm to map the top airports around the world to create a more useful UI for the user. To do this, we would need a node from the airport graph we created and a range of airports we want to create our adjacency matrix. Then we can figure out the top airports based on the calculated eigenvalues of our adjacency matrix.

We expect the Big O to be around O(V^2) (V is the number of verticies in our graph) because the most complex algorithm is Djikstra's shortest path.

## Timeline

November 9: Set-up github files and testing files. Create files for each algorithm used in the project and figure out the structure of the assignment. 

November 18: Implement the algorithm to find the shortest path between given nodes. This will be using Djikstra’s algorithm. Also, create the website to display the data onto.

November 31st: Complete Landmark Path algorithm which will be used to calculate the betweenness centrality mapping what airports are most important.

December 6 - Write final tests, complete final debugging, and complete final presentation/other deliverables.
