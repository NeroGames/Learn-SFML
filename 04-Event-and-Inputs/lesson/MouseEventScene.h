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
#include <SFML/Graphics.hpp>
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
            if (event.type == sf::Event::MouseMoved)
            {
                int position_x = event.mouseMove.x;
                int position_y = event.mouseMove.y;

                //callback
                onMouseMoved(sf::Vector2f(event.mouseMove.x, event.mouseMove.y));
            }

            if (event.type == sf::Event::MouseButtonPressed)
            {
                sf::Mouse::Button button    = event.mouseButton.button; //Left, Right, Middle, XButton1, XButton2
                int position_x          = event.mouseButton.x;
                int position_y          = event.mouseButton.y;

                //callback
                onMouseButton(event.mouseButton.button, true, sf::Vector2f(event.mouseButton.x, event.mouseButton.y));
            }

            if (event.type == sf::Event::MouseButtonReleased)
            {
                sf::Mouse::Button button    = event.mouseButton.button; //Left, Right, Middle, XButton1, XButton2
                int position_x          = event.mouseButton.x;
                int position_y          = event.mouseButton.y;

                onMouseButton(event.mouseButton.button, false, sf::Vector2f(event.mouseButton.x, event.mouseButton.y));
            }

            if (event.type == sf::Event::MouseWheelScrolled)
            {
                sf::Mouse::Wheel wheel  = event.mouseWheelScroll.wheel; //sf::Mouse::VerticalWheel or sf::Mouse::HorizontalWheel
                float delta         = event.mouseWheelScroll.delta;
                int position_x      = event.mouseWheelScroll.x;
                int position_y      = event.mouseWheelScroll.y;

                //callback
                onMouseWheel(event.mouseWheelScroll.wheel, event.mouseWheelScroll.delta,sf::Vector2f(event.mouseWheelScroll.x, event.mouseWheelScroll.y));
            }

            if (event.type == sf::Event::MouseEntered)
            {
                onMouseWindowSurface(true);
            }

            if (event.type == sf::Event::MouseLeft)
            {
                onMouseWindowSurface(false);
            }

        }

     private:

        void onMouseMoved(const sf::Vector2f& position)
        {

        }

        void onMouseButton(const sf::Mouse::Button& button, const &isPressed, const sf::Vector2f& position)
        {

        }

        void onMouseWheel(const sf::Mouse::Wheel& wheel, const float& delta, const sf::Vector2f& position)
        {

        }

        void onMouseWindowSurface(const bool& mouseEntered)
        {

        }

};

#endif // MOUSEEVENTSCENE_H_INCLUDED
