////////////////////////////////////////////////////////////
// Nero Game Engine - SFML Tutorials
// Copyright (c) 2021 Sanou A. K. Landry
////////////////////////////////////////////////////////////
#ifndef JOYSTICKEVENTSCENE_H_INCLUDED
#define JOYSTICKEVENTSCENE_H_INCLUDED
///////////////////////////HEADERS//////////////////////////
//Nero Games
#include "Scene.h"
#include "Gamepad.h"
//SFML
#include <SFML/Graphics.hpp>
////////////////////////////////////////////////////////////
class JoystickEventScene : public ng::Scene
{
    private:
        ng::Gamepad mGamepadOne;

    public:
        typedef std::unique_ptr<JoystickEventScene> Ptr;

        JoystickEventScene()
        {
            setSceneName("Joystick Event Scene v0.1");
        }

        void init()
        {
            mGamepadOne.setId(ng::Gamepad::ONE);
            mGamepadOne.setButtonMapping(ng::JSPs4ButtonMapping);
            mGamepadOne.setAxisMapping(ng::JSPs4AxisMapping);
            mGamepadOne.setConnected(sf::Joystick::isConnected(mGamepadOne.getId()));
            getRenderWindow().setJoystickThreshold(ng::Gamepad::AXIS_SENSIVITY);
        }

        void handleEvent(const sf::Event& event)
        {
            if (event.type == sf::Event::JoystickConnected)
            {
                unsigned int joystickId = event.joystickConnect.joystickId;

                //callback
                onJoystickConnection(event.joystickConnect.joystickId, true);
            }

            else if (event.type == sf::Event::JoystickDisconnected)
            {
                unsigned int joystickId = event.joystickConnect.joystickId;

                //callback
                onJoystickConnection(event.joystickConnect.joystickId, false);
            }

            if (event.type == sf::Event::JoystickButtonPressed)
            {
                unsigned int joystickId = event.joystickButton.joystickId;
                unsigned int button     = event.joystickButton.button;

                //callback
                onJoystickButton(event.joystickButton.joystickId, event.joystickButton.button, true);
            }

            if (event.type == sf::Event::JoystickButtonReleased)
            {
                unsigned int joystickId = event.joystickButton.joystickId;
                unsigned int button     = event.joystickButton.button;

                //callback
                onJoystickButton(event.joystickButton.joystickId, event.joystickButton.button, false);
            }

            if (event.type == sf::Event::JoystickMoved)
            {
                unsigned int joystickId = event.joystickMove.joystickId;
                sf::Joystick::Axis axis = event.joystickMove.axis;
                float position          = event.joystickMove.position;

                //callback
                onJoystickAxis(event.joystickMove.joystickId, event.joystickMove.axis, event.joystickMove.position);
            }
        }

    private:

        void onJoystickConnection(const unsigned int& joystickId, const bool& connected)
        {
            if(mGamepadOne.getId() == joystickId)
            {
                mGamepadOne.setConnected(connected);

                std::string info = connected ? "gamepad connection" : "gamepad disconnection";

                nero_log(info);
            }
        }

        void onJoystickButton(const unsigned int& joystickId, const unsigned int& button, const bool& isPressed)
        {
            if(mGamepadOne.getId() == joystickId && mGamepadOne.isConnected())
            {
                ng::JSButton jsButton = mGamepadOne.getButton(button);

                std::string info = ng::JString(jsButton) + " " + (isPressed ? "Pressed" : "Released");

                nero_log(info);
            }
        }

        void onJoystickAxis(const unsigned int& joystickId, const sf::Joystick::Axis& axis, const float& position)
        {

            if(mGamepadOne.getId() == joystickId && mGamepadOne.isConnected())
            {
                ng::JSAxis jsAxis = mGamepadOne.getAxis(axis);

                nero_log(ng::JString(jsAxis) + " " + _se(position));
            }
        }
};


#endif // JOYSTICKEVENTSCENE_H_INCLUDED
