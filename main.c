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
    sfVector2f pos_player_one = {225.0,382.0};
    sfVector2f pos_player_two = {1000.0,130.0};
    player_struct_t *player_one = make_struct_player(pos_player_one);
    player_struct_t *player_two = make_struct_player(pos_player_two);
    sprite_t *sprite = map_load_one();
    sfMusic *music = sfMusic_createFromFile("asset/audio/Music/music.wav");
    sfMusic_setLoop(music,sfRenderWindow_isOpen(window));
    sfMusic_play(music);
    while (sfRenderWindow_isOpen(window)){
        if (player_one->controle->move_down || player_one->controle->move_left || player_one->controle->move_right)
            clock_sprite(clock,player_one);
        else
            reset_rect(player_one);
        if (player_two->controle->move_down || player_two->controle->move_left || player_two->controle->move_right)
            clock_sprite(clock,player_two);
        else
            reset_rect(player_two);
        analyse_events(window, event, player_one,player_two);
        detect_movement(player_one,sprite);
        detect_movement(player_two,sprite);
        sfRenderWindow_drawSprite(window, sprite->sprite_background, NULL);
        bullet_shoot(player_one, player_two);
        if (my_struct_len(player_one->bullet) > 0)
            manage_bullet(window, player_one);
        if (my_struct_len(player_two->bullet) > 0)
            manage_bullet(window, player_two);
        sfRenderWindow_drawSprite(window,player_one->sprite_player,NULL);
        sfRenderWindow_drawSprite(window,player_two->sprite_player,NULL);
        sfRenderWindow_display(window);
        
        sfRenderWindow_clear(window, sfBlack);
        
    }
    sfRenderWindow_destroy(window);
    return (0);
}