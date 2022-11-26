/*
** EPITECH PROJECT, 2022
** Rabbit game menu
** File description:
** menu
*/
#include <stdio.h>
#include "rabbit.h"


sfSprite *sprite_creator(char * filepath,sfVector2f pos, int scale)
{
    sfTexture *texture = sfTexture_createFromFile(filepath,NULL);
    sfSprite *sprite = sfSprite_create();
    sfVector2f spr_scale = {scale, scale};

    sfSprite_setTexture(sprite,texture, sfTrue);
    sfSprite_setScale(sprite,spr_scale);
    sfSprite_setPosition(sprite,pos);
    return sprite;
}

void menu(sfRenderWindow *window)
{
    sfSprite *fond = sprite_creator("./Used_texture/Main_menu.png",(sfVector2f){0,0},1);
    sfSprite *start_button = sprite_creator("./Used_texture/Start_button.png",(sfVector2f){450, 300},2);

    sfRenderWindow_drawSprite(window, fond, NULL);
    sfRenderWindow_drawSprite(window, start_button, NULL);
}

void maps(sfRenderWindow *window)
{
    sfSprite *fond = sprite_creator("./Used_texture/Main_menu.png",(sfVector2f){0,0},1);
    sfSprite *map1_button = sprite_creator("./Used_texture/red_button.png",(sfVector2f){450, 300},2);
    sfSprite *map2_button = sprite_creator("./Used_texture/green_button.png",(sfVector2f){750, 300},2);
    sfSprite *home_button = sprite_creator("./Used_texture/home_button.png",(sfVector2f){100, 300},2);

    sfRenderWindow_drawSprite(window, home_button, NULL);
    sfRenderWindow_drawSprite(window, fond, NULL);
    sfRenderWindow_drawSprite(window, map1_button, NULL);
    sfRenderWindow_drawSprite(window, map2_button, NULL);
}

void game(sfRenderWindow* window, sfEvent event, sprite_t *sprite, player_struct_t *player_one, player_struct_t *player_two)
{
    sfRenderWindow_drawSprite(window, sprite->sprite_background, NULL);
    bullet_shoot(player_one, player_two);
    if (my_struct_len(player_two->bullet) > 0)
        manage_bullet(window, player_two,player_one);
    if (my_struct_len(player_one->bullet) > 0)
        manage_bullet(window, player_one,player_two);
    sfRenderWindow_drawSprite(window,player_one->sprite_player,NULL);
    sfRenderWindow_drawSprite(window,player_one->sprite_health,NULL);
    sfRenderWindow_drawSprite(window,player_two->sprite_player,NULL);
    sfRenderWindow_drawSprite(window,player_two->sprite_health,NULL); 
}

char if_click(sfRenderWindow* window, sfEvent event, char scene)
{
    sfVector2i mouse = sfMouse_getPosition(window);
    sfSprite *close_button = sprite_creator("./Used_texture/blue_boxCross.png",(sfVector2f){1150, 50},2);
    
    sfRenderWindow_drawSprite(window,close_button,NULL);
    if (mouse.x >= 450 && 830 >= mouse.x && mouse.y >= 300 && 400 >= mouse.y) {
        return '3';
    } else if (mouse.x >= 1150 && 1220 >= mouse.x && mouse.y >= 50 && 120 >= mouse.y) {
        return '2';
    } else if (mouse.x >= 75 && 175 >= mouse.x && mouse.y >= 50 && 150 >= mouse.y) {
        return '0';
    } else
        return scene;
}

char scene_handler(sfRenderWindow* window, char scene, sfEvent event, sprite_t *sprite, player_struct_t *player_one,player_struct_t *player_two)
{
    sfSprite *home_button = sprite_creator("./Used_texture/home_button.png",(sfVector2f){75, 50},2);
    
    if (scene == '1') {
        maps (window);
        sfRenderWindow_drawSprite(window, home_button, NULL);
    }
    if (scene == '3') {
        game(window,event,sprite,player_one,player_two);
        sfRenderWindow_drawSprite(window, home_button, NULL);
    }
    if (scene == '2')
            close_window(window);
    if (scene == '0') {
        menu (window);
    }
    scene = if_click(window, event, scene);
    return scene;
}