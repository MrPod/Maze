#pragma once


struct Cell
{
  int connected_vertex_amount = 0, connected_vertexes[4];
};

struct Edge
{
  int start, end, weight;
};


const int N = 4, M = 4;
const double AE = 0.08;


bool Dijkstra( int begin, int end, int arr[N * M][N * M] );
int Li( int begin, int end, int arr[N * M][N * M] );
Cell** Maze_Builder( int A, int B );
void Game(Cell** paths, int A, int B);