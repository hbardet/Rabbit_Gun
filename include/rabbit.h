/*
** EPITECH PROJECT, 2022
** struct
** File description:
** struct
*/

#include <SFML/Window.h>
#include <SFML/System.h>
#include <SFML/Graphics.h>
#include <SFML/Audio.h>


#ifndef RABBIT_H_
    #define RABBIT_H_
typedef struct sprite sprite;
struct sprite {
    sfSprite *sprite_duck;
    sfTexture *texture_duck;
    sfSprite *sprite_background;
    sfTexture *texture_background;
};
typedef struct text text;
struct text {
    sfFont *font;
    sfText *text_score_previous;
    sfText *text_score;
    sfText *text_best_score_previous;
    sfText *text_best_score;
};
typedef struct clock clock;
struct clock {
    int score_char;
    int best_score;
    sfClock *clock;
    sfClock *clock_move;
};
typedef struct sound sound;
struct sound {
    sfSound *fire_shot;
    sfSoundBuffer *fire_shot_buffer;
    sfSound *hit;
    sfSoundBuffer *hit_buffer;
};

sfRenderWindow *setup_window(void);
sfVector2i get_middle_screen(sfVideoMode md);
void analyse_events(sfRenderWindow *window, sfEvent event);


#endif /* RABBIT_H_ */
