////////////////////////////////////////////////////////////
// Nero Game Engine - SFML Tutorials
// Copyright (c) 2021 Sanou A. K. Landry
////////////////////////////////////////////////////////////
#ifndef GAMEPAD_H
#define GAMEPAD_H
///////////////////////////HEADERS//////////////////////////
//Nero Games
#include <GamepadUtil.h>
////////////////////////////////////////////////////////////
namespace ng
{
    class Gamepad
    {
        public:
            enum ID {ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, HEIGHT, NONE};
            static const float AXIS_SENSIVITY;

        public:
                                Gamepad();

            void                setId(const ID& gamepadId);
            void                setConnected(const bool& connected);
            void                setButtonMapping(const JSButtonMapping& mapping);
            void                setAxisMapping(const JSAxisMapping& mapping);

            const ID            getId() const;
            bool                isConnected() const;
            JSButton            getButton(const unsigned int& buttonId);
            JSAxis              getAxis(const sf::Joystick::Axis& axisId);

        protected:
            ID                  mGamepadId;
            bool                mConnected;
            JSButtonMapping     mButtonMapping;
            JSAxisMapping       mAxisMapping;
    };
}

#endif // GAMEPAD_H
