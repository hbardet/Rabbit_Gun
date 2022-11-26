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
    sfClock *clock = sfClock_create();
    player_struct_t *player_one = make_struct_player();
    sprite_t *sprite = map_load_one();
    while (sfRenderWindow_isOpen(window)){
        if (player_one->controle->move_down || player_one->controle->move_left || player_one->controle->move_right || player_one->controle->move_up)
            clock_sprite(clock,player_one);
        else
            reset_rect(player_one);
        analyse_events(window, event, player_one,sprite);
        detect_movement(player_one,sprite);
        sfRenderWindow_drawSprite(window, sprite->sprite_background, NULL);
        sfRenderWindow_drawSprite(window,player_one->sprite_player,NULL);
        sfRenderWindow_display(window);
        sfRenderWindow_clear(window, sfBlack);
    }
    sfRenderWindow_destroy(window);
    return (0);
}