/*
** JAM GAME
** rabbit_gun
** File description:
** main.c
*/
#include "rabbit.h"
#include <SFML/Graphics.h>

int main()
{
    sfRenderWindow *window = setup_window();
    sfEvent event;
    
    while (sfRenderWindow_isOpen(window)){
        analyse_events(window ,event);
        sfRenderWindow_display(window);
    }
    sfRenderWindow_destroy(window);
    return (0);
}