
/*
   === MoYuStudio 2022 ===
*/

#include <stdio.h>
#include <iostream>
#include <string>
#include "raylib.h"

using namespace std;

int window_size[] = { 1280, 720 };
char window_title[] = "TinyLand";

int block_width = 64;
int map_size = 3;
int block_map[3][3] = {
                        {0,0,0},
                        {0,0,0},
                        {0,0,0}
};

//for (int id = 0; 1 <= 5; id++)
//string id_str = id;
//string path = "./assets/block/" + id_str + ".png";



void block_rander(int x, int y)
{
    for (int id = 0; 1 <= 5; id++)
        string path = "./assets/block/"+to_string(id)+".png";

        Texture2D block_assets = LoadTexture(path);
        block_assets.width = block_width;
        block_assets.height = block_width;
        DrawTexture(block_assets, x, y, RAYWHITE);
}

void block_map_rander()
{

    for (int x = 0; x <= map_size; x ++)
        for (int y = 0; y <= map_size; y ++)
        {
            // self.rect.x = self.pos['z']*(self.width/2)-self.pos['x']*(self.width/2)+self.offset[0]
            // self.rect.y = self.pos['x']*(self.width/4)+self.pos['z']*(self.width/4)+self.offset[1]+(-self.width/2)*int(self.pos['y'])
            int rect_x = y * (block_width / 2) - x * (block_width / 2) + 200;
            int rect_y = x * (block_width / 4) + y * (block_width / 4) + 100;

            block_rander(rect_x, rect_y);

        };

}

int main(void)
{

    InitWindow(window_size[0], window_size[1], window_title);

    SetTargetFPS(60);
  
    while (!WindowShouldClose())
    {
        BeginDrawing();

        ClearBackground(BLANK);

        block_map_rander();
        DrawText("TinyLand C++ ReBuild Test", window_size[0]/2, window_size[1]/2, 20, LIGHTGRAY);

        EndDrawing();
    }
    // UnloadTexture(block);
    CloseWindow();        // Close window and OpenGL context

    return 0;
}