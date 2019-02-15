#include "Maze.h"

Cell **FormMaze(int n, int m, Cell **&Maze, int level)
{
	Cell **tmp = new Cell*[n];
	for (int i = 0; i < n; i++)
		tmp[i] = new Cell[m];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			tmp[i][j].left = false;
			tmp[i][j].up = false;
			tmp[i][j].right = false;
			tmp[i][j].down = false;
		}

	for ( int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			if (i == 0)
				tmp[i][j].up = true; 
			if (j == 0)
				tmp[i][j].left = true;		// боковые стенки лабиринта 
			if (j == m - 1)
				tmp[i][j].right = true;
			if (i == n - 1)
				tmp[i][j].down = true;
		}
	//алгоритм формирования внутренних стенок лабиринта !!
	//Адгоритм проверки связности 
	bool **Visited = new bool*[n];
	for (int i = 0; i < n; i++)
		Visited[i] = new bool[m];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			Visited[i][j] = false;
	//Visited[0][0] = true;
	//if (n*m > Check(tmp, 0, 0, 0, Visited, n, m)
		//возвращаем удаленное ребро( убираем стенку )

	for (int i = 0; i < n; i++)
		delete[] Visited[i];	//	чистим память из-под Visited
	delete[] Visited;
	Visited = nullptr;

	Maze = tmp;
	return Maze;
}

int CreateTestMaze(Cell **&Test_Maze, int n, int m)
{
	Test_Maze[0][0] = { true, true, false, false };
	return 1;
}

