#include "dijkstra.h"
#include <stdbool.h>

// Find the node with the smallest distance from the unvisited node
int minDistance(int dist[], bool visited[], int numCities) {
    int min = INF;
    int min_index = -1;

    for (int v = 0; v < numCities; v++) {
        if (visited[v] == false && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}

// Print the Path recursively
void printPathRecursively(Graph *g, int currentVertex, int parent[]) {
    if (currentVertex == -1) {
        return;
    }
    printPathRecursively(g, parent[currentVertex], parent);
    printf("\t%s\n", g->cities[currentVertex].name);
}

// Using Dijkstra's algorithm to find the shortest path
void findShortestPath(Graph *g, int startID, int endID) {
    int numCities = g->numCities;

    // saves the shortest distance from startID to i
    int *dist = malloc(sizeof(int) * numCities);

    // If true, the shortest path to the point has been determined
    bool *visited = malloc(sizeof(bool) * numCities);

    // Saves the precursor node of i in the path for backtracking the path
    int *parent = malloc(sizeof(int) * numCities);

    // initialize
    for (int i = 0; i < numCities; i++) {
        dist[i] = INF;
        visited[i] = false;
        parent[i] = -1;
    }
    
    // The distance to itself is 0
    dist[startID] = 0;
    
    // Find the shortest path for all nodes
    for (int count = 0; count < numCities - 1; count++) {
        int u = minDistance(dist, visited, numCities);

        //Break if the path cannot be found or the node is at the end. 
        if (u == -1 || dist[u] == INF) break;
        if (u == endID) break; 

        visited[u] = true;

        // Update the u's adjacent point v
        for (int v = 0; v < numCities; v++) {
            // if v has not been visited and there exists a shorter edge between two vertices u and v. 
            if (!visited[v] && 
                g->adjMatrix[u][v] != INF && 
                dist[u] != INF && 
                dist[u] + g->adjMatrix[u][v] < dist[v]) {        
                dist[v] = dist[u] + g->adjMatrix[u][v];
                parent[v] = u;
            }
        }
    }


    // print out result
    if (dist[endID] == INF) {
        printf("Path Not Found...\n");
    } else {
        printf("Path Found...\n");
        printPathRecursively(g, endID, parent);
        printf("Total Distance: %d\n", dist[endID]);
    }


    // free storage
    free(dist);
    free(visited);
    free(parent);
}
