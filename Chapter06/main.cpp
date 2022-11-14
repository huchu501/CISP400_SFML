// Chapter06.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Pong Game

#include "Bat.h"
#include <iostream>
#include <sstream>
#include <cstdlib>

using namespace std;

int main()
{
    VideoMode vm(1920, 1080);
    RenderWindow window(vm, "Pong", Style::Default);
    int score = 0;
    int lives = 3;

    Bat bat(1920 / 2, 1080 - 20);

    Text hud;
    Font font;
    font.loadFromFile("fonts/DS-DIGIT.TTF");
    hud.setFont(font);
    hud.setCharacterSize(75);
    hud.setPosition(20, 20);
    hud.setFillColor(Color::White);

    Clock clock;

    /*------------------------------------------------*/
    /*                 MAIN GAME LOOP                 */
    /*------------------------------------------------*/

    while (window.isOpen())
    {
        /*------------------------------------------------*/
        /*               Handle User Input                */
        /*------------------------------------------------*/
        Event event;
        while (window.pollEvent(event))     // loop for windows queued events like mouse click, key press etc.
        {
            if (event.type == Event::Closed)
            {
                window.close();
            }
        }
        if (Keyboard::isKeyPressed(Keyboard::Escape))
        {
            window.close();
        }
        if (Keyboard::isKeyPressed(Keyboard::Left))
        {
            bat.moveLeft();
        }
        else
        {
            bat.stopLeft();
        }
        if (Keyboard::isKeyPressed(Keyboard::Right))
        {
            bat.moveRight();
        }
        else
        {
            bat.stopRight();
        }

        /*------------------------------------------------*/
        /*                 Update Objects                 */
        /*------------------------------------------------*/

        Time dt = clock.restart();
        bat.update(dt);
        stringstream ss;
        ss << "Score: " << score << "   Lives: " << lives;  // feed variables and text into it as if were cout and store it as a string
        hud.setString(ss.str());

        /*------------------------------------------------*/
        /*                     Draw                       */
        /*------------------------------------------------*/

        window.clear();
        window.draw(hud);
        window.draw(bat.getShape());
        window.display();
    }


}
