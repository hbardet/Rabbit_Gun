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
    sprite_t *sprite = map_load_one();
    while (sfRenderWindow_isOpen(window)){
        analyse_events(window, event, player_one,sprite);
        detect_movement(player_one,sprite);
        sfRenderWindow_drawSprite(window, sprite->sprite_background, NULL);
        add_node_bullet(player_one);
        if (my_struct_len(player_one->bullet) > 0)
            manage_bullet(window, player_one);
        sfRenderWindow_drawSprite(window,player_one->sprite_player,NULL);
        sfRenderWindow_display(window);
        printf("len struct = %d\n", my_struct_len(player_one->bullet));
        
    }
    sfRenderWindow_destroy(window);
    return (0);
}