#ifndef MAP_HPP
#define MAP_HPP

#include <SFML/Graphics.hpp>
#include <vector>
#include <pacman/food.hpp>

class Map
{
private:
    std::vector<sf::RectangleShape> blocks;
    std::vector<fd::Food> foods;
    sf::RectangleShape leftTeleport;
    sf::RectangleShape rightTeleport;
    sf::Time _time;
    int h_block;
    int w_block;
    int foodCounter = 0;
    int specialFoodNumber = -1;
public:
    sf::Clock _clock;
    Map(int h, int w);
    void draw(sf::RenderWindow & window);
    int accident(sf::RectangleShape & shape);

    void setRandomFood(fd::Type t);
    void checkSpecoalFood();
    int getFoodCounter();
};



#endif // MAP_HPP