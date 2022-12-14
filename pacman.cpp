#include <pacman/pacman.hpp>


Pacman::Pacman(Map & m, float speed, int r) : pacman(sf::Vector2f(r * 2 - 2, r * 2 - 2)), 
                                            animation(&pacman, "./images/pacman1.png", 0.1), move(m, pacman, speed),
                                            map(m)
{
    pacman.setOrigin(r - 1, r - 1);
    pacman.setPosition(336, 624);
    animation.addTexture("./images/pacman2.png");
    animation.addTexture("./images/pacman3.png");
    animation.addTexture("./images/pacman4.png");
    animation.addTexture("./images/pacman5.png");
    animation.addTexture("./images/pacman6.png");
}


void Pacman::update()
{
    animation.update();
    move.step();
}

sf::RectangleShape & Pacman::getShape()
{
    return pacman;
}

void Pacman::rotate(DIRECTION dir)
{
    move.setRotate(dir);
}
void Pacman::back()
{
    move.back();
}


void Pacman::stop(bool stop)
{
    if (stop)
    {
        animation.setenable(false);
        move.setenable(false);
    }
    else
    {
        animation.setenable(true);
        move.setenable(true);
    }
}

void Pacman::scorePlus(int s)
{
    score += s;
}
int Pacman::getScore() const
{
    return score;
}

int Pacman::getHP() const
{
    return hp;
}
int Pacman::subHP()
{
    hp--;
    return hp;
}


void Pacman::restart(bool m, bool h, bool s)
{
    pacman.setPosition(336, 624);
    rotate(DIRECTION::RIGHT);
    stop(true);
    if (m)
        map.restart();
    if (h)
        hp = 3;
    if (s)
        score = 0;
}

void Pacman::backToHome()
{
    pacman.setPosition(336, 624);
    rotate(DIRECTION::RIGHT);
}