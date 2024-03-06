#include "raylib.h"
#include <time.h>
#define MAX_MULTILINES_COMPLETE 4

int stage[] = 
{
    1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
    1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
    1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
    1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
    1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
    1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
    1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
    1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
    1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
    1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
    1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
    1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
    1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
    1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
    1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
    1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
    1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
    1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
    1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
    1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
    1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
};

const int l_tetromino_0[] =
{
    0, 1, 0, 0,
    0, 1, 0, 0,
    0, 1, 1, 0,
    0, 0, 0, 0,
};

const int l_tetromino_90[] =
{
    0, 0, 0, 0,
    1, 1, 1, 0,
    1, 0, 0, 0,
    0, 0, 0, 0,
};

const int l_tetromino_180[] =
{
    1, 1, 0, 0,
    0, 1, 0, 0,
    0, 1, 0, 0,
    0, 0, 0, 0,
};

const int l_tetromino_270[] =
{
    0, 0, 1, 0,
    1, 1, 1, 0,
    0, 0, 0, 0,
    0, 0, 0, 0,
};

const int j_tetromino_0[] =
{
    0, 1, 0, 0,
    0, 1, 0, 0,
    1, 1, 0, 0,
    0, 0, 0, 0,
};

const int j_tetromino_90[] =
{
    1, 0, 0, 0,
    1, 1, 1, 0,
    0, 0, 0, 0,
    0, 0, 0, 0,
};

const int j_tetromino_180[] =
{
    0, 1, 1, 0,
    0, 1, 0, 0,
    0, 1, 0, 0,
    0, 0, 0, 0,
};

const int j_tetromino_270[] =
{
    0, 0, 0, 0,
    1, 1, 1, 0,
    0, 0, 1, 0,
    0, 0, 0, 0,
};

const int o_tetromino[] =
{
    1, 1, 0, 0,
    1, 1, 0, 0,
    0, 0, 0, 0,
    0, 0, 0, 0,
};

const int s_tetromino_0[] =
{
    0, 0, 0, 0,
    0, 1, 1, 0,
    1, 1, 0, 0,
    0, 0, 0, 0,
};

const int s_tetromino_90[] =
{
    0, 0, 0, 0,
    0, 1, 0, 0,
    0, 1, 1, 0,
    0, 0, 1, 0,
};

const int s_tetromino_180[] =
{
    0, 0, 0, 0,
    0, 1, 1, 0,
    1, 1, 0, 0,
    0, 0, 0, 0,
};

const int s_tetromino_270[] =
{
    0, 0, 0, 0,
    0, 1, 0, 0,
    0, 1, 1, 0,
    0, 0, 1, 0,
};

const int t_tetromino_0[] =
{
    0, 0, 0, 0,
    1, 1, 1, 0,
    0, 1, 0, 0,
    0, 0, 0, 0,
};

const int t_tetromino_90[] =
{
    0, 1, 0, 0,
    1, 1, 0, 0,
    0, 1, 0, 0,
    0, 0, 0, 0,
};

const int t_tetromino_180[] =
{
    0, 1, 0, 0,
    1, 1, 1, 0,
    0, 0, 0, 0,
    0, 0, 0, 0,
};

const int t_tetromino_270[] =
{
    0, 1, 0, 0,
    0, 1, 1, 0,
    0, 1, 0, 0,
    0, 0, 0, 0,
};

const int i_tetromino_0[] =
{
    0, 1, 0, 0,
    0, 1, 0, 0,
    0, 1, 0, 0,
    0, 1, 0, 0,
};

const int i_tetromino_90[] =
{
    0, 0, 0, 0,
    1, 1, 1, 1,
    0, 0, 0, 0,
    0, 0, 0, 0,
};

const int i_tetromino_180[] =
{
    0, 1, 0, 0,
    0, 1, 0, 0,
    0, 1, 0, 0,
    0, 1, 0, 0,
};

const int i_tetromino_270[] =
{
    0, 0, 0, 0,
    1, 1, 1, 1,
    0, 0, 0, 0,
    0, 0, 0, 0,
};

const int z_tetromino_0[] =
{
    0, 0, 0, 0,
    0, 1, 1, 0,
    0, 0, 1, 1,
    0, 0, 0, 0,
};

const int z_tetromino_90[] =
{
    0, 0, 1, 0,
    0, 1, 1, 0,
    0, 1, 0, 0,
    0, 0, 0, 0,
};

const int z_tetromino_180[] =
{
    0, 1, 1, 0,
    0, 0, 1, 1,
    0, 0, 0, 0,
    0, 0, 0, 0,
};

const int z_tetromino_270[] =
{
    0, 0, 0, 1,
    0, 0, 1, 1,
    0, 0, 1, 0,
    0, 0, 0, 0,
};

const int *tetromino_types[7][4] =
    {
        {z_tetromino_0, z_tetromino_90, z_tetromino_180, z_tetromino_270},
        {s_tetromino_0, s_tetromino_90, s_tetromino_180, s_tetromino_270},
        {t_tetromino_0, t_tetromino_90, t_tetromino_180, t_tetromino_270},
        {o_tetromino, o_tetromino, o_tetromino, o_tetromino},
        {i_tetromino_0, i_tetromino_90, i_tetromino_180, i_tetromino_270},
        {j_tetromino_0, j_tetromino_90, j_tetromino_180, j_tetromino_270},
        {l_tetromino_0, l_tetromino_90, l_tetromino_180, l_tetromino_270},
};

const Color color_types[7] =
{
    {102, 191, 255, 255}, // Sky Blue
    {253, 249, 0, 255},   // Yellow
    {230, 41, 55, 255},   // Red
    {0, 228, 48, 255},    // Green
    {0, 82, 172, 255},    // Dark Blue
    {200, 122, 255, 255}, // Purple
    {255, 161, 0, 255}    // Orange
};

const int window_width = 600;
const int window_height = 700; 
int completed_lines_y_index[MAX_MULTILINES_COMPLETE] = {-1, -1, -1, -1}; //Array containg the index on the y of the completed lines
int lines_completed;
int lines_cleared;
int blink_time_counter;
int tetromino_start_x;
int tetromino_start_y;
int start_offset_x;
int start_offset_y;
int current_tetromino_x;
int current_tetromino_y;
int current_color;
int current_tetromino_type;
int current_rotation;
int game_over = 0;
float move_tetromino_down_timer;
float time_to_move_tetromino_down;
Sound drop_sound;
Sound rotate_sound;
Color blink_color;
Music music;
Sound line_clear_sound;
time_t unix_time;