////////////////////////////////////////////////////////////
// Nero Game Engine - SFML Tutorials
// Copyright (c) 2021 Sanou A. K. Landry
////////////////////////////////////////////////////////////
#ifndef KEYBOARDEVENTSCENE_H_INCLUDED
#define KEYBOARDEVENTSCENE_H_INCLUDED
///////////////////////////HEADERS//////////////////////////
//Nero Games
#include "Scene.h"
//SFML
#include <SFML/Graphics.hpp>
////////////////////////////////////////////////////////////
class KeyboardEventScene : public ng::Scene
{
    public:
        typedef std::unique_ptr<KeyboardEventScene> Ptr;

        struct ModifierKey
        {
            bool alt        = false;
            bool control    = false;
            bool shift      = false;
            bool system     = false;
        };

        KeyboardEventScene()
        {
            setSceneName("Keyboard Event Scene v0.1");
        }


        void handleEvent(const sf::Event& event)
        {
            //close the window
            ng::Scene::handleEvent(event);

            if(event.type == sf::Event::KeyPressed)
            {
                /*sf::Keyboard::Key key   =  event.key.code; //key name : A, B, SpaceBar etc.
                bool alt                =   event.key.alt;
                bool control            =   event.key.control;
                bool shift              =   event.key.shift;
                bool system             =   event.key.system;


                if(key == sf::Keyboard::A)
                {
                    nero_log("Pressing on A");
                }

                if(key == sf::Keyboard::A && control)
                {
                    nero_log("Pressing on CTRL + A");
                }*/


                //callback
                ModifierKey modifier;
                modifier.alt        = event.key.alt;
                modifier.control    = event.key.control;
                modifier.shift      = event.key.shift;
                modifier.system     = event.key.system;

                onKeyboardButton(event.key.code, true, modifier);
            }

            else if(event.type == sf::Event::KeyReleased)
            {
                /*sf::Keyboard::Key key   =  event.key.code; //key name : A, B, SpaceBar etc.
                bool alt                =   event.key.alt;
                bool control            =   event.key.control;
                bool shift              =   event.key.shift;
                bool system             =   event.key.system;


                if(key == sf::Keyboard::A)
                {
                    nero_log("Releasing A");
                }

                if(key == sf::Keyboard::A && control)
                {
                    nero_log("Releasing CTRL + A");
                }*/

                //callback
                ModifierKey modifier;
                modifier.alt        = event.key.alt;
                modifier.control    = event.key.control;
                modifier.shift      = event.key.shift;
                modifier.system     = event.key.system;

                onKeyboardButton(event.key.code, false, modifier);
            }

            if (event.type == sf::Event::TextEntered)
            {
                /*sf::Uint32 unicode = event.text.unicode;

                //Make sure the unicode character is valid (value should be below 128)
                if (event.text.unicode < 128)
                {
                    std::string text = std::string(1, (static_cast<char>(event.text.unicode)));

                    nero_log(text);
                }*/

                //callback
                if (event.text.unicode < 128)
                {
                    onTextEntered(std::string(1, (static_cast<char>(event.text.unicode))));
                }
            }
        }

        private: //Keyboard Events callback

            void onKeyboardButton(const sf::Keyboard::Key& key, const bool& isPressed, const ModifierKey& modifier)
            {
                //do something
                    //key : name of the key (A, B, SpaceBar etc.)
                    //isPressed : is the keyPressed or released ?
                    //modifier : the state of the modifier keys (CTRL, ATL, SHIFT, SYSTEM)
            }

            void onTextEntered(const std::string& c)
            {
                //do something
                    // hero_name += c;
            }
};

#endif // KEYBOARDEVENTSCENE_H_INCLUDED
