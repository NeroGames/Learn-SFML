////////////////////////////////////////////////////////////
// Nero Game Engine - SFML Tutorials
// Copyright (c) 2021 Sanou A. K. Landry
////////////////////////////////////////////////////////////
#ifndef GAMECONTROLLER_H_INCLUDED
#define GAMECONTROLLER_H_INCLUDED
///////////////////////////HEADERS//////////////////////////
//Nero Games
#include "Scene.h"
//SFML
#include "SFML/Graphics.hpp"
//Nero
#include "Nero/utility/Utility.h"
////////////////////////////////////////////////////////////
struct Dualshock4
{
    int             gamepadId   = 0;
    bool            connected   = false;
    unsigned int    buttonCount = 0;

    //axis
    sf::Vector2f    getFirstAxis() //Left Analog
                    {
                        return sf::Vector2f(sf::Joystick::getAxisPosition(gamepadId, sf::Joystick::X), sf::Joystick::getAxisPosition(gamepadId, sf::Joystick::Y));
                    }

     sf::Vector2f   getSecondAxis() //Second Analog
                    {
                        return sf::Vector2f(sf::Joystick::getAxisPosition(gamepadId, sf::Joystick::Z), sf::Joystick::getAxisPosition(gamepadId, sf::Joystick::R));
                    }

     sf::Vector2f   getDpadAxis() //Directional Pad
                    {
                        return sf::Vector2f(sf::Joystick::getAxisPosition(gamepadId, sf::Joystick::PovX), sf::Joystick::getAxisPosition(gamepadId, sf::Joystick::PovY));
                    }


    //Direction
    bool            isButtonPressedDpadLeft()   {return sf::Joystick::getAxisPosition(gamepadId, sf::Joystick::PovX) == 100.f;}
    bool            isButtonPressedDpadRight()  {return sf::Joystick::getAxisPosition(gamepadId, sf::Joystick::PovX) == -100.f;}
    bool            isButtonPressedDpadUp()     {return sf::Joystick::getAxisPosition(gamepadId, sf::Joystick::PovY) == 100.f;}
    bool            isButtonPressedDpadDown()   {return sf::Joystick::getAxisPosition(gamepadId, sf::Joystick::PovY) == -100.f;}
    //Action
    bool            isButtonPressedSquare()     {return sf::Joystick::isButtonPressed(gamepadId, 0);}
    bool            isButtonPressedX()          {return sf::Joystick::isButtonPressed(gamepadId, 1);}
    bool            isButtonPressedCircle()     {return sf::Joystick::isButtonPressed(gamepadId, 2);}
    bool            isButtonPressedTriangle()   {return sf::Joystick::isButtonPressed(gamepadId, 3);}
    //L,R
    bool            isButtonPressedLeftOne()    {return sf::Joystick::isButtonPressed(gamepadId, 4);}
    bool            isButtonPressedRightOne()   {return sf::Joystick::isButtonPressed(gamepadId, 5);}
    bool            isButtonPressedLeftTwo()    {return sf::Joystick::isButtonPressed(gamepadId, 6);}
    bool            isButtonPressedRightTwo()   {return sf::Joystick::isButtonPressed(gamepadId, 7);}
    bool            isButtonPressedLeftThree()  {return sf::Joystick::isButtonPressed(gamepadId, 10);}
    bool            isButtonPressedRightThree() {return sf::Joystick::isButtonPressed(gamepadId, 11);}
    //other
    bool            isButtonPressedShare()      {return sf::Joystick::isButtonPressed(gamepadId, 8);}
    bool            isButtonPressedOption()     {return sf::Joystick::isButtonPressed(gamepadId, 9);}
    bool            isButtonPressedStart()      {return sf::Joystick::isButtonPressed(gamepadId, 12);}
    bool            isButtonPressedTouchPad()   {return sf::Joystick::isButtonPressed(gamepadId, 13);}
};

////////////////////////////////////////////////////////////
class GameControllerScene : public ng::Scene
{
    private:
        sf::CircleShape     mCircle;
        sf::Vector2f        mCirclePosition;
        Dualshock4          mGamePad;

    public:
        typedef std::unique_ptr<GameControllerScene> Ptr;

        GameControllerScene()
        {
            setSceneName("Game Controller Scene v0.1");
        }

    public:
        void init()
        {
            if (sf::Joystick::isConnected(0))
            {
                mGamePad.connected      = true;
                mGamePad.buttonCount    = sf::Joystick::getButtonCount(0);

                nero_log("GamePad Number of Button : " + _s(mGamePad.buttonCount));
            }



            mCircle.setRadius(100.f);
            mCircle.setOrigin(100.f, 100.f);
            mCircle.setFillColor(sf::Color::Green);

            mCirclePosition.x = getSceneResolution().x/2.f;
            mCirclePosition.y = getSceneResolution().y/2.f;
            mCircle.setPosition(mCirclePosition);
        }

        void handleEvent(const sf::Event& event)
        {
            //default event handle (close the window)
            ng::Scene::handleEvent(event);

            //capture the mouse position
            if (event.type == sf::Event::MouseMoved)
            {
                mCirclePosition.x =  event.mouseMove.x;
                mCirclePosition.y =  event.mouseMove.y;
            }

            if(mGamePad.isButtonPressedDpadLeft())
            {
                nero_log("Dpad Left");
            }

            if(mGamePad.isButtonPressedDpadRight())
            {
                nero_log("Dpad Right");
            }

            if(mGamePad.isButtonPressedDpadUp())
            {
                nero_log("Dpad Up");
            }

            if(mGamePad.isButtonPressedDpadDown())
            {
                nero_log("Dpad Down");
            }

            if(mGamePad.isButtonPressedSquare())
            {
                nero_log("Square");
            }

            if(mGamePad.isButtonPressedX())
            {
                nero_log("X");
            }

            if(mGamePad.isButtonPressedCircle())
            {
                nero_log("Circle");
            }

            if(mGamePad.isButtonPressedTriangle())
            {
                nero_log("Triangle");
            }

            if(mGamePad.isButtonPressedShare())
            {
                nero_log("Share");
            }

            if(mGamePad.isButtonPressedOption())
            {
                nero_log("Option");
            }

            if(mGamePad.isButtonPressedStart())
            {
                nero_log("Start");
            }

            if(mGamePad.isButtonPressedLeftOne())
            {
                nero_log("L 1");
            }

            if(mGamePad.isButtonPressedLeftTwo())
            {
                nero_log("L 2");
            }

            if(mGamePad.isButtonPressedLeftThree())
            {
                nero_log("L 3");
            }

            if(mGamePad.isButtonPressedRightOne())
            {
                nero_log("R 1");
            }

            if(mGamePad.isButtonPressedRightTwo())
            {
                nero_log("R 2");
            }

            if(mGamePad.isButtonPressedRightThree())
            {
                nero_log("R 3");
            }
        }

        void update(const sf::Time& timeStep)
        {
            //mCircle.setPosition(mCirclePosition);

            //nero_log(_s(mGamePad.getFirstAxis().x) + " ; " + _s(mGamePad.getFirstAxis().y));
        }

        void render()
        {
            getRenderWindow().draw(mCircle);
        }
};

#endif // GAMECONTROLLER_H_INCLUDED
