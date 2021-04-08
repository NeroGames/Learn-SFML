////////////////////////////////////////////////////////////
// Nero Game Engine - SFML Tutorials
// Copyright (c) 2021 Sanou A. K. Landry
////////////////////////////////////////////////////////////
#ifndef MOUSEEVENTSCENE_H_INCLUDED
#define MOUSEEVENTSCENE_H_INCLUDED
///////////////////////////HEADERS//////////////////////////
//Nero Games
#include "Scene.h"
//SFML
#include "SFML/Graphics.hpp"
////////////////////////////////////////////////////////////
class MouseEventScene : public ng::Scene
{
     public:
        typedef std::unique_ptr<MouseEventScene> Ptr;

        MouseEventScene()
        {
            setSceneName("Mouse Event Scene v0.1");
        }

        void handleEvent(const sf::Event& event)
        {

            if (event.type == sf::Event::MouseWheelScrolled)
            {

            }

            if (event.type == sf::Event::MouseButtonPressed)
            {

            }

            if (event.type == sf::Event::MouseButtonReleased)
            {

            }

            if (event.type == sf::Event::MouseMoved)
            {

            }

            if (event.type == sf::Event::MouseEntered)
            {

            }

            if (event.type == sf::Event::MouseLeft)
            {

            }

        }
};

#endif // MOUSEEVENTSCENE_H_INCLUDED
