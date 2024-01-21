#include "raylib.h"
#include <time.h>
#include <string.h>
#include "Tetris.h"
#include <stdio.h>

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

const int lTetromino0[] =
{
    0, 1, 0, 0,
    0, 1, 0, 0,
    0, 1, 1, 0,
    0, 0, 0, 0,
};

const int lTetromino90[] =
{
    0, 0, 0, 0,
    1, 1, 1, 0,
    1, 0, 0, 0,
    0, 0, 0, 0,
};

const int lTetromino180[] =
{
    1, 1, 0, 0,
    0, 1, 0, 0,
    0, 1, 0, 0,
    0, 0, 0, 0,
};

const int lTetromino270[] =
{
    0, 0, 1, 0,
    1, 1, 1, 0,
    0, 0, 0, 0,
    0, 0, 0, 0,
};

const int jTetromino0[] =
{
    0, 1, 0, 0,
    0, 1, 0, 0,
    1, 1, 0, 0,
    0, 0, 0, 0,
};

const int jTetromino90[] =
{
    1, 0, 0, 0,
    1, 1, 1, 0,
    0, 0, 0, 0,
    0, 0, 0, 0,
};

const int jTetromino180[] =
{
    0, 1, 1, 0,
    0, 1, 0, 0,
    0, 1, 0, 0,
    0, 0, 0, 0,
};

const int jTetromino270[] =
{
    0, 0, 0, 0,
    1, 1, 1, 0,
    0, 0, 1, 0,
    0, 0, 0, 0,
};


const int oTetromino[] =
{
    1, 1, 0, 0,
    1, 1, 0, 0,
    0, 0, 0, 0,
    0, 0, 0, 0,
};

const int sTetromino0[] =
{
    0, 0, 0, 0,
    0, 1, 1, 0,
    1, 1, 0, 0,
    0, 0, 0, 0,
};

const int sTetromino90[] =
{
    0, 0, 0, 0,
    0, 1, 0, 0,
    0, 1, 1, 0,
    0, 0, 1, 0,
};

const int sTetromino180[] =
{
    0, 0, 0, 0,
    0, 1, 1, 0,
    1, 1, 0, 0,
    0, 0, 0, 0,
};

const int sTetromino270[] =
{
    0, 0, 0, 0,
    0, 1, 0, 0,
    0, 1, 1, 0,
    0, 0, 1, 0,
};


const int tTetromino0[] =
{
    0, 0, 0, 0,
    1, 1, 1, 0,
    0, 1, 0, 0,
    0, 0, 0, 0,
};

const int tTetromino90[] =
{
    0, 1, 0, 0,
    1, 1, 0, 0,
    0, 1, 0, 0,
    0, 0, 0, 0,
};

const int tTetromino180[] =
{
    0, 1, 0, 0,
    1, 1, 1, 0,
    0, 0, 0, 0,
    0, 0, 0, 0,
};

const int tTetromino270[] =
{
    0, 1, 0, 0,
    0, 1, 1, 0,
    0, 1, 0, 0,
    0, 0, 0, 0,
};

const int iTetromino0[] =
{
    0, 1, 0, 0,
    0, 1, 0, 0,
    0, 1, 0, 0,
    0, 1, 0, 0,
};

const int iTetromino90[] =
{
    0, 0, 0, 0,
    1, 1, 1, 1,
    0, 0, 0, 0,
    0, 0, 0, 0,
};

const int iTetromino180[] =
{
    0, 1, 0, 0,
    0, 1, 0, 0,
    0, 1, 0, 0,
    0, 1, 0, 0,
};

const int iTetromino270[] =
{
    0, 0, 0, 0,
    1, 1, 1, 1,
    0, 0, 0, 0,
    0, 0, 0, 0,
};

const int zTetromino0[] =
{
    0, 0, 0, 0,
    0, 1, 1, 0,
    0, 0, 1, 1,
    0, 0, 0, 0,
};

const int zTetromino90[] =
{
    0, 0, 1, 0,
    0, 1, 1, 0,
    0, 1, 0, 0,
    0, 0, 0, 0,
};

const int zTetromino180[] =
{
    0, 1, 1, 0,
    0, 0, 1, 1,
    0, 0, 0, 0,
    0, 0, 0, 0,
};

const int zTetromino270[] =
{
    0, 0, 0, 1,
    0, 0, 1, 1,
    0, 0, 1, 0,
    0, 0, 0, 0,
};

const Color colorTypes[7] =
{
    {102, 191, 255, 255}, // Sky Blue
    {253, 249, 0, 255},   // Yellow
    {230, 41, 55, 255},   // Red
    {0, 228, 48, 255},    // Green
    {0, 82, 172, 255},    // Dark Blue
    {200, 122, 255, 255}, // Purple
    {255, 161, 0, 255}    // Orange
};

