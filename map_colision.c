/*
** EPITECH PROJECT, 2022
** my_hunter
** File description:
** 
*/

#include "rabbit.h"

sfColor get_pixel_color(sprite_t *sprite, int x, int y)
{
    sfColor color;

    color = sfImage_getPixel(sprite->image_background, x , y);
    return color;
}

int my_colorcmp(sfColor color1, sfColor color2)
{
    if (color1.r == color2.r && color1.g == color2.g &&
        color1.b == color2.b && color1.a == color2.a)
        return 0;
    return 1;
}

int colision_player(sprite_t *sprite,int x, int y)
{
    sfColor color = get_pixel_color(sprite,x ,y);
    if (my_colorcmp(color,sfRed))
        return 1;
    return 0;
}