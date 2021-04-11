////////////////////////////////////////////////////////////
// Nero Game Engine - SFML Tutorials
// Copyright (c) 2021 Sanou A. K. Landry
////////////////////////////////////////////////////////////
///////////////////////////HEADERS//////////////////////////
#include "Gamepad.h"
////////////////////////////////////////////////////////////
namespace ng
{
    //
    const float Gamepad::AXIS_SENSIVITY = 6.f;

    Gamepad::Gamepad():
         mGamepadId(Gamepad::NONE)
        ,mConnected(false)
        ,mButtonMapping()
        ,mAxisMapping()
    {
        //ctor
    }

    void Gamepad::setId(const Gamepad::ID& gamepadId)
    {
        mGamepadId = gamepadId;
    }

    void Gamepad::setConnected(const bool& connected)
    {
        mConnected = connected;
    }

    void Gamepad::setButtonMapping(const JSButtonMapping& mapping)
    {
        mButtonMapping = mapping;
    }

    void Gamepad::setAxisMapping(const JSAxisMapping& mapping)
    {
        mAxisMapping = mapping;
    }

    const Gamepad::ID Gamepad::getId() const
    {
        return mGamepadId;
    }

    bool Gamepad::isConnected() const
    {
        return mConnected;
    }

    JSButton Gamepad::getButton(const unsigned int& buttonId)
    {
        return mButtonMapping.at(buttonId);
    }

    JSAxis Gamepad::getAxis(const sf::Joystick::Axis& axisId)
    {
        return mAxisMapping.at(axisId);
    }

}
