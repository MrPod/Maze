#include <cstdio>
#include <iostream>
#include <conio.h>
#include <vld.h>

#include "Graph_Algorithms.h"


void main( void )
{
  int a, b;
  std::cin >> a >> b; // a - vertical, b - horizontal dimensions


  Cell** spanning_tree = Maze_Builder( a, b );
  /*for (int i = 0; i < a * b - 1; i++)
    std::cout << "Edge from " << spanning_tree[i]->start << " to " << spanning_tree[i]->end << " with weight " << spanning_tree[i]->weight << "\n";*/

  for (int i = 0; i < a * b; i++)
  {
    printf( "\nVertexes connected to %d are: ", i );
    for (int j = 0; j < spanning_tree[i]->connected_vertex_amount; j++)
      printf( "%d   ", spanning_tree[i]->connected_vertexes[j] );
  }
  printf("\n\n");


  Game(spanning_tree, a, b);


  for (int i = 0; i < a * b; i++)
    delete[] spanning_tree[i];
  delete[] spanning_tree;
}