int windowWidth = 600;
int windowHeight = 700; 
int completedLinesYIndex[MAX_MULTILINES_COMPLETE] = {-1}; //Array containg the index on the y of the completed lines
int linesCompleted;
int linesCleared;
int blinkTimeCounter;
int tetrominoStartX;
int tetrominoStartY;
int startOffsetX;
int startOffsetY;
int currentTetrominoX;
int currentTetrominoY;
int currentColor;
int currentTetrominoType;
int currentRotation;
int gameOver = 0;
float moveTetrominoDownTimer;
float timeToMoveTetrominoDown;
Sound drop_sound;
Sound rotate_sound;
Color blinkColor;
Music music;
Sound lineClear_sound;
time_t unixTime;

const int *tetrominoTypes[7][4] =
    {
        {zTetromino0, zTetromino90, zTetromino180, zTetromino270},
        {sTetromino0, sTetromino90, sTetromino180, sTetromino270},
        {tTetromino0, tTetromino90, tTetromino180, tTetromino270},
        {oTetromino, oTetromino, oTetromino, oTetromino},
        {iTetromino0, iTetromino90, iTetromino180, iTetromino270},
        {jTetromino0, jTetromino90, jTetromino180, jTetromino270},
        {lTetromino0, lTetromino90, lTetromino180, lTetromino270},
};

void DrawTetromino(const Color currentColor, const int startOffsetX, const int startOffsetY, const int tetrominoStartX, const int tetrominoStartY, const int *tetromino)
{
    for (int y = 0; y < TETROMINO_SIZE; y++)
    {
        for (int x = 0; x < TETROMINO_SIZE; x++)
        {
            const int offset = y * TETROMINO_SIZE + x;

            if (tetromino[offset] == 1)
            {
                DrawRectangle((x + tetrominoStartX) * TILE_SIZE + startOffsetX, (y + tetrominoStartY) * TILE_SIZE + startOffsetY, TILE_SIZE, TILE_SIZE, currentColor);
            }
        }
    }
}

void DecreaseTimer(float *timer,float decreaseValue)
{
    *timer -= decreaseValue;
}

void BlinkAnimation()
{
    //Blink Animation before reset
    if (blinkTimeCounter > 0 && blinkTimeCounter <= BLINK_TIMER)
    {
        if (blinkTimeCounter%8 < 4)
            blinkColor = RED;
        else
            blinkColor = MAROON;

        blinkTimeCounter++;
    }
    else
    {    
        blinkTimeCounter = 0;
    }

    if (blinkTimeCounter == BLINK_TIMER && completedLinesYIndex >= 0)
    {
        int index = 0;
        while (completedLinesYIndex[index] != -1 && index < MAX_MULTILINES_COMPLETE)
        {
            ResetLines(completedLinesYIndex[index]);
            completedLinesYIndex[index] = -1;
            index++;
        }
    }
}

void InitGame()
{
    startOffsetX = (windowWidth / 2) - ((STAGE_WIDTH * TILE_SIZE) / 2);
    startOffsetY = (windowHeight / 2) - ((STAGE_HEIGHT * TILE_SIZE) / 2);

    tetrominoStartY = 0;
    tetrominoStartX = STAGE_WIDTH / 2;

    currentTetrominoX = tetrominoStartX;
    currentTetrominoY = tetrominoStartY;

    linesCompleted = 0;
    linesCleared = 0;
    blinkTimeCounter = 0;

    unixTime = 0;
    time(&unixTime);
    SetRandomSeed(unixTime);

    currentTetrominoType = GetRandomValue(0, 6);
    currentRotation = 0;

    moveTetrominoDownTimer = 1.0f;
    timeToMoveTetrominoDown = moveTetrominoDownTimer;
    currentColor = GetRandomValue(0, 6);

    //Load music/sound 
    music = LoadMusicStream("tetris.mp3");
    rotate_sound = LoadSound("tetris_rotate.mp3");
    lineClear_sound = LoadSound("tetris_line_clear.mp3");
    SetSoundVolume(lineClear_sound,0.5f);
    drop_sound = LoadSound("tetris_drop.mp3");
    music.looping = true;

    PlayMusicStream(music);
    SetMusicVolume(music, 0.05f);

    SetTargetFPS(60);
}

void UnloadGameResources()
{
    StopMusicStream(music);
    UnloadMusicStream(music);
    UnloadSound(rotate_sound);
    UnloadSound(drop_sound);
    UnloadSound(lineClear_sound);
}

