/** gameLogic.c
 * ===========================================================
 * Name: CS220, Spring 2018
 * Modified by: Tricia Dang and Maya Slavin
 * Section: M3/M4
 * Project: PEX4
 * Purpose: The implementation of functions needed to
 *          create a Shannon Switching Game.
 * ===========================================================
 */

#include <stdio.h>
#include <time.h>
#include <math.h>
#include "gameLogic.h"

#define MAXIMUM_TRIES_TO_SET_LOCATION     1000
#define MAXIMUM_TRIES_TO_CREATE_EDGE      1000
#define MAXIMUM_TRIES_TO_FIND_RANDOM_EDGE 5000
#define VERTEX_DRAW_RADIUS  5
#define CLICK_TOLERANCE 5.0

// The type of the two game players.
static int playerType[2] = {HUMAN_PLAYER, HUMAN_PLAYER};
static char * playerTypeNames[2] = {" (Human)", " (AI)"};

static int activePlayer = CUT_PLAYER;
static char * activePlayerName[] = { "Cut's turn", "Short's turn"};

// Local functions
static void setLocation(Vertex *vertex, int width, int height, int margin);
static int distance(Vertex *v1, Vertex *v2);
static int someVerticesTooClose(Vertex *vertices, int last, int minimumDistance);
static int compareVertices(const void * e1, const void * e2);
static int degree(Graph * graph, int index);
static void findEdge(Graph *graph, int mouseX, int mouseY, Edge *edge);
static int humanPlayer(Graph *graph, int mouseX, int mouseY);
static int aiPlayer(Graph * graph);

// Vertices are sorted according to their distance from the origin (0,0)
static Vertex origin = {0, 0, 0};


int min_vertex;



/** -------------------------------------------------------------------
 * Set the type of player.
 * @param player Either CUT_PLAYER or SHORT_PLAYER
 * @param type Either HUMAN_PLAYER or AI_PLAYER
 */
void setPlayerType(int player, int type) {
    if ( (player == CUT_PLAYER || player == SHORT_PLAYER) &&
         (type == HUMAN_PLAYER || type == AI_PLAYER) ) {
        playerType[player] = type;
    }
}

/** -------------------------------------------------------------------
 * Set the active player. This should be called only once at
 * the start of the game to determine who goes first.
 * @param player Either CUT_PLAYER or SHORT_PLAYER
 */
void setActivePlayer(int player) {
    if ( player == CUT_PLAYER || player == SHORT_PLAYER ) {
        activePlayer = player;
    }
}

/** -------------------------------------------------------------------
 * Create a set of random vertices for the game graph. The location
 * of each vertex must meet certain constraints:
 *    1) It must be inside the game window.
 *    2) It must be "margin" pixels aways from the window borders.
 *    3) It must be "minDistance" away from all other vertices.
 * @param graph the graph to modify
 * @param max_X the width of the window along the x axis
 * @param max_Y the height of the window along the y axis
 * @param margin the number of pixels to keep clear along all borders
 * @param minDistance the minimum distance between any two vertices
 * @param randomize if TRUE, the location of the vertices is random.
 *                  if FALSE, your get the same graph every time.
 */
void createVertices(Graph *graph, int max_X, int max_Y,
                    int margin, int minDistance, int randomize) {

    // Create a local variable to point to the vertex array to simplify the code.
    Vertex * vertices = (Vertex *) graph->vertices;

    if (randomize) {
        // Use the current time to randomize the random number generator.
        time_t t;
        srand((unsigned) time(&t));
    }

    // Set a random location for the first vertex.
    setLocation(vertices, max_X, max_Y, margin);

    // Set a random location for all the other vertices, but make sure they are
    // not too close to any of the other vertices that have already been created.
    int numberTries;
    int tooClose;
    for (int j = 1; j < graph->numberVertices; j++) {
        numberTries = 0;
        tooClose = TRUE;
        while (tooClose && numberTries < MAXIMUM_TRIES_TO_SET_LOCATION) {
            numberTries++;
            setLocation(vertices+j, max_X, max_Y, margin);

            tooClose = someVerticesTooClose(vertices, j, minDistance);
        }
        if (numberTries >= MAXIMUM_TRIES_TO_SET_LOCATION) {
            printf("ERROR in createVertices. Too many tries to create a new vertex.");
            exit(1);
        }
    }

    // Sort the vertices based on their distance from the origin (0,0)
    qsort(graph->vertices, (size_t) graph->numberVertices, sizeof(Vertex), compareVertices);

    // Make the first and last vertex the starting and ending vertices
    // of the Shannon switching game.
    vertices[0].type = STARTING_VERTEX;
    vertices[graph->numberVertices-1].type = ENDING_VERTEX;
}

