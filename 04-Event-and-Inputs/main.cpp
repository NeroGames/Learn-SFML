////////////////////////////////////////////////////////////
// Nero Game Engine - SFML Tutorials
// Copyright (c) 2021 Sanou A. K. Landry
////////////////////////////////////////////////////////////
///////////////////////////HEADERS//////////////////////////
#include "Engine.h"
#include "lesson/WindowEventScene.h"
#include "lesson/KeyboardEventScene.h"
#include "lesson/MouseEventScene.h"
#include "lesson/JoystickEventScene.h"
////////////////////////////////////////////////////////////
int main()
{
    //create new Engine instance
    ng::Engine engine(1080, 720, 60);
        //provide Scene to Engine
        engine.setScene(JoystickEventScene::Ptr(new JoystickEventScene()));
    //run the Engine
    engine.run();

    return 0;
}
