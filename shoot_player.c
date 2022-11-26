/*
** EPITECH PROJECT, 2022
** rabbitgun
** File description:
** shoot_player
*/

#include "rabbit.h"



int manage_bullet(sfRenderWindow *window, player_struct_t *player)
{
    move_bullet(player);
    display_bullet_on_screen(window, player);
    return (0);
}

int move_bullet(player_struct_t *player)
{
    sfVector2f velo = {12,0};
    bullet_list_t *tmp = player->bullet;
    int size;
    for (size = 0; tmp != NULL; size ++){
        if ((tmp->position.x + velo.x > 1280 + (16 * 4) || tmp->position.x + velo.x < 0 - (16 * 4)) 
            && tmp->touching == false){
            tmp->touching = true;
            sfSprite_destroy(tmp->bullet_sprite);
        } else {
            sfSprite_move(tmp->bullet_sprite, velo);
            tmp->position.x += velo.x;
            tmp = tmp->next;
        }
    }
    return (0);
}

int display_bullet_on_screen(sfRenderWindow *window, player_struct_t *player)
{
    bullet_list_t *tmp = player->bullet;
    int size;
    for (size = 0; tmp != NULL; size ++){
        if(tmp->touching == false)
            sfRenderWindow_drawSprite(window, tmp->bullet_sprite,NULL);
        tmp = tmp->next;
    }
    return (0);
}

int my_struct_len(bullet_list_t *list)
{
    bullet_list_t *tmp = list;
    int size;
    for (size = 0; tmp != NULL; size ++)
        tmp = tmp->next;
    return (size);
}

int bullet_shoot(player_struct_t *player, sfMouseButtonEvent mousse_click)
{   
    if (mousse_click.button == sfMouseLeft)
        add_node_bullet(player);
    return (0);
}

bullet_list_t *add_node_bullet(player_struct_t *player)
{
    create_bullet(&player->bullet, player);
    return (player);
}

sfSprite *blast_bullet(player_struct_t *player)
{
    sfSprite *bullet_blast = sfSprite_create();
    sfTexture *texture_bullet = sfTexture_createFromFile("asset/sprite_sheet/bullet_sprite_sheet.png", NULL);
    sfIntRect intRect = {0,0,16,16};
    sfVector2f cordo_player = sfSprite_getPosition(player->sprite_player);
    cordo_player.x += 50;
    cordo_player.y += 10;
    sfSprite_setPosition(bullet_blast, cordo_player);
    return (bullet_blast);
}

int create_bullet(bullet_list_t **bullet, player_struct_t *player)
{
    bullet_list_t *new_bullet = malloc(sizeof(*new_bullet));

    new_bullet->bullet_sprite = sfSprite_create();
    sfTexture *texture_bullet = sfTexture_createFromFile("asset/sprite_sheet/bullet_sprite_sheet.png", NULL);
    sfIntRect intRect = {0,0,16,16};
    sfVector2f cordo_player = sfSprite_getPosition(player->sprite_player);
    cordo_player.x += 50;
    cordo_player.y += 10;
    new_bullet->rect = intRect;
    sfSprite_setTexture(new_bullet->bullet_sprite, texture_bullet, sfTrue);
    sfSprite_setTextureRect(new_bullet->bullet_sprite, new_bullet->rect);
    new_bullet->clock = sfClock_create();
    sfVector2f scale = {4.0,4.0};
    sfSprite_scale(new_bullet->bullet_sprite,scale); 
    sfSprite_setPosition(new_bullet->bullet_sprite, cordo_player);
    sfVector2f position_sprite = sfSprite_getPosition(new_bullet->bullet_sprite);
    new_bullet->position = position_sprite;
    new_bullet->touching = false;
    new_bullet->next = *bullet;
    *bullet = new_bullet;
    return (0);
}