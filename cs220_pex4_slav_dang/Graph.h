/** Graph.h
 * ===========================================================
 * Name: CS220, Spring 2018
 * Modified by: Tricia Dang and Maya Slavin
 * Section: M3/M4
 * Project: PEX4
 * Purpose: The definition of a graph.
 * ===========================================================
 */

#ifndef GRAPH_H
#define GRAPH_H

#include<stdlib.h>
#define NUM_GRAPH_NODES  5

typedef struct graph{
	int    numberVertices;
	void * vertices;  // Array of nodes
	int ** edges;     // Adjacency matrix (2D Array)
} Graph;

typedef struct path {
	int vertices[NUM_GRAPH_NODES];	  //An array of vertex indexes
} Path;

/** -------------------------------------------------------------------
 * Create the memory needed to hold a graph data structure.
 * @param numberVertices the number of vertices in the graph
 * @param bytesPerNode the number of bytes used to represent a
 *                     single vertex of the graph
 * @return a pointer to a graph struct
 */
Graph * graphCreate(int numberVertices, int bytesPerNode);

/** -------------------------------------------------------------------
 * Delete a graph data structure
 * @param graph the graph to delete
 */
void graphDelete(Graph *graph);

/** -------------------------------------------------------------------
 * Set the state of an edge in a graph
 * @param graph the graph to modify
 * @param fromVertex the beginning vertex of the edge
 * @param toVertex the ending vertex of the edge
 * @param state the state of the edge
 */
void graphSetEdge(Graph *graph, int fromVertex, int toVertex, int state);

/** -------------------------------------------------------------------
 * Get the state of an edge in a graph
 * @param graph the graph
 * @param fromVertex the starting vertex of the edge
 * @param toVertex the ending vertex of the edge
 * @return the state of the edge
 */
int graphGetEdge(Graph *graph, int fromVertex, int toVertex);

/** -------------------------------------------------------------------
 * Creates an a path structure
 * @return path - a structure containing an array
 */
Path* createpath();

#endif // GRAPH_H