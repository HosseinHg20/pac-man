#ifndef GHOST_HPP
#define GHOST_HPP

#include <SFML/Graphics.hpp>
#include <pacman/animation.hpp>
#include <pacman/randomizeMove.hpp>
#include <pacman/map.hpp>
#include <pacman/ghostAnimations.hpp>
#include <vector>

enum class AnimationStatus {Left, Right, DiedLeft, DiedRight, Scared};

class Ghost
{
private:
    Map & map;
    sf::RectangleShape ghost;
    Animation * animation;
    AnimationStatus animationStatus = AnimationStatus::Right;
    RandomizeMove move;
public:
    Ghost(Map & map, float speed);
    ~Ghost();
    void changeAnimationStatus(AnimationStatus animationStatus);

    void update();
    sf::RectangleShape getShape();
};



#endif // GHOST_HPP