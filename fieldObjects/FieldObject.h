#ifndef SNAKE_FIELDOBJECT_H
#define SNAKE_FIELDOBJECT_H


#include <SFML/Graphics/Shape.hpp>

class FieldObject {
public:
    enum class OnEaten {
        GROW,
        DIE
    };

    virtual ~FieldObject() = default;
    virtual const sf::Shape &getSprite() const = 0;
    virtual OnEaten onEaten() const = 0;
};


#endif //SNAKE_FIELDOBJECT_H
