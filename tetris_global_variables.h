#ifndef TETRIS_STAGE_TETROMINOS
#define TETRIS_STAGE_TETROMINOS

#include "raylib.h"
#include <time.h>
#include <string.h>
#include <stdio.h>
#define MAX_MULTILINES_COMPLETE 4
#define STAGE_WIDTH 12
#define STAGE_HEIGHT 22
#define TILE_SIZE 24
#define TETROMINO_SIZE 4
#define BLINK_TIMER 33

extern int stage[];

extern int l_tetromino_0[];

extern int l_tetromino_90[];

extern int l_tetromino_180[];

extern int l_tetromino_270[];

extern int j_tetromino_0[];

extern int j_tetromino_90[];

extern int j_tetromino_180[];

extern int j_tetromino_270[];

extern int o_tetromino[];

extern int s_tetromino_0[];

extern int s_tetromino_90[];

extern int s_tetromino_180[];

extern int s_tetromino_270[];

extern int t_tetromino_0[];

extern int t_tetromino_90[];

extern int t_tetromino_180[];

extern int t_tetromino_270[];

extern int i_tetromino_0[];

extern int i_tetromino_90[];

extern int i_tetromino_180[];

extern int i_tetromino_270[];

extern int z_tetromino_0[];

extern int z_tetromino_90[];

extern int z_tetromino_180[];

extern int z_tetromino_270[];

extern int *tetromino_types[7][4];
extern Color color_types[7];

extern int window_width;
extern int window_height;
extern int completed_lines_y_index[MAX_MULTILINES_COMPLETE]; //Array containg the index on the y of the completed lines
extern int lines_completed;
extern int lines_cleared;
extern int blink_time_counter;
extern int tetromino_start_x;
extern int tetromino_start_y;
extern int start_offset_x;
extern int start_offset_y;
extern int current_tetromino_x;
extern int current_tetromino_y;
extern int current_color;
extern int current_tetromino_type;
extern int current_rotation;
extern int game_over;
extern float move_tetromino_down_timer;
extern float time_to_move_tetromino_down;
extern Sound drop_sound;
extern Sound rotate_sound;
extern Color blink_color;
extern Music music;
extern Sound line_clear_sound;
extern time_t unix_time;

#endif //TETRIS_STAGE_TETROMINOS