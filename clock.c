#include "rabbit.h"



void move_rect(sfIntRect *rect, int offset, int max_value)
{
    rect->left += offset;
    if (rect->left > max_value)
        rect->left = 0;
}

void reset_rect(player_struct_t *player)
{
    player->rect.left = 0;
    sfSprite_setTextureRect(player->sprite_player,player->rect);
}

void clock_sprite(sfClock *clock, player_struct_t *player)
{
    float seconds;
    sfTime time;
    time = sfClock_getElapsedTime(clock);
    seconds = time.microseconds / 1000000.0;
    if (seconds > 0.3) {
        move_rect(&player->rect,16,32);
        sfSprite_setTextureRect(player->sprite_player,player->rect);
        sfClock_restart(clock);
    }
}
