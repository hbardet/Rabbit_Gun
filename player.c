/*
** EPITECH PROJECT, 2022
** rabbit_gun
** File description:
** player
*/

#include "rabbit.h"

player_struct_t *make_player(void)
{
    player_struct_t *player = malloc(sizeof(player_struct_t));
    player->sprite_player = sfSprite_create();
    player->texture_player = sfTexture_createFromFile("asset/images/03/Tilemap/tilemap_packed.png", NULL);
    sfSprite_setTexture(player->sprite_player, player->texture_player, sfTrue);
    player->rect.height = 16;
    player->rect.left = 0;
    player->rect.top = 64;
    player->rect.width = 16;
    sfSprite_setTextureRect(player->sprite_player,player->rect);
    sfVector2f scale = {4.0,4.0};
    sfSprite_scale(player->sprite_player,scale);
    sfVector2f pos = {225.0,382.0};
    sfSprite_setPosition(player->sprite_player,pos);
    return (player);
}

player_struct_t *make_struct_player(void)
{
    player_struct_t *new_player = make_player();
    new_player->controle = make_struct_controle();
    new_player->clock_player = sfClock_create();
    return (new_player);
}
