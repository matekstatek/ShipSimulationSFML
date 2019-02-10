//
//  Player.h
//  simulation
//
//  Created by Matek on 18.12.2017.
//  Copyright © 2017 Matek. All rights reserved.
//
#include <iostream>
#include <SFML/Graphics.hpp>

#ifndef Player_h
#define Player_h

class Player {
public:
    double odometry = 0;
    double head = 180;
    double alpha = 0;
    double xSteru = 175;
    double ySteru = 100;
    double xSpeed = 420;
    double ySpeed = 275;
    double x = 50;
    double y = 500;
    double speed = 0;
    double newX;
    double newY;
    int declination = 0;
    
    Player(sf::Vector2f size) {
        player.setSize(size);
        player.setFillColor(sf::Color::Black);
    }
    
    void drawTo(sf::RenderWindow &window) {
        window.draw(player);
    }
    
    void move(sf::Vector2f distance) {
        player.move(distance);
    }
    
    void setPos(sf::Vector2f newPos) {
        player.setPosition(newPos);
    }
    
private:
    sf::RectangleShape player;
};

#endif /* Player_h */
