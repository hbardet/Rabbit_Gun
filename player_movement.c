/*
** EPITECH PROJECT, 2022
** rabbit_gun
** File description:
** player_movement
*/

#include "rabbit.h"
#define SPEED 5.0

int detect_movement(player_struct_t *player, sfKeyEvent key_pressed)
{
    sfVector2f cordo = {0,0};
    cordo.y -= (key_pressed.code == sfKeyZ) ? (SPEED) : (0);
    cordo.y += (key_pressed.code == sfKeyS) ? (SPEED) : (0);
    cordo.x -= (key_pressed.code == sfKeyQ) ? (SPEED) : (0);
    cordo.x += (key_pressed.code == sfKeyD) ? (SPEED) : (0);
    sfSprite_move(player->sprite_player,cordo);
    return (0);
}
