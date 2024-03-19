#include "reset_game.h"
#include "tetris_global_variables.h"
#include "init.h"

void reset_game()
{
    ClearBackground(WHITE);
    DrawText("PRESS [ENTER] TO PLAY AGAIN", GetScreenWidth() / 2 - MeasureText("PRESS [ENTER] TO PLAY AGAIN", 20) / 2, GetScreenHeight() / 2 - 50, 20, BLACK);
    if (IsKeyPressed(KEY_ENTER))
    {
        for (int y = 0; y < STAGE_HEIGHT - 1; y++)
        {
            int yOffset = y * STAGE_WIDTH + 1;
            int sizeToSet = (STAGE_WIDTH - 2) * sizeof(int);
            memset(&stage[yOffset], 0, sizeToSet);
        }
        unload_game_resources();
        init_game();
        game_over = 0;
    }
}

void unload_game_resources()
{
    StopMusicStream(music);
    UnloadMusicStream(music);
    UnloadSound(rotate_sound);
    UnloadSound(drop_sound);
    UnloadSound(line_clear_sound);
}