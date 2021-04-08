////////////////////////////////////////////////////////////
// Nero Game Engine - SFML Tutorials
// Copyright (c) 2021 Sanou A. K. Landry
////////////////////////////////////////////////////////////
///////////////////////////HEADERS//////////////////////////
//SFML
#include <SFML/Window/Event.hpp>
//Nero Games
#include "Scene.h"
////////////////////////////////////////////////////////////
namespace ng
{
    Scene::Scene():
         m_SceneName("Empty Scene")
        ,m_RenderWindow(nullptr)
    {
        //ctor
    }

    Scene::~Scene()
    {
        //dtor
    }

    void Scene::init()
    {

    }

    void Scene::handleEvent(const sf::Event& event)
    {
        if(event.type == sf::Event::Closed)
        {
            m_RenderWindow->close();
        }
    }

    void Scene::update(const sf::Time& timeStep)
    {

    }

    void Scene::render()
    {

    }

    void Scene::destroy()
    {
        m_RenderWindow = nullptr;
    }

    void Scene::clear()
    {
        m_RenderWindow->clear();
    }

    std::string Scene::getSceneName() const
    {
        return m_SceneName;
    }

    void Scene::setSceneName(const std::string& name)
    {
        m_SceneName = name;
    }

    sf::Vector2f Scene::getSceneResolution() const
    {
        return m_Resolution;
    }

    sf::RenderWindow& Scene::getRenderWindow() const
    {
        return *m_RenderWindow;
    }
}




