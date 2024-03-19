#include "init.h"
#include "draw.h"
#include "update.h"
#include "reset_game.h"
#include "reset_lines.h"
#include "check_input.h"
#include "delete_lines.h"
#include "blink_animation.h"
#include "check_collision.h"
#include "tetris_global_variables.h"

int main(int argc, char **argv, char **environ)
{
    InitWindow(window_width, window_height, "Title");
    InitAudioDevice();

    init_game();

    while (!WindowShouldClose())
    {
        if (!game_over)
        {
            update_game();
            blink_animation();

            BeginDrawing();
            ClearBackground(BLACK);
            draw();
        }
        else
        {
            reset_game();
        }

        EndDrawing();
    }

    CloseAudioDevice(); // Close audio device
    CloseWindow();      // Close window

    return 0;
}
