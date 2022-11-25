#include "rabbit.h"

sprite_t *map_load_one(void)
{
    sprite_t *sprite = malloc(sizeof(sprite_t));
    sfVector2f scale_background = {4.0, 4.0};
    sprite->texture_background =
    sfTexture_createFromFile("map/map1-2.png", NULL);
    sprite->sprite_background = sfSprite_create();
    sfSprite_setTexture(sprite->sprite_background, sprite->texture_background, sfFalse);
    sfSprite_setScale(sprite->sprite_background,scale_background);
    sprite->image_background = sfImage_createFromFile("map/map1-2-col.png");
    return sprite;
}

