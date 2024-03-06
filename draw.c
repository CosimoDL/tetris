#include "draw.h"

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

void draw()
{
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