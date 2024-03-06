#include "check_input_and_collision.h"
#include "clear_lines.h"

int check_collision(const int tetrominoStartX, const int tetrominoStartY, const int *tetromino)
{
    for(int y = 0; y < TETROMINO_SIZE; y++)
    {
        for(int x = 0; x < TETROMINO_SIZE; x++)
        {
            const int offset = y * TETROMINO_SIZE + x;

            if(tetromino[offset] == 1)
            {
                const int offset_stage = (y + tetrominoStartY) * STAGE_WIDTH + (x +tetrominoStartX);

                if (stage[offset_stage] != 0)
                {
                    return 1;
                }
            }
        }
    }

    return 0;
}

void check_input()
{
    if (IsKeyPressed(KEY_SPACE))
    {
        const int lastRotation = current_rotation;

        current_rotation++;

        if (current_rotation > 3)
        {
            current_rotation = 0;
        }

        PlaySound(rotate_sound);
        if (check_collision(current_tetromino_x, current_tetromino_y, tetromino_types[current_tetromino_type][current_rotation]))
        {
            current_rotation = lastRotation;
            StopSound(rotate_sound);
        }
    }
    if (IsKeyPressed(KEY_RIGHT))
    {
        // No need to check overflow, wall is your protector
        if (!check_collision(current_tetromino_x + 1, current_tetromino_y, tetromino_types[current_tetromino_type][current_rotation]))
        {
            current_tetromino_x++;
        }
    }
    if (IsKeyPressed(KEY_LEFT))
    {
        // No need to check overflow, wall is your protector
        if (!check_collision(current_tetromino_x - 1, current_tetromino_y, tetromino_types[current_tetromino_type][current_rotation]))
        {
            current_tetromino_x--;
        }
    }
    if (time_to_move_tetromino_down <= 0 || IsKeyPressed(KEY_DOWN))
    {
        if (!check_collision(current_tetromino_x, current_tetromino_y + 1, tetromino_types[current_tetromino_type][current_rotation]))
        {
            current_tetromino_y++;
            time_to_move_tetromino_down = move_tetromino_down_timer;
        }
        else
        {
            for (int y = 0; y < TETROMINO_SIZE; y++)
            {
                for (int x = 0; x < TETROMINO_SIZE; x++)
                {
                    const int offset = y * TETROMINO_SIZE + x;

                    const int *tetromino = tetromino_types[current_tetromino_type][current_rotation];

                    if (tetromino[offset] == 1)
                    {
                        const int offset_stage = (y + current_tetromino_y) * STAGE_WIDTH + (x + current_tetromino_x);

                        stage[offset_stage] = 2; // Tetrominos value in the stage[] after collision
                        PlaySound(drop_sound);
                    }
                }
            }

            delete_lines(completed_lines_y_index);

            current_tetromino_x = tetromino_start_x;
            current_tetromino_y = tetromino_start_y;

            current_tetromino_type = GetRandomValue(0, 6);
            current_rotation = 0;
            current_color = GetRandomValue(0, 6);
        }
    }
}