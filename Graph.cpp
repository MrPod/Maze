#include "Maze.h"


int Check(Cell **Cell, int i, int j, int &Colored, bool **Visited, int n, int m)
{
	if (Visited[i][j] != true)
	{
		Visited[i][j] = true;
		Colored++;
	}
	if (i != 0 && Cell[i][j].up != true && Visited[i - 1][j] != true)
		Check(Cell, i - 1, j, Colored, Visited, n, m);
	if (i != n - 1  && Cell[i][j].down != true && Visited[i + 1][j] != true)
		Check(Cell, i + 1, j, Colored, Visited, n, m);
	if (j != 0 && Cell[i][j].left != true && Visited[i][j - 1] != true)
		Check(Cell, i, j - 1, Colored, Visited, n, m);
	if (j != m - 1 && Cell[i][j].right != true && Visited[i][j + 1] != true)
		Check(Cell, i , j + 1, Colored, Visited, n, m);
	return Colored;
}