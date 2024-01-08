#define STAGE_WIDTH 12
#define STAGE_HEIGHT 22
#define TILE_SIZE 24
#define TETROMINO_SIZE 4
#define BLINK_TIMER 33

int CheckCollision(const int tetrominoStartX, const int tetrominoStartY, const int *tetromino);

void ResetLines(int startLineY);

int DeleteLines();
