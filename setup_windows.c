/*
** EPITECH PROJECT, 2022
** my_hunter
** File description:
** setup_windows
*/
#include <SFML/Audio.h>
#include <stdio.h>
#include <SFML/Graphics.h>
#include <stdlib.h>
#include <SFML/Window.h>

sfVector2i get_middle_screen(sfVideoMode md)
{
    sfVideoMode scn = sfVideoMode_getDesktopMode();
    
    sfVector2i posi = {(scn.width / 2) - (md.width / 2),
    (scn.height / 2) - (md.height / 2)};
    return (posi);
}

sfRenderWindow *setup_window(void)
{
    sfVideoMode mode = {1280,720,32};
    sfRenderWindow *window = sfRenderWindow_create(mode, "Rabbit Guns", sfClose, NULL);
    sfRenderWindow_setFramerateLimit(window, 32);
    sfVector2i posi = get_middle_screen(mode);
    sfRenderWindow_setPosition(window, posi);
    return (window);
}