/** -------------------------------------------------------------------
 * Set the location of a vertex.
 * @param vertex the vertex to change
 * @param width the width of the window
 * @param height the height of the window
 * @param margin the margins around the borders
 */
void setLocation(Vertex *vertex, int width, int height, int margin) {
    vertex->x = (rand() % (width  - (2 * margin))) + margin;
    vertex->y = (rand() % (height - (2 * margin))) + margin;
    vertex->type = NORMAL_VERTEX;
}

/** -------------------------------------------------------------------
 * Check to verify that a vertex is not too close to any of the other
 * vertices in the graph.
 * @param vertices the array of vertices
 * @param last the vertex to check
 * @param minimumDistance the minimum distance between two vertices
 * @return TRUE if the distance between vertices[last] and every
 *         other vertex is greater than minimumDistance.
 *         return FALSE otherwise.
 */
int someVerticesTooClose(Vertex * vertices, int last, int minimumDistance) {
    // Check to make sure vertices[last] is not too close to other vertices
    Vertex * lastVertex = vertices + last;
    int k = 0;
    while (k < last && distance(lastVertex, vertices+k) > minimumDistance) {
        k++;
    }
    return k < last; // TRUE if one vertex is less than minimumDistance away.
}

/** -------------------------------------------------------------------
 * Calculate the distance between two vertices
 * @param v1 vertex 1
 * @param v2 vertex 2
 * @return the distance between the two vertices
 */
int distance(Vertex *v1, Vertex *v2) {
    double dx = (double) v1->x - (double) v2->x;
    double dy = (double) v1->y - (double) v2->y;
    return (int) (sqrt(dx*dx + dy*dy));
}

/** -------------------------------------------------------------------
 * Compare two vertices. This is used by qsort to sort the vertices array.
 * @param e1 a pointer to a vertex
 * @param e2 a pointer to a vertex
 * @return -1 if e1 < e1; 0 if e1 == e2, +1 if e1 > e2
 */
int compareVertices(const void * e1, const void * e2) {
    Vertex * v1 = (Vertex *) e1;
    Vertex * v2 = (Vertex *) e2;
    int dist1 = distance(v1, &origin);
    int dist2 = distance(v2, &origin);
    if (dist1 < dist2)       return -1;
    else if (dist1 == dist2) return 0;
    else                     return 1;
}

/** -------------------------------------------------------------------
 * Create a set of random edges for a graph that meet the following
 * constraints:
 *   1) Each vertex can have [minNumberEdges, maxNumberEdges] edges
 *   2) Each edge must have a length that is less than
 *      edgeLengthPercent*max(windowWidth, windowHeight)
 * @param graph the graph to modify
 * @param minNumberEdges the minimum number of edges that each vertex must have
 * @param maxNumberEdges the maximum number of edges that each vertex can have
 * @param windowWidth the width of the game window
 * @param windowHeight the height of the game window
 * @param edgeLengthPercent limits the length of edges in the graph
 */
