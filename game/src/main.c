#include "raylib.h"
#include "Body.h"
#include "Mathf.h"
#include "raymath.h"
#include "World.h"
#include <stdlib.h>
#include <assert.h>

#define MAX_BODIES 100
int main(void)
{
	InitWindow(1280, 720, "Physics Engine");
	SetTargetFPS(60);


	//game loop
	while (!WindowShouldClose())
	{
		//update 
		float dt = GetFrameTime();
		float fps = (float)GetFPS();

		Vector2 position = GetMousePosition();
		if (IsMouseButtonDown(0))
		{
			Body* body = CreateBody();
			body->position = position;
			body->velocity = CreateVector2(GetRandomFloatValue(-5,5),GetRandomFloatValue(-5,5));
		}

		//draw
		BeginDrawing();
		ClearBackground(BLACK);

		DrawCircle((int)position.x, (int)position.y, 10, BLUE);

		//update bodies
		// update / draw bodies
		Body* body = bodies;
		while (body) // do while we have a valid pointer, will be NULL at the end of the list
		{
			// update body position
			// draw body
			body->position = Vector2Add(body->position, body->velocity);
			DrawCircle((int)body->position.x, (int)body->position.y, 10, RED);

			body = body->next; // get next body
		}
		//stats
		DrawText(TextFormat("FPS: %.2f (%.2fms)", fps,1000/fps), 10, 10, 20, LIME);
		DrawText(TextFormat("FRAME: %.4f", dt), 10, 30, 20, LIME);

		EndDrawing();
	}
	CloseWindow();
	return 0;
}