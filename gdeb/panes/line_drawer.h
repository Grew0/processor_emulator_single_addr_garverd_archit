#ifndef GDEB_PANES_LINE_DRAWER_H
#define GDEB_PANES_LINE_DRAWER_H

#include "gdeb/sfml_info.h"

struct LineDrawer {
  public:
    LineDrawer(SfmlInfo &info, float scrollY)
        : scrollY(scrollY), sfmlInfo(info), txt(sfmlInfo.font) {
        txt.setCharacterSize(20);
        txt.setFillColor(sf::Color::Black);
    }

    float scrollY = 0;
    float mxX = 0;
    SfmlInfo &sfmlInfo;
    sf::Text txt;
    sf::Vector2f hilight_margin = sf::Vector2f(5, 5);

    void DrawText(std::string &s, int line, float xOffset, bool hilight) {
        txt.setString(sf::String(s));
        float y = line * txt.getCharacterSize() + scrollY;
        txt.setPosition({xOffset, y});
        sf::Vector2f rsSize = txt.getLocalBounds().size + 2.f * hilight_margin;

        mxX = std::max<float>(mxX, rsSize.x);

        if (hilight) {

            sf::RectangleShape sp(rsSize);

            sp.setFillColor(sf::Color::Red);
            sp.setPosition(txt.getLocalBounds().position +
                           sf::Vector2f(xOffset, y) - hilight_margin);
            sfmlInfo.win->draw(sp);
        }
        sfmlInfo.win->draw(txt);
    }
};

#endif // GDEB_PANES_LINE_DRAWER_H
