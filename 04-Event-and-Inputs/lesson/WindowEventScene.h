////////////////////////////////////////////////////////////
// Nero Game Engine - SFML Tutorials
// Copyright (c) 2021 Sanou A. K. Landry
////////////////////////////////////////////////////////////
#ifndef WINDOWEVENTSCENE_H_INCLUDED
#define WINDOWEVENTSCENE_H_INCLUDED
///////////////////////////HEADERS//////////////////////////
//Nero Games
#include "Scene.h"
#include <Nero/utility/Utility.h>
//SFML
#include <SFML/Graphics.hpp>
////////////////////////////////////////////////////////////
class WindowEventScene : public ng::Scene
{
     public:
        typedef std::unique_ptr<WindowEventScene> Ptr;

        WindowEventScene()
        {
            setSceneName("Window Event Scene v0.1");
        }

        void handleEvent(const sf::Event& event)
        {
            //Closed Event
            if(event.type == sf::Event::Closed)
            {
                /*nero_log("closing window");
                //getRenderWindow().close();*/

                //callback
                onWindowClosed();
            }

            //Resized Event
            else if(event.type == sf::Event::Resized)
            {
                /*unsigned int new_width  = event.size.width;
                unsigned int new_height = event.size.height;

                nero_log(_se(new_width));
                nero_log(_se(new_height));*/

                //callback
                onWindowResized(sf::Vector2u(event.size.width, event.size.height));
            }

            //GainedFocus Event
            else  if(event.type == sf::Event::GainedFocus)
            {
                /*nero_log("window just gained focus");*/

                //callback
                onWindowFocusChanged(true);
            }

            //LostFocus Event
            else if(event.type == sf::Event::LostFocus)
            {
                /*nero_log("window just lost focus");*/

                //callback
                onWindowFocusChanged(false);
            }
        }

     private: //Window Events callback

        void onWindowClosed()
        {
            //do something
                //save the game
                //show a pop-up to the user asking if he/she really want to close
                //Etc.

                //close the window
                getRenderWindow().close();
        }

        void onWindowResized(const sf::Vector2u& size)
        {
            //do something
                //update the scene resolution
                //update your OpenGL viewport
                //Etc.

            nero_log(_se(size.x));
            nero_log(_se(size.y));
        }

        void onWindowFocusChanged(const bool& gainedFocus)
        {
            //do something
                //pause the game if gainedFocus = false
                //resume the game if gainedFocus = true
                //Etc.

            nero_log(_se(gainedFocus));
        }
};

#endif // WINDOWEVENTSCENE_H_INCLUDED
