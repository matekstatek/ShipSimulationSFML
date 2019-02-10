#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "main.h"
#include "Gauss.hpp"
#include "ResourcePath.hpp"
#include "View.hpp"
#include <math.h>
#include <unistd.h>

#define PI 3.14159

Gauss gauss;
View view;
Player ship({10, 10});
std::string man;

void zoomViewAt(sf::Vector2i pixel, sf::RenderWindow& window, float zoom)
{
    const sf::Vector2f beforeCoord{ window.mapPixelToCoords(pixel) };
    sf::View view{ window.getView() };
    view.zoom(zoom);
    window.setView(view);
    const sf::Vector2f afterCoord{ window.mapPixelToCoords(pixel) };
    const sf::Vector2f offsetCoords{ beforeCoord - afterCoord };
    view.move(offsetCoords);
    window.setView(view);
}

double startMouseX = 17.003484;
double startMouseY = 54.163741;
double tempMouseX;
double tempMouseY;

int main(int, char const**)
{
    view.setText(&text, &font);
    
    // idk why resourcePath() gives wrong path, so I had to write my own
    if(!texture.loadFromFile("/Users/statekmatek/Desktop/programming/Symulacja - Mateusz Sobolewski/simulation/simulation/img/save.png")){
        std::cout << "brak zdjęcia " << resourcePath() << std::endl;
        exit(EXIT_FAILURE);
    }
    
    sf::Sprite background (texture);
    
    startWindow.create(sf::VideoMode(1828, 1107), "Symulacje Komputerowe, grupa 142i - Mateusz Sobolewski", sf::Style::Titlebar | sf::Style::Close);
    startWindow.setPosition({600, 200});
    startWindow.setKeyRepeatEnabled(true);
    
    double tempx, tempy;
    std::ostringstream stream;
    
    stream.str("");
    stream.clear();
    
    while(startWindow.isOpen()){
        tempMouseX = startMouseX + sf::Mouse::getPosition(startWindow).x * 0.00157024;
        tempMouseY = startMouseY + abs(sf::Mouse::getPosition(startWindow).y-1107) * 0.0010725;
        sf::Event event;
        stream << "Za pomoca strzalek wybierz poczatkowyy kurs: " << -(ship.head - 180) << "\nWskaz poczatkowe miejsce jednostki klikajac na mapie.\nAktualne wspolrzedne: " << tempMouseX << "  "<< tempMouseY;
        text.setString(stream.str());
        
        while(startWindow.pollEvent(event)){
            if (event.type == sf::Event::MouseButtonPressed){
                ship.x = sf::Mouse::getPosition(startWindow).x-10;
                ship.y = sf::Mouse::getPosition(startWindow).y-10;
                startWindow.close();
            }
            if (event.type == sf::Event::Closed){
                startWindow.close();
                exit(EXIT_SUCCESS);
            }
            if (event.type == sf::Event::KeyPressed){
                if(event.key.code == sf::Keyboard::Right){
                    ship.head --;
                    ship.head = gauss.setHeading(ship.head);
                }
                if(event.key.code == sf::Keyboard::Left){
                    ship.head ++;
                    ship.head = gauss.setHeading(ship.head);
                }
            }
        }
        
        startWindow.clear(sf::Color::White);
        startWindow.draw(background);
        startWindow.draw(text);
        startWindow.display();
        
        stream.str("");
        stream.clear();
        
    }
    
    view.setControlPanel(&pasek, &pasek2, &zero, &zero2, &pkt, &pkt2, ship.xSteru, ship.ySteru, ship.xSpeed, ship.ySpeed);
    
    dane.create(sf::VideoMode(500, 600), "Dane");
    dane.setPosition({100,200});
    
    control.create(sf::VideoMode(500,507), "Sterowanie");
    control.setPosition({100, 800});
    
    window.create(sf::VideoMode(1828, 1107), "Symulacje Komputerowe, grupa 142i - Mateusz Sobolewski", sf::Style::Titlebar | sf::Style::Close);
    window.setPosition({600, 200});
    window.setKeyRepeatEnabled(true);
    
    ship.x = tempx;
    ship.y = tempy;
    
    ship.setPos({(float)ship.x, (float)ship.y});
    sf::Texture vessel;
    vessel.loadFromFile("/Users/statekmatek/Desktop/programming/Symulacja - Mateusz Sobolewski/simulation/simulation/img/ff.png");
    sf::Sprite vesselSprite(vessel);
    vesselSprite.setPosition({(float)ship.x, (float)ship.y});
    
    
    while(window.isOpen()){
        sf::Event event;
        
        newX = sin(ship.head * PI/180)*ship.speed;
        newY = cos(ship.head * PI/180)*ship.speed;
        
        ship.head += ship.alpha*1.05;
        //head *= 1.01;
        ship.head = gauss.GaussRandom(ship.head, 0.015);
        ship.head = gauss.setHeading(ship.head);
        
        
        line.setSize({50,2});
        line.setFillColor(sf::Color::Blue);
        line.setPosition(ship.x+5, ship.y+5);
        line.setRotation(-ship.head + 90);
        
        oldX = ship.x;
        oldY = ship.y;
        
        ship.x+=newX;
        ship.y+=newY;
        
        ship.odometry += sqrt(pow(ship.x-oldX, 2) + pow(ship.y-oldY, 2))/10.45;
        
        //ship.setPos({(float)x, (float)y});
        vesselSprite.setPosition({(float)ship.x-5, (float)ship.y-5});
        
        while(window.pollEvent(event)){
            switch(event.type){
                case sf::Event::Closed:
                    window.close();
                    break;
                    
                case sf::Event::KeyPressed:
                    if(event.key.code == sf::Keyboard::Left){
                        if(ship.alpha < 0.00191){
                            ship.declination--;
                            ship.xSteru -= 3;
                            ship.alpha += (0.01/156.5/1.8);
                        }
                    }
                    if(event.key.code == sf::Keyboard::Right){
                        if (ship.alpha > -0.00191){
                            ship.declination++;
                            ship.xSteru += 3;
                            ship.alpha -= (0.01/156.5/1.8);
                        }
                    }
                    if(event.key.code == sf::Keyboard::Up){
                        if(ship.speed <= 0.019/32.1){
                        ship.ySpeed -= 8;
                        ship.speed += 0.001/32.1;
                        }
                    }
                    if(event.key.code == sf::Keyboard::Down){
                        if(ship.speed >= -0.019/32.1){
                        ship.ySpeed += 8;
                        ship.speed -= 0.001/32.1;
                        }
                    }
                    
                    break;
                    
                case sf::Event::MouseWheelScrolled:
                    if (event.mouseWheelScroll.delta > 0)
                        zoomViewAt({ event.mouseWheelScroll.x, event.mouseWheelScroll.y }, window, (1.f / zoomAmount));
                    else if (event.mouseWheelScroll.delta < 0)
                        zoomViewAt({ event.mouseWheelScroll.x, event.mouseWheelScroll.y }, window, zoomAmount);
                    break;
                    
                case sf::Event::MouseButtonPressed:
                    mPos_old = sf::Mouse::getPosition(window);
                    break;
                    
                case sf::Event::MouseButtonReleased:
                    mPos = sf::Mouse::getPosition(window);
                    sf::View view{window.getView()};
                    view.move((mPos_old.x - mPos.x) * 1/zoomAmount, (mPos_old.y - mPos.y)*1/zoomAmount);
                    window.setView(view);
                    break;
            }
        }
        oss.clear();
        oss.str("");
        
        if (round(ship.speed*100339.28283) == 0) man = "Zerowe";
        else if (round(ship.speed*100339.28283) > 0) man = "Naprzod";
        else man = "Wstecz";
        
        tempMouseX = startMouseX + ship.x * 0.00157024;
        tempMouseY = startMouseY + abs(ship.y-1107) * 0.0010725;
        
        
        oss << "Kurs: " << round((180-ship.head)*100)/100<< "\nWychylenie: " << abs(round(ship.alpha*15649.9911));
        (round(ship.alpha*15649.9911) < 0) ? oss << " prawo" : (round(ship.alpha*15649.9911) > 0)? oss << " lewo" : oss << "";
        oss << "\nPredkosc: " << abs(round(ship.speed*100339.28283)) << " km/h, " << abs(round(ship.speed*100339.28283/1.852)) << " wezly" << std::endl << "Polozenie manetki: " << man << std::endl << "Odleglosc: " << round(ship.odometry*100)/100 << " km / " << round(ship.odometry*100/1.852)/100 << " mil" << std::endl << std::endl << "WSPOLRZEDNE "<< std::endl << "fi:\t\t\t\t" << tempMouseY << std::endl << "lambda: \t" << tempMouseX;
        
        text.setString(oss.str());
        pkt.setPosition(ship.xSteru, ship.ySteru);
        pkt2.setPosition(ship.xSpeed, ship.ySpeed);
        
        window.clear(sf::Color::White);
        dane.clear(sf::Color::White);
        control.clear(sf::Color::White);
        window.draw(background);
        
        window.draw(line);
        window.draw(vesselSprite);
        
        control.draw(pasek);
        control.draw(zero);
        control.draw(pkt);
        
        control.draw(pasek2);
        control.draw(zero2);
        control.draw(pkt2);
        dane.draw(text);
        
        dane.display();
        control.display();
        window.display();
    }
}
