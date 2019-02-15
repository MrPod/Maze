#pragma once
 struct Cell {
	bool left;
	bool up;
	bool right;
	bool down;
};


Cell **FormMaze(int n, int m, Cell **&Maze, int level);
int Game(Cell **Maze, int n, int m);
int CreateTestMaze(Cell **&Test_Maze, int n, int m);
int Check(Cell **, int i, int j, int &Colored, bool **Visited, int n, int m);