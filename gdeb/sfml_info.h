#ifndef GDEB_SFML_INFO_H
#define GDEB_SFML_INFO_H

#include <SFML/Graphics.hpp>
struct SfmlInfo {
    sf::RenderWindow *win;
    sf::Font font;

    void OpenFont() {
        if (!font.openFromFile("/usr/share/fonts/TTF/DejaVuSansMono.ttf")) {
            abort();
        }
    }
};

#endif // GDEB_SFML_INFO_H
