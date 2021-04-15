////////////////////////////////////////////////////////////
// Nero Game Engine - SFML Tutorials
// Copyright (c) 2021 Sanou A. K. Landry
////////////////////////////////////////////////////////////
///////////////////////////HEADERS//////////////////////////
#include "engine/Engine.h"
#include "lesson/CircleScene.h"
////////////////////////////////////////////////////////////
int main()
{
    //create new Engine instance
    ng::Engine engine(1080, 720, 60);
        //provide Scene to Engine
        engine.setScene(CircleScene::Ptr(new CircleScene()));
    //run the Engine
    engine.run();

    return 0;
}
