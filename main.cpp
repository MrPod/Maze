#include <cstdio>
#include <conio.h>
#include <cstdlib>
#include <iostream>
#include "Maze.h"
#include <vld.h>

void main(void)
{
	Cell **Maze ;
	int n, m;
	bool flag = true;
	//bool win = false;
	int level = 0;
	std::cout << "Input demenitions of maze \n";
	//while(flag)
	std::cout << "Input height(height should be > 3):";
	std::cin >> n;
	std::cout << "Input width(widht should be > 3):";
	std::cin >> m;
	//Придумать, как можно менять сложность лабиринта!!
	// как один из вариантов  сложность = количесвтво пройденых клеток до выхода 
	// количесвто путей до выхода 
	// количесвто поворотов 

	FormMaze(n, m, Maze, level);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			std::cout << " " << (Maze[i][j].left ? 1 : 0) << " ";
			std::cout << " " << (Maze[i][j].up ? 1 : 0) << " ";
			std::cout << " " << (Maze[i][j].right ? 1 : 0) << " ";
			std::cout << " " << (Maze[i][j].down ? 1 : 0) << "    ";
		}
		std::cout << std::endl;
	}
	std::cout << "\n\n\n\n";
	Cell **Test_Maze = new Cell*[3];
	for (int i = 0; i < 3; i++)
		Test_Maze[i] = new Cell[3];
	//CreateTestMaze(Test_Maze, 3, 3);
	Test_Maze[0][0] = { true, true, false, true };
	Test_Maze[0][1] = { false, true, true, false };
	Test_Maze[0][2] = { true, true, false, false };
	Test_Maze[1][0] = { true, true, true, false };
	Test_Maze[1][1] = { true, false, true, false };
	Test_Maze[1][2] = { true, false, true, false };
	Test_Maze[2][0] = { true, false, false, true };
	Test_Maze[2][1] = { false, false, false, true };
	Test_Maze[2][2] = {  false, false, true, true };
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			std::cout << " " << (Test_Maze[i][j].left ? 1 : 0) << " ";
			std::cout << " " << (Test_Maze[i][j].up ? 1 : 0) << " ";
			std::cout << " " << (Test_Maze[i][j].right ? 1 : 0) << " ";
			std::cout << " " << (Test_Maze[i][j].down ? 1 : 0) << "    ";
		}
		std::cout << std::endl;
	}
	//Chоверка связности тестового лабиринта
	bool **Visited = new bool*[n];
	for (int i = 0; i < n; i++)
		Visited[i] = new bool[m];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			Visited[i][j] = false;
	//Visited[0][0] = true;
	int Colored = 0; 
	if (n*m > Check(Test_Maze, 0, 0, Colored, Visited, n, m))
		std::cout << "NE SVZZNYI\n";
	else 
		std::cout << "SVZZNYI\n";
	//конец прверки
	Game(Test_Maze, 3, 3);
	for (int i = 0; i < n; i++)
		delete[] Visited[i];
	delete[] Visited;
	Visited = nullptr;
	for (int i = 0; i < 3; i++)
		delete[] Test_Maze[i];
	delete[] Test_Maze;
	Test_Maze = nullptr;
	
	for (int i = 0; i < n; i++)
		delete[] Maze[i];
	delete[] Maze;
	Maze = nullptr;
}