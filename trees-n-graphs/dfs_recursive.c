#include <stdio.h>
#include <stdlib.h>
#define G_SIZE 7
#define S_SIZE 30
// graph matrix repr
int a[G_SIZE][G_SIZE] = {
	{0, 1, 1, 1, 0, 0, 0},
	{1, 0, 0, 0, 1, 1, 0},
	{1, 0, 0, 0, 0, 0, 0},
	{1, 0, 0, 0, 0, 0, 0},
	{0, 1, 0, 0, 0, 0, 1},
	{0, 1, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 1, 0, 0}};

// DFS
int visited[G_SIZE] = {0, 0, 0, 0, 0, 0, 0}; // arr of visited node

void DFS(int node)
{
	printf("%d", node);
	visited[node] = 1;
	for (int j = 0; j < G_SIZE; j++) // checking connected and unvisited node
	{
		if (a[node][j] == 1 && visited[j] == 0)
		{
			DFS(j); // getting dfs of that node
		}
	}
}
int main()
{
	DFS(0); // passing source node
	return 0;
}