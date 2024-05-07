/**
 * @file Contains the main function.
 * @author Tobias Mayer
 * @date 15.04.2024
*/

#include <SFML/Graphics.hpp>
#include <iostream>
#include <memory>

#include "include/randomConvexShape.hpp"

int main() {
    static constexpr int WWIDTH = 800;
    static constexpr int WHEIGHT = 600;
    std::shared_ptr<sf::RenderWindow> window = std::make_shared<sf::RenderWindow>(sf::VideoMode(WWIDTH, WHEIGHT), "RaycastingApp");
    sf::Event event;
    bool runApp = true;
    RandomConvexShape shape(sf::Vector2f(200, 200), sf::Vector2i(350, 150), 6);
    sf::RectangleShape bbox(sf::Vector2f(350,150));
    bbox.setOrigin(175,75);
    bbox.setOutlineColor(sf::Color::Blue);
    bbox.setOutlineThickness(4.f);
    bbox.setPosition(shape.getPosition());
    sf::CircleShape point(4.f);
    point.setFillColor(sf::Color::Red);
    point.setOrigin(sf::Vector2f(2,2));
    point.setPosition(shape.getPosition());

    window->setVerticalSyncEnabled(true);
    
    while ( runApp ) {
        window->draw(bbox);
        window->draw(shape);
        window->draw(point);
        
        window->display();
        while ( window->pollEvent(event) ) {
            switch ( event.type ) {
                case sf::Event::Closed:
                    runApp = false;
                break;
                case sf::Event::KeyReleased:
                    if ( event.key.scancode == sf::Keyboard::Scan::Escape || event.key.scancode == sf::Keyboard::Scan::X ) {
                        runApp = false;
                    } // if ( event.key.scancode == sf::Keyboard::Scan::Escape || event.key.scancode == sf::Keyboard::Scan::X )
                break;
                default:
                break;
            } // switch ( event.type )
        } // while ( window->pollEvent(event) )
    } // while ( runApp )
    return 0;
} // int main()