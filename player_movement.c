/*
** EPITECH PROJECT, 2022
** rabbit_gun
** File description:
** player_movement
*/

#include "rabbit.h"
#define SPEED 5.0


controle_key_t *make_struct_controle(void)
{
    controle_key_t *new_controle = malloc(sizeof(*new_controle));

    new_controle->move_up = false; 
    new_controle->move_down = false; 
    new_controle->move_left = false; 
    new_controle->move_right = false; 
    return (new_controle);
}

int memo_key_pressed(player_struct_t *player, sfKeyEvent key_pressed)
{
    
    if(key_pressed.code == sfKeyZ)
        player->controle->move_up = true;
    if(key_pressed.code == sfKeyS)
        player->controle->move_down = true;
    if(key_pressed.code == sfKeyQ)
        player->controle->move_left = true;
    if(key_pressed.code == sfKeyD)
        player->controle->move_right = true;
    return (0);
}

int memo_key_released(player_struct_t *player, sfKeyEvent key_released)
{
    if(key_released.code == sfKeyZ)
        player->controle->move_up = false;
    if(key_released.code == sfKeyS)
        player->controle->move_down = false;
    if(key_released.code == sfKeyQ)
        player->controle->move_left = false;
    if(key_released.code == sfKeyD)
        player->controle->move_right = false;
    return (0);
}

int detect_movement(player_struct_t *player)
{  
    sfVector2f cordo = {0,0};
    if (player->controle->move_up == true)
        cordo.y -= SPEED;
    if (player->controle->move_down == true)
        cordo.y += SPEED;
    if (player->controle->move_right == true)
        cordo.x += SPEED;
    if (player->controle->move_left == true)
        cordo.x -= SPEED;
    
    sfSprite_move(player->sprite_player,cordo);
    return (0);
}
