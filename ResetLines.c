#include "Tetris.h"
#include "raylib.h"
#include <string.h>
#include <stdio.h>

extern int linesCompleted;
extern int linesCleared;
extern Sound lineClear_sound;
extern int stage[];
extern int blinkTimeCounter;

void ResetLines(int startLineY)
{
    linesCompleted++;
    linesCleared++;
    PlaySound(lineClear_sound);
    const int offset = startLineY * STAGE_WIDTH + 1;
    memset(stage + offset, 0, (STAGE_WIDTH - 2) * sizeof(int));
    for (int y = startLineY; y >= 0; y--)
    {
        for (int x = 1; x < STAGE_WIDTH - 1; x++)
        {
            const int offset = y * STAGE_WIDTH + x;
            const int offset_below = (y + 1) * STAGE_WIDTH + x;

            if (stage[offset_below] == 0 && stage[offset] > 0)
            {
                stage[offset_below] = stage[offset];
                stage[offset] = 0;
            }
        }
    }
}

void DeleteLines(int *completedLines)
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
            blinkTimeCounter++;
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