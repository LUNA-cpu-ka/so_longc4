#include "so_long.h"

void error(char* msg)
{
    write(2, msg, ft_strlen(msg));
    exit(1);
}