/*
** EPITECH PROJECT, 2022
** my_hunter
** File description:
** event function
*/

#include "rabbit.h"

void close_window(sfRenderWindow *window)
{
    sfRenderWindow_close(window);    
}

void analyse_events(sfRenderWindow *window, sfEvent event)
{  
    while(sfRenderWindow_pollEvent(window, &event)){
        if (event.type == sfEvtClosed)
            close_window(window);
    }
}