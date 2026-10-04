#include "debbuger.h"
#include "proc/proc.h"
#include "sfml_info.h"
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Mouse.hpp>

std::unique_ptr<SfmlInfo> OpenSfmlInfo() {
    auto sfmlInfo = std::make_unique<SfmlInfo>();
    sfmlInfo->OpenFont();
    return sfmlInfo;
}

void GDeb::Start() {
    assert(proc != nullptr);
    sf::RenderWindow win(sf::VideoMode({800, 600}), "sfml");

    auto sfmlInfo = OpenSfmlInfo();
    sfmlInfo->win = &win;

    win.setFramerateLimit(20);
    while (win.isOpen()) {
        while (auto ev = win.pollEvent()) {
            if (ev->is<sf::Event::Closed>()) {
                win.close();
            }
            if (auto key = ev->getIf<sf::Event::KeyPressed>()) {
                if (key->scancode == sf::Keyboard::Scan::N) {
                    proc->ExecuteOne();
                } else if (key->scancode == sf::Keyboard::Scan::Escape) {
                    win.close();
                }
            }
        }

        win.clear(sf::Color(166, 166, 166));

        sf::RectangleShape border(sf::Vector2f(10, win.getSize().y));
        border.setFillColor(sf::Color::Black);
        int startX = 0;

        auto DrawBorder = [&border, &win, &startX]() {
            startX += border.getSize().x / 2;
            border.setPosition({static_cast<float>(startX), 0.f});
            win.draw(border);
            startX += border.getSize().x * 1.5;
        };

        disasmPane.Draw(*sfmlInfo, proc, startX);
        DrawBorder();
        registersPane.Draw(*sfmlInfo, proc, startX);
        DrawBorder();
        memPane.Draw(*sfmlInfo, proc, startX);
        win.display();
    }
}
