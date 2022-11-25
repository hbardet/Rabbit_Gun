/*
** EPITECH PROJECT, 2022
** struct
** File description:
** struct
*/

#include <stdlib.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <stdio.h>

#ifndef RABBIT_H_
    #define RABBIT_H_
    #define SPEED_PLAYER = 1.0
typedef struct sprite {
    sfSprite *sprite_background;
    sfTexture *texture_background;
    sfImage *image_background;
}sprite_t;

typedef struct text{
    sfFont *font;
    sfText *text_score_previous;
    sfText *text_score;
    sfText *text_best_score_previous;
    sfText *text_best_score;
}text_t;

typedef struct clok {
    int score_char;
    int best_score;
    sfClock *clock;
    sfClock *clock_move;
}clok_t;

typedef struct sound {
    sfSound *fire_shot;
    sfSoundBuffer *fire_shot_buffer;
    sfSound *hit;
    sfSoundBuffer *hit_buffer;
}sound_t;

typedef struct controle_key{
    //sfKeyCode upKey = sfKeyCode.sfKeyZ;
    
}controle_key_t;

typedef struct player_struct {
    sfSprite *sprite_player;
}player_struct_t;

sfRenderWindow *setup_window(void);
sfVector2i get_middle_screen(sfVideoMode md);
void analyse_events(sfRenderWindow *window, sfEvent event, player_struct_t *player);
sfSprite *make_player(void);
player_struct_t *make_struct_player(void);
int detect_movement(player_struct_t *player, sfKeyEvent key_pressed);



sprite_t *map_load_one(void);

#endif /* RABBIT_H_ */
