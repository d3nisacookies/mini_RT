#include "mini_RT.h"

int close_window(void *param)
{
    (void)param;
    exit(0);
}

int key_handler(int keycode, void *param)
{
    (void)param;
    if (keycode == 65307)
        exit(0);
    return (0);
}