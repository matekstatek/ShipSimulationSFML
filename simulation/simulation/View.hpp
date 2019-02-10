//
//  View.hpp
//  simulation
//
//  Created by Matek on 21.01.2018.
//  Copyright © 2018 Matek. All rights reserved.
//

#ifndef View_hpp
#define View_hpp

#include <stdio.h>
#include <SFML/Graphics.hpp>

class View{
public:
    void setText(sf::Text *text, sf::Font *font);
    void setControlPanel(sf::RectangleShape *pasek, sf::RectangleShape *pasek2, sf::RectangleShape *zero, sf::RectangleShape *zero2, sf::RectangleShape *pkt, sf::RectangleShape *pkt2, double xSteru, double ySteru, double xSpeed, double ySpeed);
};

#endif /* View_hpp */
