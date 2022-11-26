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

void analyse_events(sfRenderWindow *window, sfEvent event, player_struct_t *player_one, player_struct_t *player_two)
{  
    while(sfRenderWindow_pollEvent(window, &event)){
        if (event.type == sfEvtClosed)
            close_window(window);
        if (event.type == sfEvtMouseButtonPressed)
            bullet_shoot(player_one, event.mouseButton);
        if (event.type == sfEvtKeyReleased)
            memo_key_released(player_one,player_two, event.key);
        if (event.type == sfEvtKeyPressed)
            memo_key_pressed(player_one, player_two, event.key);
    }
}