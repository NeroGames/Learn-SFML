////////////////////////////////////////////////////////////
// Nero Game Engine - SFML Tutorials
// Copyright (c) 2021 Sanou A. K. Landry
////////////////////////////////////////////////////////////
///////////////////////////HEADERS//////////////////////////
//SFML
#include <SFML/Window/Event.hpp>
//Nero Games
#include "Engine.h"
////////////////////////////////////////////////////////////
namespace ng
{
    Engine::Engine(const unsigned int& windowWidth, const unsigned int& windowHeight, const float& frameRate):
         m_WindowResolution(windowWidth, windowHeight)
        ,m_FrameRate(sf::seconds(1.f/frameRate))
        ,m_RenderWindow(sf::VideoMode(windowWidth, windowHeight), "Simple Engine")
    {
        //constructor
    }

    Engine::~Engine()
    {
        //destructor
    }

    void Engine::setScene(Scene::Ptr scene)
    {
        m_Scene = std::move(scene);
        m_RenderWindow.setTitle(m_Scene->m_SceneName);
        m_Scene->m_Resolution   = m_WindowResolution;
        m_Scene->m_RenderWindow = &m_RenderWindow;
    }

    void Engine::run()
    {
        //Initialize game
        init();

        //Variable to store the time that passes
        sf::Time timePassed = sf::Time::Zero;
        //Create a clock, the clock starts automatically
        sf::Clock clock;
        //Entering the game loop
        while(m_RenderWindow.isOpen())
        {
            //Retrieve the clock time and reset the clock at the same time
            sf::Time clockTime = clock.restart();
            //Accumulate the time passing in our variable (this happens at each cycle of the while loop)
            timePassed += clockTime;

            //When the time passing is over our Fixed Time only Capture Inputs and Update the Game
            while(timePassed > m_FrameRate)
            {
                //Remove (0.0166) seconds from the passing time
                //Only the overflow will remain for the next frame
                timePassed -= m_FrameRate;

                //capture the user inputs using SFML Events
                handleEvent();
                //update the game at the fixed time frame of (0.0166 second)
                update(m_FrameRate);
            }

            //Render the game
            //We do not render the game at 60 FPS, only the update happens at 60 FPS
            render();
        }

        destroy();
    }

    void Engine::init()
    {
        if(m_Scene) m_Scene->init();
    }

    void Engine::handleEvent()
    {
        sf::Event event;
        while(m_RenderWindow.pollEvent(event))
        {
            if(!m_Scene && event.type == sf::Event::Closed)
            {
                // end the program
                m_RenderWindow.close();
            }

            if(m_Scene) m_Scene->handleEvent(event);
        }
    }

    void Engine::update(const sf::Time& timeStep)
    {
        if(m_Scene) m_Scene->update(m_FrameRate);
    }

    void Engine::render()
    {
        if(m_Scene)
        {
            m_Scene->clear();

            m_Scene->render();

            m_RenderWindow.display();
        }
    }

    void Engine::destroy()
    {
        if(m_Scene) m_Scene->destroy();
    }
}

