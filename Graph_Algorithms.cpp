#include <cstdio>
#include <ctime>
#include <iostream>

#include "Graph_Algorithms.h"


int* merge_trees( Edge** mst, const int edge_amount, int mst_prev_edge, int mst_edge, int* leader, const int vertex_amount, int& leader_amount )
{
  int initial_leader_amount = leader_amount;
  for (int i = mst_prev_edge; i < mst_edge; i++)
  {
    // checks whether 2 different components have a common edge and connects them
    int component_a = leader[mst[i]->end], component_b = leader[mst[i]->start];
    for (int j = 0; j < vertex_amount; j++)
      if (leader[j] == component_a && component_a != component_b)
        leader[j] = component_b;
    leader_amount--;
  }

  // reduces the amount of disconnected components
  int* arr = new int[leader_amount] {leader[0]}, amount = 1;

  for (int i = 0; i < initial_leader_amount; i++)
    if (arr[amount] < leader[i] && arr[amount - 1] != leader[i])
    {
      arr[amount++] = leader[i];
      break;
    }

  return arr;
}

Cell** Maze_Builder( int A, int B )
{
  /*
  * edges_amount     - amount of the edges in the graph
  * leader           - array of different connected components of the graph, value - the 'leader' of the component
  * leader_amount    - amount of disconnected components of the graph
  * mst_edges        - amount of edges, that are in minimal spinning tree
  * trees            - array of disconnected components of the graph, value - the 'leader' of the component
  * additional_edges - amount of edges to add to the amount of the edges in the minimal spinning tree
  * paths            - vertexes available to go to from another vertex (last array cell is for amount of connected vertexes)
  * mst              - array of pointers to EDGES, where the minimal spinning tree is stored
  * edges            - array of pointers to EDGES, where every edge of the graph is stored
  */
  int edges_amount = 0, *leader = new int[A * B], leader_amount = A * B, mst_edges = 0, *trees = new int[A * B], additional_edges = static_cast<int>((2 * A * B - A - B) * AE + 0.5);
  Edge** mst = new Edge*[A * B - 1 + additional_edges], ** edges = new Edge*[2 * A * B - A - B];
  Cell** paths = new Cell*[A * B];

  srand( time( nullptr ) );

  for (int i = 0; i < A * B; i++)
  {
    trees[i] = leader[i] = i;
    paths[i] = new Cell{ 0, 0 };
  }

  for (int i = 0; i < A * B - 1 + additional_edges; i++)
    mst[i] = new Edge{ 0 };

  for (int i = 0; i < 2 * A * B - A - B; i++)
    edges[i] = new Edge{ 0 };

  for (int i = 0; i < A * B - 1; i++)
  {
    int h = rand() % (A * B) + 1, v = rand() % (A * B) + 1;
    if ((i + 1) % B)
    {
      edges[edges_amount]->start = i; // adds a path between two vertexes horizontaly
      edges[edges_amount]->end = i + 1;
      edges[edges_amount++]->weight = h;
    }
    if (i + B < A * B)
    {
      edges[edges_amount]->start = i; // adds a path between two vertexes vertically
      edges[edges_amount]->end = i + B;
      edges[edges_amount++]->weight = v;
    }
  }

  
  int *links = new int[edges_amount] {0};

  while (leader_amount > 1)
  {
    int mst_prev_edges = mst_edges;
    for (int i = 0; i < leader_amount; i++)
    {
      int cheapest = -1;
      for (int j = 0; j < edges_amount; j++) // finds the cheapest way between two different components
        if (((leader[edges[j]->start] != trees[i] && leader[edges[j]->end] == trees[i]) ||   // if in different components
          (leader[edges[j]->end] != trees[i] && leader[edges[j]->start] == trees[i])) && // another ends
              (cheapest == -1 || edges[j]->weight < edges[cheapest]->weight))
          cheapest = j;

      if (!links[cheapest]) // checks whether the path is traversed
      {
        *mst[mst_edges++] = *edges[cheapest]; // adds this path into the spanning tree

        int start = edges[cheapest]->start, end = edges[cheapest]->end;

        // Adds an available vertex to go to
        paths[start]->connected_vertexes[paths[start]->connected_vertex_amount++] = end;
     
        // Adds an available vertex to go to
        paths[end]->connected_vertexes[paths[end]->connected_vertex_amount++] = start;
     
        links[cheapest] = 1;
      }
    }
    delete[] trees;
    trees = merge_trees( mst, edges_amount, mst_prev_edges, mst_edges, leader, A * B, leader_amount ); // merge components with a common edge into one
  }

  for (int i = 0; i < additional_edges; i++)
  {
    int new_edge = rand() % edges_amount; // chooses random edge from not traversed
    if (links[new_edge])
      i--;
    else
    {
      *mst[mst_edges++] = *edges[new_edge];

      int start = edges[new_edge]->start, end = edges[new_edge]->end;

      // Adds an available vertex to go to
      paths[start]->connected_vertexes[paths[start]->connected_vertex_amount++] = end;
      
      // Adds an available vertex to go to
      paths[end]->connected_vertexes[paths[end]->connected_vertex_amount++] = start;

      links[new_edge] = 1;
    }
  }

  // Massive deletetion of allocated memory
  for (int i = 0; i < 2 * A * B - A - B; i++)
    delete[] edges[i];
  delete[] edges;

  for (int i = 0; i < A * B - 1 + additional_edges; i++)
    delete[] mst[i];
  delete[] mst;

  delete[] trees;
  delete[] leader;
  delete[] links;


  return paths;
}
