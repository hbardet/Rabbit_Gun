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
    new_controle->shooting = false;
    return (new_controle);
}

int memo_key_pressed(player_struct_t *player_one, player_struct_t *player_two, sfKeyEvent key_pressed)
{
    
    if(key_pressed.code == sfKeyZ)
        player_one->controle->move_up = true;
    if(key_pressed.code == sfKeyS)
        player_one->controle->move_down = true;
    if(key_pressed.code == sfKeyQ)
        player_one->controle->move_left = true;
    if(key_pressed.code == sfKeyD)
        player_one->controle->move_right = true;
    if(key_pressed.code == sfKeySpace)
        player_one->controle->shooting = true;

    if(key_pressed.code == sfKeyUp)
        player_two->controle->move_up = true;
    if(key_pressed.code == sfKeyDown)
        player_two->controle->move_down = true;
    if(key_pressed.code == sfKeyLeft)
        player_two->controle->move_left = true;
    if(key_pressed.code == sfKeyRight)
        player_two->controle->move_right = true;
    if(key_pressed.code == sfKeyRShift)
        player_two->controle->shooting = true;

    return (0);
}

int memo_key_released(player_struct_t *player_one, player_struct_t *player_two, sfKeyEvent key_released)
{
    if(key_released.code == sfKeyZ)
        player_one->controle->move_up = false;
    if(key_released.code == sfKeyS)
        player_one->controle->move_down = false;
    if(key_released.code == sfKeyQ)
        player_one->controle->move_left = false;
    if(key_released.code == sfKeyD)
        player_one->controle->move_right = false;
    if(key_released.code == sfKeySpace)
        player_one->controle->shooting = false;
    

    if(key_released.code == sfKeyUp)
        player_two->controle->move_up = false;
    if(key_released.code == sfKeyDown)
        player_two->controle->move_down = false;
    if(key_released.code == sfKeyLeft)
        player_two->controle->move_left = false;
    if(key_released.code == sfKeyRight)
        player_two->controle->move_right = false;
    if(key_released.code == sfKeyRShift)
        player_two->controle->shooting = false;
    return (0);
}

int detect_movement(player_struct_t *player,sprite_t *sprite)
{
    sfVector2f cordo = {0,0};
    sfVector2f cordo_player = sfSprite_getPosition(player->sprite_player);
    if (player->controle->move_up == true && up_player(sprite,cordo_player.x,cordo_player.y))
        cordo.y -= SPEED;
    else if (colision_player(sprite,cordo_player.x - 40, cordo_player.y + 65) && colision_player(sprite,cordo_player.x + 60,cordo_player.y + 65) && cordo_player.y < 720)
        cordo.y += SPEED;
    if (player->controle->move_down == true && colision_player(sprite,cordo_player.x - 40, cordo_player.y + 65) && colision_player(sprite,cordo_player.x + 60,cordo_player.y + 65) && cordo_player.y < 720)
        cordo.y += SPEED;
    if (player->controle->move_right == true && colision_player(sprite,cordo_player.x + 64, cordo_player.y + 60) && cordo_player.x < 1200.0) {
        cordo.x += SPEED;
        if (player->nb_player == 1) {
            player->texture_player = sfTexture_createFromFile("asset/images/03/Tiles/player_one_right.png", NULL);
            player->orientation_player = 0;
        } else {
            player->texture_player = sfTexture_createFromFile("asset/images/03/Tiles/player_two_right.png", NULL);
            player->orientation_player = 0;
        }
        sfSprite_setTexture(player->sprite_player, player->texture_player, sfTrue);
        sfSprite_setTextureRect(player->sprite_player,player->rect);
    }
    if (player->controle->move_left == true && colision_player(sprite,cordo_player.x - 48, cordo_player.y + 60) && cordo_player.x > 10.0) {
        cordo.x -= SPEED;
        if (player->nb_player == 1) {
            player->texture_player = sfTexture_createFromFile("asset/images/03/Tiles/player_one_left.png", NULL);
            player->orientation_player = 1;
        } else {
            player->texture_player = sfTexture_createFromFile("asset/images/03/Tiles/player_two_left.png", NULL);
            player->orientation_player = 1;
        }
        sfSprite_setTexture(player->sprite_player, player->texture_player, sfTrue);
        sfSprite_setTextureRect(player->sprite_player,player->rect);
        }
    sfSprite_move(player->sprite_player, cordo);
    return (0);
}
