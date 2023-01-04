/*
You are given a directed graph of an airline network represented as an adjacency list.
For the test graph below, the entry {"CLT", {"JFK", "ORD"}} means there is a non-stop flight between CLT (Charlotte), 
and JFK (NYC), as well as between CLT and ORD (Chicago).  However, to fly from CLT to MIA (Miami) on this airline network, 
you would have to fly from CLT to ORD, and from ORD to DFW (Dalls), and DFW to MIA. That would be 2 stops.  Alterately, 
you could fly from ORD to LAX (LA), and LAX to MIA. There could be multiple such flight paths with varying number of intermediate stops. 

Problem: Given a graph representing an airline network, find the minimum number of stops to fly from starting city to destination city. A direct connection would be zero stops.

Do NOT modify the test. Note that your code should for any arbirtrary directed airline network, not just the one given in the test.
Include any additional STL libraries that you may need
Note: For full credit your code should be O(n + m) where n is the number of vertices, and m is the number of edges in the graph.
*/

#include <iostream>
#include <unordered_map>
#include <queue>
#include <vector>
#include <string>

int minStops(std::unordered_map<std::string, std::vector<std::string>>& aList, std::string v1, std::string v2) {
// Your code here
// I actually tried to do this with a basic hash map at first
// Did not work
std::queue<std::string> q;
std::unordered_map<std::string, bool> visit;
std::unordered_map<std::string, int> distance;

visit[v1] = true; // Visited Index Set as Source
distance[v1] = 0;
q.push(v1); // Adds Source Into Queue

while(!q.empty()){
    std::string currentIndex = q.front(); // Sets Front of Queue as Current Index
    q.pop(); // Checks another Index
    
    if (currentIndex == v2){ // Destination Index Reached
       return distance[currentIndex]-1;
    }

    for(auto&city : aList[currentIndex]){
    
    if (!visit[city]){ // Visits any Index not yet visited
        q.push(city);
        visit[city] = true;
        distance[city] = distance[currentIndex] + 1;
        }
    }
}
// returns minimum stops
return distance[v2] - distance[v1] - 1;
}


// Test
int main() {
	std::unordered_map<std::string, std::vector<std::string>> adjList{ {"CLT", {"JFK", "ORD"}},
	   											{"JFK", {"CLT", "LHR", "MUC"}}, 
												{"LHR", {"CDG", "ORD", "MUC"}},
												{"MUC", {"BCN", "LHR", "JFK"}},
												{"ORD", {"LHR", "LAX", "DFW"}},
												{"DFW", {"SLC", "MIA"}},
												{"LAX", {"ORD", "MIA"}},
												{"MIA", {"LAX"}},
												{"SLC", {"DFW"}}
												};
	std::cout << "Number of stop between CLT and LAX is " << minStops(adjList, "CLT", "LAX") << std::endl; // Should 1

	std::cout << "Number of stops between MIA and BCN " << minStops(adjList, "MIA", "BCN") << std::endl; // Should be 4

	return 0;
}



