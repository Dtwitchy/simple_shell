include "main.h"

/**
 * get_coc - Handle the crtl + c call in prompt
 * @singh: Signal handler
 */
void get_coc(int singh)
{
 (void)singh;
 write(STDOUT_FILENO, "\n^-^ ", 4);
}
