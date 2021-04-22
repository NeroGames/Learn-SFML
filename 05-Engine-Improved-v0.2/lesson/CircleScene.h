////////////////////////////////////////////////////////////
// Nero Game Engine - SFML Tutorials
// Copyright (c) 2021 Sanou A. K. Landry
////////////////////////////////////////////////////////////
#ifndef CIRCLESCENE_H_INCLUDED
#define CIRCLESCENE_H_INCLUDED
///////////////////////////HEADERS//////////////////////////
//Nero Games
#include "Scene.h"
#include "Gamepad.h"
//SFML
#include <SFML/Graphics.hpp>
////////////////////////////////////////////////////////////
class CircleScene : public ng::Scene
{
    private:
        //controller
        ng::Gamepad         mGamepadOne;
        //player
        struct player
        {
            sf::CircleShape     circle;
            sf::Vector2f        position;
            bool                isMovingLeft    = false;
            bool                isMovingRight   = false;
            bool                isMovingUp      = false;
            bool                isMovingDown    = false;
            float               speed           = 200.f;

        } mPlayer;

    public:
        typedef std::unique_ptr<CircleScene> Ptr;

        CircleScene()
        {
            setSceneName("Circle Scene v0.2");
        }

    public:
        void init()
        {
            //setup game controller
            mGamepadOne.setId(ng::Gamepad::ONE);
            mGamepadOne.setButtonMapping(ng::JSPs4ButtonMapping);
            mGamepadOne.setAxisMapping(ng::JSPs4AxisMapping);
            getRenderWindow().setJoystickThreshold(ng::Gamepad::AXIS_SENSIVITY);

            //step the player
                //circle shape
            mPlayer.circle.setRadius(50.f);
            mPlayer.circle.setOrigin(50.f, 50.f);
            mPlayer.circle.setFillColor(sf::Color::Green);
                //position the player at the middle of the screen
            mPlayer.position.x = getSceneResolution().x/2.f;
            mPlayer.position.y = getSceneResolution().y/2.f;
            mPlayer.circle.setPosition(mPlayer.position);
        }

        void render()
        {
            //draw the player
            getRenderWindow().draw(mPlayer.circle);
        }

        void onJoystickAxis(const unsigned int& joystickId, const sf::Joystick::Axis& axis, const float& position)
        {

            if(mGamepadOne.getId() == joystickId)
            {
                ng::JSAxis jsAxis = mGamepadOne.getAxis(axis);

                if(jsAxis == ng::JSAxis::LeftAnalogX)
                {
                    mPlayer.isMovingRight   = position > 10.f;
                    mPlayer.isMovingLeft    = position < -10.f;
                }
                else if(jsAxis == ng::JSAxis::LeftAnalogY)
                {
                   mPlayer.isMovingUp       = position < -10.f;
                   mPlayer.isMovingDown     = position > 10.f;
                }
            }
        }

        void update(const sf::Time& timeStep)
        {
            //compute new position
            if(mPlayer.isMovingLeft)
                mPlayer.position.x -= timeStep.asSeconds() * mPlayer.speed;
            else if(mPlayer.isMovingRight)
                mPlayer.position.x += timeStep.asSeconds() * mPlayer.speed;

            if(mPlayer.isMovingUp)
                mPlayer.position.y -= timeStep.asSeconds() * mPlayer.speed;
            else if(mPlayer.isMovingDown)
                mPlayer.position.y += timeStep.asSeconds() * mPlayer.speed;
            //update position
            mPlayer.circle.setPosition(mPlayer.position);

            //change player color
            if(mGamepadOne.isButtonPressed(ng::JSButton::RightAnalogLeft))
            {
                mPlayer.circle.setFillColor(sf::Color::Red);
            }
            else if(mGamepadOne.isButtonPressed(ng::JSButton::RightAnalogRight))
            {
                mPlayer.circle.setFillColor(sf::Color::Blue);
            }
            else if(mGamepadOne.isButtonPressed(ng::JSButton::R3))
            {
                mPlayer.circle.setFillColor(sf::Color::Green);
            }
        }

};

#endif // CIRCLESCENE_H_INCLUDED
