////////////////////////////////////////////////////////////
// Nero Game Engine - SFML Tutorials
// Copyright (c) 2021 Sanou A. K. Landry
////////////////////////////////////////////////////////////
#include <SFML/Graphics.hpp>

int main()
{
    //Create Graphics Window
        //window parameters
    sf::Vector2u    window_resolution(1080, 720);
    std::string     window_title = "Graphics Window";
        //create the window
    sf::RenderWindow renderWindow(sf::VideoMode(window_resolution.x, window_resolution.y), window_title);

    //Initialize your game here
        //let's create a simple circle and draw it later
    sf::CircleShape circle;
    circle.setRadius(50.f);
    circle.setOrigin(50.f, 50.f);
    circle.setFillColor(sf::Color::Green);
    circle.setPosition(window_resolution.x/2.f, window_resolution.y/2.f); //center of the screen

    //Game loop
    while (renderWindow.isOpen())
    {
        //handle input events

        //1- Create an empty Event. (Message = "")
        sf::Event event;
        //2- Catch and store the last event inside our empty event object (Message = "something")
        while (renderWindow.pollEvent(event))
        {
            //3- if (Message = The close button has been clicked on) close the window
            if (event.type == sf::Event::Closed)
                renderWindow.close();
        }


        //update your game here
            //we have nothing to update, so it's empty


        //clear the screen with a black color
        renderWindow.clear(sf::Color::Black);
            //draw your game here (it happens in the background, the drawing want be visible yet)
                //let's draw our circle
            renderWindow.draw(circle);
        //display your screen (now everything becomes visible)
        renderWindow.display();
    }

    return 0;
}
