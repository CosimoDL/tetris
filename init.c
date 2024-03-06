#include "init.h"

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