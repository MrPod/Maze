#include "Maze.h"
#include <cstdio>
#include <cstdlib>
#include <conio.h>
#include <ctime>
#include <iostream>

int Game(Cell **Maze, int n, int m)
{
	bool win = false;
	int x, y;
	srand(time(NULL));
	x = rand() % n;
	y = rand() % m;
	char c;
	while (win != true)
	{
		std::cin >> c;
		switch (c)
		{
			case 'w':								                 //      0  1  2 ...
				if (y == 0 && Maze[y][x].up == false)                // 0  | ----------->
					win = true;						                 // 1  |			  x
				else if (Maze[y][x].up == false)	                 // 2  |  
				{									                 // ...v y 
					y--;							                 //		
					printf("Ok\n");					                 
				}
				else
					printf("wall\n");
				break;
			case 'W':
				if (y == 0 && Maze[y][x].up == false)
					win = true; 
				else if (Maze[y][x].up == false)
				{
					y--;
					printf("Ok\n");
				}
				else
					printf("wall\n");
				break;
			case 'a':
				if (x == 0 && Maze[y][x].left == false)
					win = true;
				else if (Maze[y][x].left == false)
				{
					x--;
					printf("Ok\n");
				}
				else
					printf("wall\n");
				break;
			case 'A':
				if (x == 0 && Maze[y][x].left == false)
					win = true;
				else if (Maze[y][x].left == false)
				{
					x--;
					printf("Ok\n");
				}
				else
					printf("wall\n");
				break;
			case 's':
				if ((y == m - 1) && Maze[y][x].down == false)
					win = true;
				else if (Maze[y][x].down == false)
				{
					y++;
					printf("Ok\n");
				}
				else
					printf("wall\n");
				break;
			case 'S':
				if ((y == m - 1) && Maze[y][x].down == false)
					win = true;
				else if (Maze[y][x].down == false)
				{
					y++;
					printf("Ok\n");
				}
				else
					printf("wall\n");
				break;
			case 'd':
				if ((x == n - 1)  && Maze[y][x].right == false)
					win = true;
				else if (Maze[y][x].right == false)
				{
					x++;
					printf("Ok\n");
				}
				else
					printf("wall\n");
				break;
			case 'D':
				if ((x == n - 1) && Maze[y][x].right == false)
					win = true;
				else if (Maze[y][x].right == false)
				{
					x++;
					printf("Ok\n");
				}
				else
					printf("wall\n");
				break;
			/*case 'w':
				break;
			case 'w':
				break;
			case 'w':
				break;
				case 'w':
				break;*/
			default:
				printf("wrong symbol ? try again \n");
		}



	}
	printf("YOU WIN!!!!\n");
	return 0;
}