void createEdges(Graph * graph, int minNumberEdges, int maxNumberEdges,
                 int windowWidth, int windowHeight, double edgeLengthPercent) {
    Vertex * vertices = (Vertex *) graph->vertices;

    // The number of edges for each vertex is random within a range
    int edgeRange = (maxNumberEdges - minNumberEdges) + 1;
    int existingEdges;
    int desiredEdges;
    int edgesNeeded;
    int toVertex;

    // Restrict the edges to the close vertices by restricting the length
    // of an edge.
    int maxEdgeLength;
    if (windowWidth > windowHeight) {
        maxEdgeLength = (int) (windowWidth * edgeLengthPercent);
    } else {
        maxEdgeLength = (int) (windowHeight * edgeLengthPercent);
    }

    for (int nodeIndex = 0; nodeIndex < graph->numberVertices; nodeIndex++) {
        existingEdges = degree(graph, nodeIndex);
        desiredEdges = (rand() % edgeRange) + minNumberEdges;
        edgesNeeded = desiredEdges - existingEdges;
        for (int j = 0; j < edgesNeeded; j++) {
            toVertex = nodeIndex;
            int tries = 0;
            while (tries < MAXIMUM_TRIES_TO_CREATE_EDGE &&
                   toVertex == nodeIndex) {
                toVertex = rand() % graph->numberVertices;
                if (toVertex != nodeIndex) {
                    int existingEdge = graphGetEdge(graph, nodeIndex, toVertex);
                    if (existingEdge == NO_EDGE &&
                        distance(vertices + nodeIndex, vertices + toVertex) <= maxEdgeLength) {
                        break;
                    }
                }
                tries++;
            }
            if (tries > MAXIMUM_TRIES_TO_CREATE_EDGE) {
                printf("Error in createEdges. The maximum number of tries was exceeded.\n");
                exit(1);
            }
            graphSetEdge(graph, nodeIndex, toVertex, NORMAL_EDGE);

            //MYCHANGE
            graphSetEdge(graph, toVertex, nodeIndex, NORMAL_EDGE);

        }
    }
}

/** -------------------------------------------------------------------
 * Calculate the number of edges that are connected to a specific vertex.
 * @param graph the graph
 * @param index which vertex, an array index [0, graph->numberNodes-1]
 * @return the number of edges leaving vertex[index]
 */
int degree(Graph * graph, int index) {
    int count = 0;
    for (int j = 0; j < graph->numberVertices; j++) {
        if (graph->edges[index][j] > NO_EDGE) {
            count++;
        }
    }
    return count;
}


/** -------------------------------------------------------------------
 * Print the value that define a graph. Great for debuggin!
 * @param graph the graph
 */
void printGraph(Graph *graph) {
    Vertex * vertices = (Vertex *) graph->vertices;
    for (int j = 0; j < graph->numberVertices; j++){
        printf("VERTEX %3d:   X=%4d    Y=%4d  TYPE=%1d\n",
               j, vertices[j].x, vertices[j].y, vertices[j].type);
    }

    for (int j = 0; j < graph->numberVertices; j++){
        printf("FROM %d   TO: ", j);
        for (int k = 0; k < graph->numberVertices; k++) {
            printf(" %3d", graph->edges[j][k]);
        }
        printf("\n");
    }
}

/** -------------------------------------------------------------------
 * Draw the graph on the window.
 * @param graph the graph
 * @param hwnd handle to the window where the graph is to be drawn
 * @param labelVertices if TRUE, the array index of each vertex is displayed
 */
