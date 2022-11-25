/*
** EPITECH PROJECT, 2022
** rabbit_gun
** File description:
** player
*/

#include "rabbit.h"

sfSprite *make_player(void)
{
    sfSprite *player = sfSprite_create();
    sfTexture *texture_player = sfTexture_createFromFile("asset/images/03/Tilemap/tilemap_packed.png", NULL);
    sfSprite_setTexture(player, texture_player, sfTrue);
    sfSprite_setTexture(player,texture_player,sfTrue);
    sfIntRect rect = {0,64,16,16};
    sfSprite_setTextureRect(player,rect);
    sfVector2f scale = {3.0,3.0};
    
    sfSprite_scale(player,scale); 

    return (player);
}

player_struct_t *make_struct_player(void)
{
    player_struct_t *new_player = malloc(sizeof(*new_player));

    new_player->sprite_player = make_player();
    return (new_player);
}
