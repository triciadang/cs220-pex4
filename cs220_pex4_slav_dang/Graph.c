/** Graph.c
 * ===========================================================
 * Name: CS220, Spring 2018
 * Modified by: Tricia Dang, Maya Slavin
 * Section: M3/M4
 * Project: PEX4
 * Purpose: The implementation of a graph.
 * ===========================================================
 */

#include <stdlib.h>
#include <stdio.h>
#include <memory.h>
#include <math.h>
#include "Graph.h"
#include "gameLogic.h"

/** -------------------------------------------------------------------
 * Create the memory needed to hold a graph data structure.
 * @param numberVertices the number of vertices in the graph
 * @param bytesPerNode the number of bytes used to represent a
 *                     single vertex of the graph
 * @return a pointer to a graph struct
 */
Graph * graphCreate(int numberVertices, int bytesPerNode) {
    Graph *graph = malloc(sizeof(Graph));
    graph->numberVertices = numberVertices;
    graph->vertices = malloc(numberVertices * bytesPerNode);
    graph->edges = malloc(numberVertices * sizeof(int *));

// Create each row of the adjacency matrix
    for (int j=0; j < numberVertices; j++) {
        graph->edges[j] = (int *) malloc( numberVertices * sizeof(int));
    }

    // Set every edge to FALSE
    for (int row = 0; row < graph->numberVertices; row++) {
        for (int col = 0; col < graph->numberVertices; col++) {
            graph->edges[row][col] = 0;
        }
    }

    return graph;
}

/** -------------------------------------------------------------------
 * Delete a graph data structure
 * @param graph the graph to delete
 */
void graphDelete(Graph * graph) {
    // delete each edge and vertex and then the whole graph
    free(graph->edges);
    free(graph->vertices);
    free(graph);
}

/** -------------------------------------------------------------------
 * Set the state of an edge in a graph
 * @param graph a pointer to the graph to modify
 * @param fromVertex the beginning vertex of the edge
 * @param toVertex the ending vertex of the edge
 * @param state the state of the edge
 **/
void graphSetEdge(Graph * graph, int fromVertex, int toVertex, int state) {
    graph->edges[fromVertex][toVertex] = state;
}

/** -------------------------------------------------------------------
 * Get the state of an edge in a graph
 * @param graph the graph
 * @param fromVertex the starting vertex of the edge
 * @param toVertex the ending vertex of the edge
 * @return the state of the edge
 **/
int graphGetEdge(Graph * graph, int fromVertex, int toVertex) {
    int state = graph->edges[fromVertex][toVertex];
    return state;
}

/** -------------------------------------------------------------------
 * Creates an a path structure
 * @return path - a structure containing an array
 */
Path* createpath() {
    Path* path = malloc(sizeof(Path));
    return path;
}