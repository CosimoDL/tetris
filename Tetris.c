#include "clear_lines.h"
#include "check_collision.h"
#include "tetris_global_variables.h"

void draw_tetromino(const Color current_color, const int start_offset_x, const int start_offset_y, const int tetromino_start_x, const int tetromino_start_y, const int *tetromino)
{
    for (int y = 0; y < TETROMINO_SIZE; y++)
    {
        for (int x = 0; x < TETROMINO_SIZE; x++)
        {
            const int offset = y * TETROMINO_SIZE + x;

            if (tetromino[offset] == 1)
            {
                DrawRectangle((x + tetromino_start_x) * TILE_SIZE + start_offset_x, (y + tetromino_start_y) * TILE_SIZE + start_offset_y, TILE_SIZE, TILE_SIZE, current_color);
            }
        }
    }
}

void decrease_timer(float *timer,float decrease_value)
{
    *timer -= decrease_value;
}

void blink_animation()
{
    //Blink Animation before reset
    if (blink_time_counter > 0 && blink_time_counter <= BLINK_TIMER)
    {
        if (blink_time_counter%8 < 4)
            blink_color = RED;
        else
            blink_color = MAROON;

        blink_time_counter++;
    }
    else
    {    
        blink_time_counter = 0;
    }

    if (blink_time_counter == BLINK_TIMER && completed_lines_y_index >= 0)
    {
        int index = 0;
        while (completed_lines_y_index[index] != -1 && index < MAX_MULTILINES_COMPLETE)
        {
            reset_lines(completed_lines_y_index[index]);
            completed_lines_y_index[index] = -1;
            index++;
        }
    }
}

void init_game()
{
    start_offset_x = (window_width / 2) - ((STAGE_WIDTH * TILE_SIZE) / 2);
    start_offset_y = (window_height / 2) - ((STAGE_HEIGHT * TILE_SIZE) / 2);

    tetromino_start_y = 0;
    tetromino_start_x = STAGE_WIDTH / 2;

    current_tetromino_x = tetromino_start_x;
    current_tetromino_y = tetromino_start_y;

    lines_completed = 0;
    lines_cleared = 0;
    blink_time_counter = 0;

    unix_time = 0;
    time(&unix_time);
    SetRandomSeed(unix_time);

    current_tetromino_type = GetRandomValue(0, 6);
    current_rotation = 0;

    move_tetromino_down_timer = 1.0f;
    time_to_move_tetromino_down = move_tetromino_down_timer;
    current_color = GetRandomValue(0, 6);

    //Load music/sound 
    music = LoadMusicStream("music\\tetris.mp3");
    rotate_sound = LoadSound("music\\tetris_rotate.mp3");
    line_clear_sound = LoadSound("music\\tetris_line_clear.mp3");
    SetSoundVolume(line_clear_sound,0.5f);
    drop_sound = LoadSound("music\\tetris_drop.mp3");
    music.looping = true;

    PlayMusicStream(music);
    SetMusicVolume(music, 0.05f);

    SetTargetFPS(60);
}

void unload_game_resources()
{
    StopMusicStream(music);
    UnloadMusicStream(music);
    UnloadSound(rotate_sound);
    UnloadSound(drop_sound);
    UnloadSound(line_clear_sound);
}

void checking_input()
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

    checking_input();

    // Check if the starting position for the new tetromino is occupied
    if (check_collision(tetromino_start_x, tetromino_start_y, tetromino_types[current_tetromino_type][current_rotation]))
    {
        game_over = 1;
    }
}

void draw_game()
{
    BeginDrawing();
    ClearBackground(BLACK);

    // Drawing the different tetrominos(Walls,Block)
    for (int y = 0; y < STAGE_HEIGHT; y++)
    {
        for (int x = 0; x < STAGE_WIDTH; x++)
        {
            const int offset = y * STAGE_WIDTH + x;

            if (stage[offset] == 1)
            {
                DrawRectangle(x * TILE_SIZE + start_offset_x, y * TILE_SIZE + start_offset_y, TILE_SIZE, TILE_SIZE, DARKGRAY); // Wall limits
            }
            else if (stage[offset] == 2)
            {
                DrawRectangle(x * TILE_SIZE + start_offset_x, y * TILE_SIZE + start_offset_y, TILE_SIZE, TILE_SIZE, DARKGREEN); // Block
            }
            else if (stage[offset] == 3)
            {
                DrawRectangle(x * TILE_SIZE + start_offset_x, y * TILE_SIZE + start_offset_y, TILE_SIZE, TILE_SIZE, blink_color); // Complete Line
            }

            DrawRectangleLines(x * TILE_SIZE + start_offset_x, y * TILE_SIZE + start_offset_y, TILE_SIZE, TILE_SIZE, WHITE); // Cells outlines
        }
    }

    draw_tetromino(color_types[current_color], start_offset_x, start_offset_y, current_tetromino_x, current_tetromino_y, tetromino_types[current_tetromino_type][current_rotation]);

    DrawText(TextFormat("Lines: %i", lines_completed), 470, 100, 20, YELLOW);
}

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
            draw_game();
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