void drawGraph(Graph *graph, HWND hwnd, int labelVertices) {
    PAINTSTRUCT ps;
    HDC hdc = BeginPaint(hwnd, &ps);
    int brush;
    int pen;
    char textString[40];
    Vertex * vertices = (Vertex *) graph->vertices;

    clearBackground(hwnd, hdc, SOLID_THIN_WHITE, MY_WHITE_BRUSH);

    // Display the player's name and the player's type in the upper-left corner.
    if (game_status == 2) {
        strcpy(textString, "Cut player wins.");
        drawText(hdc, 3, 3, textString);
    }
    else if (game_status == 1){
        strcpy(textString, "Short player wins.");
        drawText(hdc, 3, 3, textString);
    }
    else{
        strcpy(textString, activePlayerName[activePlayer]);
        strcat(textString, playerTypeNames[playerType[activePlayer]]);
        drawText(hdc, 3, 3, textString);
    }

    // Draw the edges
    for (int from = 0; from < graph->numberVertices; from++) {
        for (int to = from+1; to < graph->numberVertices; to++) {
            if (graph->edges[from][to] > NO_EDGE) {
                if (graph->edges[from][to] == LOCKED_EDGE) {
                    // Draw a locked edge
                    pen = SOLID_THICK_RED;
                } else {
                    // Draw a normal edge
                    pen = SOLID_THIN_BLACK;
                }
                drawLine(hdc, vertices[from].x, vertices[from].y,
                              vertices[to].x,   vertices[to].y, pen);
            }
        }
    }

    // Draw the vertices
    for (int j = 0; j < graph->numberVertices; j++){
        if (vertices[j].type == NORMAL_VERTEX) {
            pen = SOLID_THIN_BLACK;
            brush = MY_BLACK_BRUSH;
        } else { // vertices[j].type == STARTING_VERTEX
            pen = SOLID_THIN_GREEN;
            brush = MY_GREEN_BRUSH;
        }

        drawCircle(hdc, vertices[j].x, vertices[j].y, VERTEX_DRAW_RADIUS, pen, brush);

        if (labelVertices) {
            sprintf(textString, "%d", j);
            drawText(hdc, vertices[j].x-20, vertices[j].y-20, textString);
        }
    }

    EndPaint(hwnd, &ps);
}

/** -------------------------------------------------------------------
 * Determine if a mouse click has selected a specific graph edge
 * @param x1 the starting coordinate (x1,y1) of the edge
 * @param y1
 * @param x2 the ending coordinate (x2,y2) of the edge
 * @param y2
 * @param mouseX the location of the mouse (mouseX, mouseY)
 * @param mouseY
 * @return TRUE if the mouse location is within CLICK_TOLERANCE pixels
 *         of any part of the edge. Return FALSE otherwise.
 */
int edgeClicked(int x1, int y1, int x2, int y2, int mouseX, int mouseY){
    double d = 10000.0;
    double onX, onY;  // The projection of the mouse onto the line segment
    double t; // parametric parameter for a line segment from (x1,y1) to (x2,y2)

    double dx = x2 - x1;
    double dy = y2 - y1;
    t=((mouseX-x1)*(x2-x1)+(mouseY-y1)*(y2-y1))/(dx*dx + dy*dy);
    if (t < 0 || t > 1.0) {
        // The projected point is not on the line segment
        return FALSE;
    } else {
        // Calculate the projected point.
        onX = x1 + dx * t;
        onY = y1 + dy * t;

        // Find the distance from the mouse to the projected point.
        double dx2 = mouseX - onX;
        double dy2 = mouseY - onY;
        double dist = sqrt(dx2 * dx2 + dy2 * dy2);

        return dist <= CLICK_TOLERANCE;
    }
}

/** -------------------------------------------------------------------
 * Find an edge that is within CLICK_TOLERANCE of the mouse location.
 * @param graph the graph
 * @param mouseX the location of the mouse (mouseX, mouseY)
 * @param mouseY
 * @param edge output of the function. If the edge is (-1,-1) then
 *             no edge was found. If the edge is (A,B) on return
 *             then the edge that goes from node A to node B was
 *             within CLICK_TOLERANCE of the mouse location.
 */
void findEdge(Graph *graph, int mouseX, int mouseY, Edge *edge) {

    // Assume that no edge can be found
    edge->fromVertex = -1;
    edge->toVertex = -1;

    Vertex * vertices = (Vertex *) graph->vertices;

    // Search all the edges and find the closest one
    for (int from = 0; from < graph->numberVertices; from++) {
        for (int to = 0; to < graph->numberVertices; to++) {
            if (graph->edges[from][to] == NORMAL_EDGE) {
                if (edgeClicked(vertices[from].x, vertices[from].y,
                               vertices[to].x,   vertices[to].y,
                               mouseX, mouseY) ) {
                    //printf("Found %3d %3d\n", from, to);
                    edge->fromVertex = from;
                    edge->toVertex = to;
                    return;
                }
            }
        }
    }
}

