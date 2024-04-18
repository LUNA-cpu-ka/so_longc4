#include "so_long.h"
//⚠️⚠️You need libft ⚠️⚠️




void validation_extantion(try *app, int ac, char **av)
{
    char *ptr;

    if(ac < 2)
        error("Please enter the file name 🙂\n");
    ptr = strrchr(av[1], '.');
    if(!ptr || strncmp(ptr, ".ber",4))
        error("no extantion");
    app->file_name = av[1];

}

void    *validation_exist(try *app)
{
    app->fd = open(app->file_name, O_RDONLY);
    if(app->fd == -1)
        error("Not created");
    else 
        error("-Founded-");
    return(0);
}

char *read_map(try *app)
{
    app->fd = open(app->file_name, O_RDONLY);
    char *map = malloc(sizeof(char));
    app->line = get_next_line(app->fd);
    while(app->line){
        map = ft_strjoin(map, app->line);
        app->line = get_next_line(app->fd);
    }
    write(1, map, ft_strlen(map));
    write(1,"\n\n",2);
    free(map);
    return(0);
}

int height(try *app)
{
    int height;
    
    height = 0;
    app->fd = open(app->file_name, O_RDONLY);
    while(get_next_line(app->fd))
        height++;
    close(app->fd);
    return height;
}

// void read_map(try *app)
// {
//     int i;
//     int fd;

//     i = 0;
//     fd = open(app->file_name, O_RDONLY);
//     while(i < app->h)
//     {
//         app->map[i] =  get_next_line(fd);
//         i++;
//     }
// }

// char *validation_map(try *app, int ac, char** av)
// {
//     (void)ac;
//     (void)av;
//     printf("%s",app->line = get_next_line(app->fd));
//     return(0);
// }

int main(int ac, char** av)
{
    try app;
    validation_extantion(&app, ac, av);
    
    printf("height ==> %d\n",height(&app));
    // app.h = height(&app);
    // app.map = malloc(sizeof(char *) * app.h);
    read_map(&app);
    // int i;

    // i = 0;
    // while(app.map[i])
    // {
    //     printf("%s",app.map[i]);
    //     i ++;
    // }
    // validation_map(&app,ac,av);
    // validation_exist(&app);

    // mlx_function();
    return(0);
}
