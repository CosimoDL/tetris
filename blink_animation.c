#include "blink_animation.h"
#include "tetris_global_variables.h"
#include "reset_lines.h"

void blink_animation()
{
    //Blink Animation before reset
    if (blink_time_counter > 0 && blink_time_counter <= BLINK_TIMER)
    {
        if (blink_time_counter%8 < 4)
            blink_color = RED;
        else
            blink_color = MAROON;

        blink_time_counter++;
    }
    else
    {    
        blink_time_counter = 0;
    }

    if (blink_time_counter == BLINK_TIMER && completed_lines_y_index >= 0)
    {
        int index = 0;
        while (completed_lines_y_index[index] != -1 && index < MAX_MULTILINES_COMPLETE)
        {
            reset_lines(completed_lines_y_index[index]);
            completed_lines_y_index[index] = -1;
            index++;
        }
    }
}