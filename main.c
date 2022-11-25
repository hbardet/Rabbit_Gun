/*
** JAM GAME
** rabbit_gun
** File description:
** main.c
*/
#include "rabbit.h"

int main()
{
    sfRenderWindow *window = setup_window();
    sfEvent event;
    player_struct_t *player_one = make_struct_player();
    while (sfRenderWindow_isOpen(window)){
        analyse_events(window, event, player_one);
        sfRenderWindow_drawSprite(window,player_one->sprite_player,NULL);
        sfRenderWindow_display(window);
    }
    sfRenderWindow_destroy(window);
    return (0);
}