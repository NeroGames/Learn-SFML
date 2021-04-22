////////////////////////////////////////////////////////////
// Nero Game Engine - SFML Tutorials
// Copyright (c) 2021 Sanou A. K. Landry
////////////////////////////////////////////////////////////
#ifndef KEYBOARDUTIL_H_INCLUDED
#define KEYBOARDUTIL_H_INCLUDED
///////////////////////////HEADERS//////////////////////////
//SFML
#include <SFML/Window/Keyboard.hpp>
////////////////////////////////////////////////////////////
namespace ng
{
    struct ModifierKey
    {
        bool alt        = false;
        bool control    = false;
        bool shift      = false;
        bool system     = false;
    };

    inline bool CTRL()
    {
        return   sf::Keyboard::isKeyPressed(sf::Keyboard::LControl) &&
                !sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) &&
                !sf::Keyboard::isKeyPressed(sf::Keyboard::LAlt);
    }

    inline bool SHIFT()
    {
        return  !sf::Keyboard::isKeyPressed(sf::Keyboard::LControl) &&
                 sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) &&
                !sf::Keyboard::isKeyPressed(sf::Keyboard::LAlt);
    }

    inline bool ALT()
    {
        return  !sf::Keyboard::isKeyPressed(sf::Keyboard::LControl) &&
                !sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) &&
                 sf::Keyboard::isKeyPressed(sf::Keyboard::LAlt);
    }

    inline bool CTRL_SHIFT()
    {
        return   sf::Keyboard::isKeyPressed(sf::Keyboard::LControl) &&
                 sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) &&
                !sf::Keyboard::isKeyPressed(sf::Keyboard::LAlt);
    }

    inline bool CTRL_ALT()
    {
        return   sf::Keyboard::isKeyPressed(sf::Keyboard::LControl) &&
                !sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) &&
                 sf::Keyboard::isKeyPressed(sf::Keyboard::LAlt);
    }

    inline bool SHIFT_ALT()
    {
        return  !sf::Keyboard::isKeyPressed(sf::Keyboard::LControl) &&
                 sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) &&
                 sf::Keyboard::isKeyPressed(sf::Keyboard::LAlt);
    }
}

#endif // KEYBOARDUTIL_H_INCLUDED
