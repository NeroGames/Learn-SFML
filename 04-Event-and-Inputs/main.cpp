////////////////////////////////////////////////////////////
// Nero Game Engine - SFML Tutorials
// Copyright (c) 2021 Sanou A. K. Landry
////////////////////////////////////////////////////////////
///////////////////////////HEADERS//////////////////////////
#include "Engine.h"
#include "lesson/WindowEventScene.h"
#include "lesson/KeyboardEventScene.h"
////////////////////////////////////////////////////////////
int main()
{
    //create new Engine instance
    ng::Engine engine(1080, 720, 60);
        //provide Scene to Engine
        engine.setScene(WindowEventScene::Ptr(new WindowEventScene()));
    //run the Engine
    engine.run();

    return 0;
}
