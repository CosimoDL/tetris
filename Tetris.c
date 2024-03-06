#include "tetris_global_variables.h"
#include "init.h"
#include "clear_lines.h"
#include "check_input_and_collision.h"
#include "draw.h"

void decrease_timer(float *timer,float decrease_value)
{
    *timer -= decrease_value;
}

void update_game()
{
    UpdateMusicStream(music); // Update music buffer with new stream data

    time_to_move_tetromino_down -= GetFrameTime();

    // Increase tetromino's speed
    if (lines_cleared >= 5 && move_tetromino_down_timer >= 0.25)
    {
        decrease_timer(&move_tetromino_down_timer, 0.05f);
        lines_cleared = 0;
    }

    check_input();

    // Check if the starting position for the new tetromino is occupied
    if (check_collision(tetromino_start_x, tetromino_start_y, tetromino_types[current_tetromino_type][current_rotation]))
    {
        game_over = 1;
    }
}

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
