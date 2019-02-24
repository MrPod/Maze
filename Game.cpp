#include <cstdio>    // printf
#include <conio.h>   // _getch
#include <ctime>     // time
#include <iostream>
#include <windows.h> // sleep


#include "Graph_Algorithms.h"



void Game( Cell** paths, int A, int B )
{
  srand(time(NULL));
  int initial_vertex = (rand() % (A - 2) + 1) * B + (rand() % (B - 2) + 1), final_vertex = rand() % 2;

  if (final_vertex)
    final_vertex = rand() % A * B + rand() % 2 ? B - 1 : 0; // left \ right sides
  else
    final_vertex = rand() % B + rand() % 2 ? (A - 1) * B : 0; // up \ down sides


  std::cout << "Welcome to the MAZE!\nChoose the way to move yourself in the maze and good luck!\n";
  char* controls[] = { "WASD", "arrows" }, choice;
  for (int i = 0; i < sizeof(controls) / sizeof(controls[0]); i++)
    printf("  [%d] - %s\n", i, controls[i]);

  std::cin >> choice;
  bool chosen = choice == '0' ? 0 : 1;
  std::cout << "Now your controls are: " << controls[chosen] << "\n";
  Sleep(1000);
  std::cout << "Nah, I'm kidding - u can use both of them\nYour start point is " << initial_vertex << "\n\n";
  std::cin.ignore(32768, '\n');


  while (1)
  {
    if (initial_vertex == final_vertex)
    {
      std::cout << "Congrats! U win c:\n";
      _getch();
      break;
    }

    int key = _getch();
    if (key == 224)  // to handle the arrows (they return two values, one of them is 224)
      key = _getch();
    bool path = 0;

    switch (key)
    {
      case 119:
      case 72:
        std::cout << "U'r trying to go up\n";
        for (int i = 0; i < paths[initial_vertex]->connected_vertex_amount; i++)
          if (paths[initial_vertex]->connected_vertexes[i] == initial_vertex - B)
            path = 1;
        if (path)
        {
          initial_vertex -= B;
          std::cout << "Now u're at the point #" << initial_vertex << "\n\n";
        }
        else
          std::cout << "There is no way up\n\n";
        break;
      case 97:
      case 75:
        std::cout << "U'r trying to go left\n";
        for (int i = 0; i < paths[initial_vertex]->connected_vertex_amount; i++)
          if (paths[initial_vertex]->connected_vertexes[i] == initial_vertex - 1)
            path = 1;
        if (path)
        {
          initial_vertex--;
          std::cout << "Now u're at the point #" << initial_vertex << "\n\n";
        }
        else
          std::cout << "There is no way left\n\n";
        break;
      case 115:
      case 80:
        std::cout << "U'r trying to go down\n";
        for (int i = 0; i < paths[initial_vertex]->connected_vertex_amount; i++)
          if (paths[initial_vertex]->connected_vertexes[i] == initial_vertex + B)
            path = 1;
        if (path)
        {
          initial_vertex += B;
          std::cout << "Now u're at the point #" << initial_vertex << "\n\n";
        }
        else
          std::cout << "There is no way down\n\n";
        break;
      case 100:
      case 77:
        std::cout << "U'r trying to go right\n";
        for (int i = 0; i < paths[initial_vertex]->connected_vertex_amount; i++)
          if (paths[initial_vertex]->connected_vertexes[i] == initial_vertex + 1)
            path = 1;
        if (path)
        {
          initial_vertex++;
          std::cout << "Now u're at the point #" << initial_vertex << "\n\n";
        }
        else
          std::cout << "There is no way right\n\n";
        break;
      default:
        std::cout << "U hit the wrong button!\n\n";
        break;
    }
  }
}
