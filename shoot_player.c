/*
** EPITECH PROJECT, 2022
** rabbitgun
** File description:
** shoot_player
*/

#include "rabbit.h"

#define SPEED_BULLET 20
#define CD_SHOOT 0.1

int manage_bullet(sfRenderWindow *window, player_struct_t *player,player_struct_t *ennemy)
{
    move_bullet(player,ennemy);
    display_bullet_on_screen(window, player);
    return (0);
}

int move_bullet(player_struct_t *player,player_struct_t *ennemy)
{
    bullet_list_t *tmp = player->bullet;
    int size;
    for (size = 0; tmp != NULL; size ++){
        if ((tmp->position.x + tmp->velo.x > 1280 + (16 * 4) || tmp->position.x + tmp->velo.x < 0 - (16 * 4))
            && tmp->touching == false) {
            tmp->touching = true;
        } else if (tmp->position.x >= (sfSprite_getPosition(ennemy->sprite_player).x) && tmp->position.x <= (sfSprite_getPosition(ennemy->sprite_player).x + 12) && tmp->position.y - 12 == (sfSprite_getPosition(ennemy->sprite_player).y)) {
            tmp->touching = true;
            ennemy->health -= 1;
            printf("%d\n",ennemy->health);
            move_rect(&ennemy->rect_health,64,320);
            sfSprite_setTextureRect(ennemy->sprite_health,ennemy->rect_health);
            tmp->position.x += tmp->velo.x;
        } else {
            sfSprite_move(tmp->bullet_sprite, tmp->velo);
            tmp->position.x += tmp->velo.x;
        }
        tmp = tmp->next;
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



int bullet_shoot(player_struct_t *player_one, player_struct_t *player_two)
{   
    sfTime time = sfClock_getElapsedTime(player_one->clock_shooting);
    float seconds = sfTime_asSeconds(time);
    if (player_one->controle->shooting && seconds > CD_SHOOT){
        add_node_bullet(player_one);
        sfClock_restart(player_one->clock_shooting);
    }      
    time = sfClock_getElapsedTime(player_two->clock_shooting);
    seconds = sfTime_asSeconds(time);
    if (player_two->controle->shooting && seconds > CD_SHOOT){
        add_node_bullet(player_two);
        sfClock_restart(player_two->clock_shooting);
    }
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
    sfIntRect intRect = {16, 16 * player->orientation_player,16,16};
    sfVector2f cordo_player = sfSprite_getPosition(player->sprite_player);
    cordo_player.x += (player->orientation_player) ? (-13) : (48);
    cordo_player.y += 26;
    new_bullet->rect = intRect;
    sfSprite_setTexture(new_bullet->bullet_sprite, texture_bullet, sfTrue);
    sfSprite_setTextureRect(new_bullet->bullet_sprite, new_bullet->rect);
    new_bullet->clock = sfClock_create();
    sfVector2f scale = {2.0,2.0};
    sfSprite_scale(new_bullet->bullet_sprite,scale); 
    sfSprite_setPosition(new_bullet->bullet_sprite, cordo_player);
    sfVector2f position_sprite = sfSprite_getPosition(new_bullet->bullet_sprite);
    new_bullet->position = position_sprite;
    new_bullet->touching = false;
    sfVector2f velo = {0,0};
    new_bullet->velo = velo;
    new_bullet->velo.x = (player->orientation_player) ? (-1 * SPEED_BULLET) : (SPEED_BULLET);
    new_bullet->next = *bullet;
    *bullet = new_bullet;
    return (0);
}