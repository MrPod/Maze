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
  Game(spanning_tree, a, b);


  for (int i = 0; i < a * b; i++)
    delete[] spanning_tree[i];
  delete[] spanning_tree;
}
