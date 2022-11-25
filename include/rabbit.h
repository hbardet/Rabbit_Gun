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
typedef struct sprite {
    sfSprite *sprite_duck;
    sfTexture *texture_duck;
    sfSprite *sprite_background;
    sfTexture *texture_background;
}sprite_t;

typedef struct text{
    sfFont *font;
    sfText *text_score_previous;
    sfText *text_score;
    sfText *text_best_score_previous;
    sfText *text_best_score;
}text_t;

typedef struct clock {
    int score_char;
    int best_score;
    sfClock *clock;
    sfClock *clock_move;
}clock_t;

typedef struct sound {
    sfSound *fire_shot;
    sfSoundBuffer *fire_shot_buffer;
    sfSound *hit;
    sfSoundBuffer *hit_buffer;
}sound_t;

sfRenderWindow *setup_window(void);
sfVector2i get_middle_screen(sfVideoMode md);
void analyse_events(sfRenderWindow *window, sfEvent event);


#endif /* RABBIT_H_ */
