#ifndef PACMAN_HPP
#define PACMAN_HPP

#include <SFML/Graphics.hpp>
#include <pacman/animation.hpp>
#include <pacman/move.hpp>

class Pacman 
{
private:
    sf::RectangleShape pacman;
    Animation animation;
    Move move;
    int score = 0;
public:
    Pacman(float speed = 0.1, int r = 32);
    
    void update();
    sf::RectangleShape & getShape();
    void rotate(DIRECTION dir);
    void back();
    void stop(bool stop);
    void scorePlus(int s);
    int getScore();
};

#endif // PACMAN_HPP