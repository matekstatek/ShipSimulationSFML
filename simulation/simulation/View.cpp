//
//  View.cpp
//  simulation
//
//  Created by Matek on 21.01.2018.
//  Copyright © 2018 Matek. All rights reserved.
//

#include "View.hpp"
#include <SFML/Graphics.hpp>
#include "ResourcePath.hpp"

void View::setText (sf::Text *text, sf::Font *font){
    font->loadFromFile(resourcePath() + "sansation.ttf");
    text->setFont(*font);
    text->setString("");
    text->setCharacterSize(30);
    text->setFillColor(sf::Color::Black);
    text->setStyle(sf::Text::Bold);
}

void View::setControlPanel (sf::RectangleShape *pasek, sf::RectangleShape *pasek2, sf::RectangleShape *zero, sf::RectangleShape *zero2, sf::RectangleShape *pkt, sf::RectangleShape *pkt2, double xSteru, double ySteru, double xSpeed, double ySpeed){
    zero2->setFillColor(sf::Color::Black);
    zero2->setSize({25,25});
    zero2->setPosition(420, 275);
    pkt2->setSize({25,25});
    pkt2->setPosition(xSpeed, ySpeed);
    pasek2->setSize({25,400});
    pasek2->setPosition(420, 100);
    pasek2->setFillColor(sf::Color::Red);
    
    zero->setFillColor(sf::Color::Black);
    zero->setSize({25,25});
    zero->setPosition(175, 100);
    pkt->setSize({25,25});
    pkt->setPosition(xSteru, ySteru);
    pasek->setSize({400,25});
    pasek->setPosition(0, 100);
    pasek->setFillColor(sf::Color::Red);
}
