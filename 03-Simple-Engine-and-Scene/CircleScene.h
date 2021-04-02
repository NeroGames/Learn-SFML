#ifndef CIRCLESCENE_H_INCLUDED
#define CIRCLESCENE_H_INCLUDED

#include "Scene.h"
#include "SFML/Graphics.hpp"

class CircleScene : public ng::Scene
{
    public:
        typedef std::unique_ptr<CircleScene> Ptr;

        CircleScene()
        {
            setSceneName("Circle Scene v0.1");
        }

    public:
        void init()
        {
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
        }

        void update(const sf::Time& timeStep)
        {
            mCircle.setPosition(mCirclePosition);
        }

        void clear()
        {
            getRenderWindow().clear(sf::Color::Black);
        }

        void render()
        {
            getRenderWindow().draw(mCircle);
        }

        void destroy()
        {
            //nothing
        }

    private:
        sf::CircleShape mCircle;
        sf::Vector2f    mCirclePosition;
};

#endif // CIRCLESCENE_H_INCLUDED
