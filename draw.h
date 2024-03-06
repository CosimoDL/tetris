#ifndef DRAW_H
#define DRAW_H
#include "tetris_global_variables.h"

void draw_tetromino(const Color current_color, const int start_offset_x, const int start_offset_y, 
                    const int tetromino_start_x, const int tetromino_start_y, const int *tetromino);

void draw();

#endif // DRAW_H