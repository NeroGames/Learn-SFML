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
#include "SFML/Graphics.hpp"
////////////////////////////////////////////////////////////
class KeyboardEventScene : public ng::Scene
{
    public:
        struct ModifierKey
        {
            bool alt        = false;
            bool control    = false;
            bool shift      = false;
            bool system    = false;
        };

    public:
        typedef std::unique_ptr<KeyboardEventScene> Ptr;

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
                sf::Keyboard::Key key   =  event.key.code;
                bool alt            =   event.key.alt;
                bool control        =   event.key.control;
                bool shift          =   event.key.shift;
                bool  system        =   event.key.system;


                //callback
                ModifierKey modifier;
                modifier.alt = event.key.alt;
                modifier.control = event.key.control;
                modifier.shift = event.key.shift;
                modifier.system = event.key.system;

                onKeyboardButton(event.key.code, true, modifier);
            }

            else if(event.type == sf::Event::KeyReleased)
            {
                sf::Keyboard::Key key   =  event.key.code;
                bool alt            =   event.key.alt;
                bool control        =   event.key.control;
                bool shift          =   event.key.shift;
                bool  system        =   event.key.system;

                //callback
                ModifierKey modifier;
                modifier.alt = event.key.alt;
                modifier.control = event.key.control;
                modifier.shift = event.key.shift;
                modifier.system = event.key.system;

                onKeyboardButton(event.key.code, false, modifier);
            }

            if (event.type == sf::Event::TextEntered)
            {
                sf::Uint32 unicode = event.text.unicode;

                if (event.text.unicode < 128)
                {
                    std::string text = std::string(1, (static_cast<char>(event.text.unicode)));
                    nero_log(text);
                }

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

            }

            void onTextEntered(const std::string& c)
            {

            }
};



#endif // KEYBOARDEVENTSCENE_H_INCLUDED
