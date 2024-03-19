#include "delete_lines.h"
#include "tetris_global_variables.h"

void delete_lines(int *completedLines)
{
    int index = 0;
    for (int y = 0; y < STAGE_HEIGHT - 1; y++)
    {
        int checkLine = 1;

        for (int x = 1; x < STAGE_WIDTH - 1; x++)
        {
            const int offset = y * STAGE_WIDTH + x;

            if (stage[offset] == 0)
            {
                checkLine = 0;
                break;
            }
        }

        if (checkLine)
        {
            blink_time_counter++;
            for (int x = 1; x < STAGE_WIDTH - 1; x++)
            {
                const int offset = y * STAGE_WIDTH + x;
                stage[offset] = 3; //Blink status
            }

            completedLines[index] = y;
            index++;
        }
    }
}