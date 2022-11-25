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

void analyse_events(sfRenderWindow *window, sfEvent event, player_struct_t *player)
{  
    while(sfRenderWindow_pollEvent(window, &event)){
        if (event.type == sfEvtClosed)
            close_window(window);
        if (event.type == sfEvtKeyReleased)
            memo_key_released(player, event.key);
        if (event.type == sfEvtKeyPressed)
            memo_key_pressed(player, event.key);
    }
}