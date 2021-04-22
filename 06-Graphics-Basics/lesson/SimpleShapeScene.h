////////////////////////////////////////////////////////////
// Nero Game Engine - SFML Tutorials
// Copyright (c) 2021 Sanou A. K. Landry
////////////////////////////////////////////////////////////
#ifndef SIMPLESHAPESCENE_H_INCLUDED
#define SIMPLESHAPESCENE_H_INCLUDED
///////////////////////////HEADERS//////////////////////////
//Nero Games
#include "Scene.h"
//SFML
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/ConvexShape.hpp>
////////////////////////////////////////////////////////////
class SimpleShapeScene : public ng::Scene
{
    private:
        sf::CircleShape         mCircle;
        sf::CircleShape         mRegularPolygon;
        sf::RectangleShape      mRectangle;
        sf::RectangleShape      mLine;
        sf::ConvexShape         mConvexPolygon;

    public:
        typedef std::unique_ptr<SimpleShapeScene> Ptr;

        SimpleShapeScene()
        {
            setSceneName("Simple Shapes Scene v0.1");
        }

        void init()
        {
            //circle
            mCircle.setRadius(50.f);
            mCircle.setOrigin(50.f, 50.f);
            mCircle.setFillColor(sf::Color::Yellow);
            mCircle.setPosition(100.f, getSceneResolution().y/2.f);
            //mCircle.setOutlineThickness (4.f);
            //mCircle.setOutlineColor(sf::Color::Red);

            //pentagon (5 sides)
            mRegularPolygon.setPointCount(5); //5 points (the number of points equal the number of sides/faces)
            mRegularPolygon.setRadius(50.f);
            mRegularPolygon.setOrigin(50.f, 50.f);
            mRegularPolygon.setFillColor(sf::Color::Yellow);
            mRegularPolygon.setPosition(300.f, getSceneResolution().y/2.f);
            //mRegularPolygon.setOutlineThickness (4.f);
            //mRegularPolygon.setOutlineColor(sf::Color::Red);

            //rectangle
            mRectangle.setSize(sf::Vector2f(150.f, 100.f));
            mRectangle.setOrigin(75.f, 50.f);
            mRectangle.setFillColor(sf::Color::Yellow);
            mRectangle.setPosition(500.f, getSceneResolution().y/2.f);
           //mRectangle.setOutlineThickness (4.f);
            //mRectangle.setOutlineColor(sf::Color::Red);

            //line
            mLine.setSize(sf::Vector2f(150.f, 2.f));
            mLine.setOrigin(75.f, 1.f);
            mLine.setFillColor(sf::Color::Yellow);
            mLine.setPosition(700.f, getSceneResolution().y/2.f);
            //mLine.setOutlineThickness (4.f);
            //mLine.setOutlineColor(sf::Color::Red);

            //convex polygon
            mConvexPolygon.setPointCount(7);
            mConvexPolygon.setOrigin(100.f, 50.f);
            mConvexPolygon.setPoint(0, sf::Vector2f(0.f, 0.f));
            mConvexPolygon.setPoint(1, sf::Vector2f(100.f, 0.f));
            mConvexPolygon.setPoint(2, sf::Vector2f(150.f, 50.f));
            mConvexPolygon.setPoint(3, sf::Vector2f(200.f, 60.f));
            mConvexPolygon.setPoint(4, sf::Vector2f(200.f, 100.f));
            mConvexPolygon.setPoint(5, sf::Vector2f(-50.f, 100.f));
            mConvexPolygon.setPoint(6, sf::Vector2f(-50.f, 50.f));
            mConvexPolygon.setFillColor(sf::Color::Yellow);
            mConvexPolygon.setPosition(950.f, getSceneResolution().y/2.f);
            //mConvexPolygon.setOutlineThickness (4.f);
            //mConvexPolygon.setOutlineColor(sf::Color::Red);
        }

        void render()
        {
            getRenderWindow().draw(mCircle);
            getRenderWindow().draw(mRegularPolygon);
            getRenderWindow().draw(mRectangle);
            getRenderWindow().draw(mLine);
            getRenderWindow().draw(mConvexPolygon);
        }
};

#endif // SIMPLESHAPESCENE_H_INCLUDED
