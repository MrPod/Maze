#pragma once


struct Cell
{
  int connected_vertex_amount = 0, connected_vertexes[4];
};

struct Edge
{
  int start, end, weight;
};

const double AE = 0.08;

Cell** Maze_Builder( int A, int B );
void Game(Cell** paths, int A, int B);
