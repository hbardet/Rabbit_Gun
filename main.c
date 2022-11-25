/*
** JAM GAME
** rabbit_gun
** File description:
** main.c
*/

int main()
{
    sfRenderWindow *window = setup_window();
    sfEvent event;
    background_t *background = create_struct_bg();
    sfClock *clock = sfClock_create();
    
    while (sfRenderWindow_isOpen(window)){
        analyse_events(window ,event);
        show_background(background, window);
        sfRenderWindow_display(window);
    }
    sfRenderWindow_destroy(window);
    return (0);
}