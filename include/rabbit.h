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
#include <stdbool.h>     
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
   
   bool move_up;
   bool move_down;
   bool move_left;
   bool move_right;
    
}controle_key_t;

typedef struct bullet_list{
    sfIntRect rect;
    sfVector2f position;
    bool touching;
    sfSprite *bullet_sprite;
    sfClock *clock;
    int num_bullet;
    struct bullet_list *next;
}bullet_list_t;

typedef struct player_struct {

    sfSprite *sprite_player;
    sfTexture *texture_player;
    sfIntRect rect;
    controle_key_t *controle;
    sfClock *clock_player;
    bool can_shoot;
    int nb_player;
    int orientation_player;

    bullet_list_t *bullet; 
}player_struct_t;

sfRenderWindow *setup_window(void);
sfVector2i get_middle_screen(sfVideoMode md);
void analyse_events(sfRenderWindow *window, sfEvent event, player_struct_t *player_one,player_struct_t *player_two);
player_struct_t *make_player(sfVector2f pos);
player_struct_t *make_struct_player(sfVector2f pos);
int memo_key_released(player_struct_t *player_one, player_struct_t *player_two, sfKeyEvent key_released);
int memo_key_pressed(player_struct_t *player_one, player_struct_t *player_two, sfKeyEvent key_pressed);
controle_key_t *make_struct_controle(void);
int detect_movement(player_struct_t *player,sprite_t *sprite);
int my_colorcmp(sfColor color1, sfColor color2);
sfColor get_pixel_color(sprite_t *sprite, int x, int y);
int colision_player(sprite_t *sprite,int x, int y);
int up_player(sprite_t *sprite,int x, int y);
void clock_sprite(sfClock *clock, player_struct_t *player);
void move_rect(sfIntRect *rect, int offset, int max_value);
void reset_rect(player_struct_t *player);
sprite_t *map_load_one(void);
int bullet_shoot(player_struct_t *player, sfMouseButtonEvent mousse_click);
bullet_list_t *add_node_bullet(player_struct_t *player);
int create_bullet(bullet_list_t **bullet, player_struct_t *player);
int my_struct_len(bullet_list_t *list);
int display_bullet_on_screen(sfRenderWindow *window, player_struct_t *player);
int move_bullet(player_struct_t *player);
int manage_bullet(sfRenderWindow *window, player_struct_t *player);
int destroy_bullet(player_struct_t *player);
int delete_bullet_node(bullet_list_t **list);
bullet_list_t *delete_last_node(bullet_list_t **list);








#endif /* RABBIT_H_ */