void CheckingInput()
{
    if (IsKeyPressed(KEY_SPACE))
    {
        const int lastRotation = currentRotation;

        currentRotation++;

        if (currentRotation > 3)
        {
            currentRotation = 0;
        }

        PlaySound(rotate_sound);
        if (CheckCollision(currentTetrominoX, currentTetrominoY, tetrominoTypes[currentTetrominoType][currentRotation]))
        {
            currentRotation = lastRotation;
            StopSound(rotate_sound);
        }
    }
    if (IsKeyPressed(KEY_RIGHT))
    {
        // No need to check overflow, wall is your protector
        if (!CheckCollision(currentTetrominoX + 1, currentTetrominoY, tetrominoTypes[currentTetrominoType][currentRotation]))
        {
            currentTetrominoX++;
        }
    }
    if (IsKeyPressed(KEY_LEFT))
    {
        // No need to check overflow, wall is your protector
        if (!CheckCollision(currentTetrominoX - 1, currentTetrominoY, tetrominoTypes[currentTetrominoType][currentRotation]))
        {
            currentTetrominoX--;
        }
    }
    if (timeToMoveTetrominoDown <= 0 || IsKeyPressed(KEY_DOWN))
    {
        if (!CheckCollision(currentTetrominoX, currentTetrominoY + 1, tetrominoTypes[currentTetrominoType][currentRotation]))
        {
            currentTetrominoY++;
            timeToMoveTetrominoDown = moveTetrominoDownTimer;
        }
        else
        {
            for (int y = 0; y < TETROMINO_SIZE; y++)
            {
                for (int x = 0; x < TETROMINO_SIZE; x++)
                {
                    const int offset = y * TETROMINO_SIZE + x;

                    const int *tetromino = tetrominoTypes[currentTetrominoType][currentRotation];

                    if (tetromino[offset] == 1)
                    {
                        const int offset_stage = (y + currentTetrominoY) * STAGE_WIDTH + (x + currentTetrominoX);

                        stage[offset_stage] = 2; // Tetrominos value in the stage[] after collision
                        PlaySound(drop_sound);
                    }
                }
            }

            DeleteLines(completedLinesYIndex);

            currentTetrominoX = tetrominoStartX;
            currentTetrominoY = tetrominoStartY;

            currentTetrominoType = GetRandomValue(0, 6);
            currentRotation = 0;
            currentColor = GetRandomValue(0, 6);
        }
    }
}

void UpdateGame()
{
    UpdateMusicStream(music); // Update music buffer with new stream data

    timeToMoveTetrominoDown -= GetFrameTime();

    // Increase tetromino's speed
    if (linesCleared >= 5 && moveTetrominoDownTimer >= 0.25)
    {
        DecreaseTimer(&moveTetrominoDownTimer, 0.05f);
        linesCleared = 0;
    }

    CheckingInput();

    // Check if the starting position for the new tetromino is occupied
    if (CheckCollision(tetrominoStartX, tetrominoStartY, tetrominoTypes[currentTetrominoType][currentRotation]))
    {
        gameOver = 1;
    }
}

void DrawGame()
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
                DrawRectangle(x * TILE_SIZE + startOffsetX, y * TILE_SIZE + startOffsetY, TILE_SIZE, TILE_SIZE, DARKGRAY); // Wall limits
            }
            else if (stage[offset] == 2)
            {
                DrawRectangle(x * TILE_SIZE + startOffsetX, y * TILE_SIZE + startOffsetY, TILE_SIZE, TILE_SIZE, DARKGREEN); // Block
            }
            else if (stage[offset] == 3)
            {
                DrawRectangle(x * TILE_SIZE + startOffsetX, y * TILE_SIZE + startOffsetY, TILE_SIZE, TILE_SIZE, blinkColor); // Complete Line
            }

            DrawRectangleLines(x * TILE_SIZE + startOffsetX, y * TILE_SIZE + startOffsetY, TILE_SIZE, TILE_SIZE, WHITE); // Cells outlines
        }
    }

    DrawTetromino(colorTypes[currentColor], startOffsetX, startOffsetY, currentTetrominoX, currentTetrominoY, tetrominoTypes[currentTetrominoType][currentRotation]);

    DrawText(TextFormat("Lines: %i", linesCompleted), 470, 100, 20, YELLOW);
}

void ResetGame()
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
        UnloadGameResources();
        InitGame();
        gameOver = 0;
    }
}

int main(int argc, char **argv, char **environ)
{
    InitWindow(windowWidth, windowHeight, "Title");
    InitAudioDevice();

    InitGame();

    while (!WindowShouldClose())
    {
        if (!gameOver)
        {
            UpdateGame();
            BlinkAnimation();
            DrawGame();
        }
        else
        {
            ResetGame();
        }

        EndDrawing();
    }

    CloseAudioDevice(); // Close audio device
    CloseWindow();      // Close window

    return 0;
}
