/*******************************************************************************************
*
*   raylib [core] example - basic window
*
*   This example has been created using raylib 1.0 (www.raylib.com)
*   raylib is licensed under an unmodified zlib/libpng license (View raylib.h for details)
*
*   Copyright (c) 2013-2016 Ramon Santamaria (@raysan5)
*
********************************************************************************************/

#include "raylib.h"
#include <vector>
#include <algorithm>
#include <iostream>

struct Node;

struct Edge 
{
	Node* target;
	float cost;
};

struct Node 
{
	Vector2 position;

	float gScore;
	float hScore;
	float fScore;
	Node* previous;

	std::vector<Edge> connections;
};

int heuristic(Node * currentNode, Node * goal)
{
	return abs(currentNode->position.x - goal->position.x) + abs(currentNode->position.y - goal->position.y);
}

std::vector<Node*> aStarSearch(Node* startNode, Node* endNode)
{
	//Validate the input
	if (startNode == nullptr || endNode == nullptr) {
		return std::vector<Node*>();
	}

	if (startNode == endNode) {
		std::vector<Node*> singleNodePath;
		singleNodePath.push_back(startNode);
		return singleNodePath;
	}

	//Initialize the starting node
	startNode->gScore = 0;
	startNode->previous = nullptr;

	//Create our temporary lists for storing nodes
	std::vector<Node*> openList;
	std::vector<Node*> closedList;

	//Add the starting node to openList
	openList.push_back(startNode);

	while (!openList.empty())
	{

	}
}

int main()
{
	// Initialization
	//--------------------------------------------------------------------------------------
	int screenWidth = 800;
	int screenHeight = 450;

	InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

	SetTargetFPS(60);
	//--------------------------------------------------------------------------------------

	// Main game loop
	while (!WindowShouldClose())    // Detect window close button or ESC key
	{
		// Update
		//----------------------------------------------------------------------------------
		// TODO: Update your variables here
		//----------------------------------------------------------------------------------

		// Draw
		//----------------------------------------------------------------------------------
		BeginDrawing();

		ClearBackground(RAYWHITE);

		DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);

		EndDrawing();
		//----------------------------------------------------------------------------------
	}

	// De-Initialization
	//--------------------------------------------------------------------------------------   
	CloseWindow();        // Close window and OpenGL context
	//--------------------------------------------------------------------------------------

	return 0;
}