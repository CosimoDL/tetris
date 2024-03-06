#ifndef CHECK_INPUT_H
#define CHECK_INPUT_H
#include "tetris_global_variables.h"

void check_input();

int check_collision(const int tetrominoStartX, const int tetrominoStartY, const int *tetromino);

#endif // CHECK_INPUT_H