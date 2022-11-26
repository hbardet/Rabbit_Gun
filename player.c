/*
** EPITECH PROJECT, 2022
** rabbit_gun
** File description:
** player
*/

#include "rabbit.h"

player_struct_t *make_player(sfVector2f pos)
{
    player_struct_t *player = malloc(sizeof(player_struct_t));
    player->sprite_player = sfSprite_create();
    if (pos.x == 225) {
        player->texture_player = sfTexture_createFromFile("asset/images/03/Tiles/player_one_right.png", NULL);
        player->nb_player = 1;
    } else {
        player->texture_player = sfTexture_createFromFile("asset/images/03/Tiles/player_two_right.png", NULL);
        player->nb_player = 2;
    }
    player->orientation_player = 0;
    sfSprite_setTexture(player->sprite_player, player->texture_player, sfTrue);
    player->rect.height = 16;
    player->rect.left = 0;
    player->rect.top = 0;
    player->rect.width = 16;
    sfSprite_setTextureRect(player->sprite_player,player->rect);
    sfVector2f scale = {4.0,4.0};
    sfSprite_scale(player->sprite_player,scale);
    sfSprite_setPosition(player->sprite_player,pos);
    return (player);
}

player_struct_t *make_struct_player(sfVector2f pos)
{
    player_struct_t *new_player = make_player(pos);
    new_player->controle = make_struct_controle();
    new_player->clock_player = sfClock_create();
    new_player->bullet = malloc(sizeof(*new_player->bullet));
    new_player->bullet = NULL;
    new_player->can_shoot = true;

    return (new_player);
}
