//
//  main.h
//  simulation
//
//  Created by Matek on 22.12.2017.
//  Copyright © 2017 Matek. All rights reserved.
//

#include <sstream>
#include <string>

#ifndef main_h
#define main_h

double oldX, oldY;
double newX;
double newY;

const float zoomAmount{ 1.1f };

std::ostringstream oss;
sf::RenderWindow window;
sf::RenderWindow startWindow;
sf::RenderWindow control;
sf::Vector2i mPos;
sf::Vector2i mPos_old;
sf::Texture texture;
sf::Image icon;
sf::RectangleShape line;
sf::RenderWindow dane;

sf::Text text;
sf::Font font;

sf::RectangleShape pasek;
sf::RectangleShape pkt;
sf::RectangleShape zero;

sf::RectangleShape pasek2;
sf::RectangleShape pkt2;
sf::RectangleShape zero2;


#endif /* main_h */