/** -------------------------------------------------------------------
 * Take a turn of the game by a human player. The location of the
 * user's mouse click is used to detemine the edge that is changed.
 * @param graph the graph
 * @param mouseX the location of the mouse (mouseX, mouseY)
 * @param mouseY
 * @return TRUE if the turn was taken. Return FALSE if the turn
 *         was not taken (e.g., if the user did not select an edge.)
 */
int humanPlayer(Graph *graph, int mouseX, int mouseY) {
    Edge edge;
    findEdge(graph, mouseX, mouseY, &edge);

    if (edge.fromVertex == -1) {
        // No edge was found; therefore this turn still needs
        // to be made.
        return FALSE;
    } else {
        if (activePlayer == SHORT_PLAYER) {
            graphSetEdge(graph, edge.fromVertex, edge.toVertex, LOCKED_EDGE);
            graphSetEdge(graph, edge.toVertex, edge.fromVertex, LOCKED_EDGE);


        } else { // activePlayer == CUT_PLAYER
            graphSetEdge(graph, edge.fromVertex, edge.toVertex, NO_EDGE);
            graphSetEdge(graph, edge.toVertex, edge.fromVertex, NO_EDGE);

        }
        return TRUE;
    }
}

/** -------------------------------------------------------------------
 * Make a move for an AI player.
 * @param graph the graph
 * @return TRUE if the turn was taken. Return FALSE if the turn
 *         was not taken.
 */
int aiPlayer(Graph * graph) {
    Path* ai_shortpath = dijkstra(graph);


    /**Short Player AI - For the short player AI, we locked the edge on the shortest path (which is found using
     * dijkstra's algorithm) that is closest to the ending vertex. The next turn, it will either follow along this
     * path or start a new one if a new shortest path is found.
     */
    if (activePlayer == SHORT_PLAYER) {
        int turn = 0; // turn is not taken
        int index = 0;
        while (turn == 0) {
            if (graphGetEdge(graph, ai_shortpath->vertices[index], ai_shortpath->vertices[index + 1]) == 1 &&
                    graph) {
                graphSetEdge(graph, ai_shortpath->vertices[index], ai_shortpath->vertices[index + 1], LOCKED_EDGE);
                graphSetEdge(graph, ai_shortpath->vertices[index+1], ai_shortpath->vertices[index], LOCKED_EDGE);
                turn = 1;
            }
            index++;
        }
    }

    /**Short Player AI - For the cut player AI, we took the same idea of the short player ai. We cut the edge on the
     * shortest path (which is found using dijkstra's algorithm) that is closest to the ending vertex. The next turn,
     * it will either follow along this path or start a new one if a new shortest path is found.
    */
    else { //activePlayer = CUT_PLAYER
        int turn = 0; // turn is not taken
        int index = 0;
        while (turn == 0) {
            if (graphGetEdge(graph, ai_shortpath->vertices[index], ai_shortpath->vertices[index + 1]) == 1) {
                graphSetEdge(graph, ai_shortpath->vertices[index], ai_shortpath->vertices[index + 1], NO_EDGE);
                graphSetEdge(graph, ai_shortpath->vertices[index+1], ai_shortpath->vertices[index], NO_EDGE);
                turn = 1;
            }
            index++;
        }
    }


    return TRUE;
}
/** -------------------------------------------------------------------
 * Take one turn in the Shannon Switching game. If the turn was successful,
 * the active player changes to the other player and the window is redrawn.
 * If the turn was not taken, the active player is unchanged and the window
 * is not redrawn.
 * @param graph the graph
 * @param mouseX the location of the mouse (mouseX, mouseY)
 * @param mouseY
 */
