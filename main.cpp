/**
 * @file Contains the main function.
 * @author Tobias Mayer
 * @date 15.04.2024
*/

#include <SFML/Graphics.hpp>
#include <iostream>
#include <memory>

int main() {
    static constexpr int WWIDTH = 800;
    static constexpr int WHEIGHT = 600;
    std::shared_ptr<sf::RenderWindow> window = std::make_shared<sf::RenderWindow>(sf::VideoMode(WWIDTH, WHEIGHT), "RaycastingApp");
    sf::Event event;
    bool runApp = true;

    window->setVerticalSyncEnabled(true);
    
    while ( runApp ) {
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

    window->display();
    return 0;
} // int main()