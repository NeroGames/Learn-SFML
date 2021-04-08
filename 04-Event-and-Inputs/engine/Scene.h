////////////////////////////////////////////////////////////
// Nero Game Engine - SFML Tutorials
// Copyright (c) 2021 Sanou A. K. Landry
////////////////////////////////////////////////////////////
#ifndef SCENE_H
#define SCENE_H
///////////////////////////HEADERS//////////////////////////
//SFML
#include <SFML/Graphics/RenderWindow.hpp>
//CPP
#include <memory>
////////////////////////////////////////////////////////////
namespace ng
{
    class Scene
    {
        public:
            typedef std::unique_ptr<Scene> Ptr;

        public:
                                        Scene();
            virtual                    ~Scene();

        public:
            virtual void                init();
            virtual void                handleEvent(const sf::Event& event);
            virtual void                update(const sf::Time& timeStep);
            virtual void                clear();
            virtual void                render();
            virtual void                destroy();

        public:
                //getter
            std::string                 getSceneName() const;
            sf::Vector2f                getSceneResolution() const;
            sf::RenderWindow&           getRenderWindow() const;
                //setter
            void                        setSceneName(const std::string& name);

        private:
            friend class                Engine;
            std::string                 m_SceneName;
            sf::Vector2f                m_Resolution;
            sf::RenderWindow*           m_RenderWindow;
    };
}

#endif // SCENE_H
