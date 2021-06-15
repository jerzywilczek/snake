//
// Created by jerzy on 6/14/21.
//

#ifndef SNAKE_GAMEDRAWER_H
#define SNAKE_GAMEDRAWER_H


#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include "area/Area.h"

class GameDrawer {
public:
    GameDrawer(sf::RenderWindow *window, int width, int height, int fieldLen, sf::Time minTimePerMove,
               sf::Time maxTimePerMove, const sf::Color &backgroundColor, const sf::Color &wallColor,
               const sf::Color &snakeColor, const sf::Color &foodColor);

    void update(sf::Time deltaTime);
    void keyPressed(sf::Keyboard::Key key);

private:
    int width;
    int height;
    int fieldLen;
    sf::RenderWindow *window;
    const sf::Time minTimePerMove;
    const sf::Time maxTimePerMove;
    Area area;
    sf::RectangleShape empty;
    sf::RectangleShape wall;
    sf::RectangleShape snake;
    sf::RectangleShape food;

    static double squeezeFunction(double x) ;

};


#endif //SNAKE_GAMEDRAWER_H