void doTurn(Graph *graph, int mouseX, int mouseY) {

    int turnIsDone = FALSE;

    if (playerType[activePlayer] == HUMAN_PLAYER) {
        turnIsDone = humanPlayer(graph, mouseX, mouseY);
    } else {
        turnIsDone = aiPlayer(graph);
    }


    if (turnIsDone) {
        activePlayer = 1 - activePlayer; // swap active player
        redraw();
    }


    /**Cut_Player wins: If the first value in the path array for the original adjacency matrix is a -1, this means that
     * there is no shortest path, or no path at all, that exists. Therefore, cut_player wins.**/
    Path *shortest_path = dijkstra(graph);
    Graph* locked_edge = locked_edge_graph(graph);
    Path* lockedpath_exists = dijkstra(locked_edge);

    if (shortest_path->vertices[0] == -1) {
        game_status = 2;
    }

    /**Short_Player wins: If the first value in the path array for the adjacency matrix that is composed only of locked
     * edges is a -1, this means that there is no shortest path through just the locked edges, that exists.
     * Therefore, short_player wins.**/
    else if(lockedpath_exists->vertices[0] != -1){
        game_status = 1;
    }
    else{
        game_status = 0;
    }
}

/** -------------------------------------------------------------------
 * Finds the shortest path using the dijkstra algorithm
 * @param graph the graph
 * @return shortest_path - an array of vertices that make up the shortest path
 */
Path* dijkstra (Graph* graph) {

    int alt;
    Path* shortest_path = createpath();


    int Q[graph->numberVertices];
    int dist[graph->numberVertices];
    int prev[graph->numberVertices];

    for (int v = 0; v < graph->numberVertices; v++) {
        dist[v] = 10000;
        prev[v] = -1;
        Q[v] = -1;
        shortest_path->vertices[v] = -1;
    }

    dist[0] = 0;

    int emptyset = 1;

    //while Q is not empty
    while (emptyset != 0) {

        //find min_vertex
        int min_dist = 100000000;
        for (int i = 0; i < graph->numberVertices; i++) {
            if (dist[i] < min_dist && Q[i] == -1) {
                min_dist = dist[i];
                min_vertex = i;
            }
        }
        Q[min_vertex] = 0; //Taken out of Q

        emptyset = 0;
        for (int i = 0; i < graph->numberVertices; i++) {
            if (Q[i] != 0) {
                emptyset = 1; //emptyset is TRUE when all Q not equal to 0
            }
        }

        //for each neighbor v of u
        for (int i = 0; i < graph->numberVertices; i++){
            if (graph->edges[min_vertex][i] == 1 | graph->edges[min_vertex][i] == 2) { //find neighbors of v
                if (Q[i] == -1) {// check to see if neighbor is still in Q
                    alt = dist[min_vertex] + 1;
                    if (alt < dist[i]){
                        dist[i] = alt;
                        prev[i]= min_vertex;
                    }
                }
            }
        }
    }
    //creates path
    int current_vertex = graph->numberVertices - 1;

    int i = 0;
    if (dist[current_vertex] < 10000){
        while (current_vertex != 0) {
            shortest_path->vertices[i] = current_vertex;
            current_vertex = prev[current_vertex];
            i++;
        }
        shortest_path->vertices[i] = 0;
    }
    else{
        shortest_path->vertices[0] = -1; //indicates that no path exists
    }

    return shortest_path;
}


/** -------------------------------------------------------------------
 * Finds all the locked edges and puts it in another adjacency matrix
 * @param graph the graph
 * @return locked_graph - a graph structure whose edge substructure is
 * the adjacency matrix with all locked edges
 */
Graph* locked_edge_graph (Graph* graph){
    Graph* locked_graph = graphCreate(graph->numberVertices, sizeof(Vertex));
    for (int u = 0; u< graph->numberVertices; u++){
        for (int v = 0; v< graph->numberVertices; v++){
            if (graphGetEdge(graph, u, v) == 2){
                locked_graph->edges[u][v] = 1;
            }
            else{
                locked_graph->edges[u][v] = 0;
            }
        }
    }
    return locked_graph;
}
