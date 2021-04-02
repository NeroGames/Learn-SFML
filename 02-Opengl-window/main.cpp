////////////////////////////////////////////////////////////
// Nero Game Engine - SFML Tutorials
// Copyright (c) 2021 Sanou A. K. Landry
////////////////////////////////////////////////////////////
//Glew
#include <GL/glew.h>
//SFML
#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>
//
#include <iostream>

// Forward Declaration : Utility functions
struct          TriangleState{unsigned int VBO, VAO, EBO;};
sf::Vector2f    pixelToNDC(const sf::Vector2f& vertex, sf::Vector2u resolution);
int             createShaderProgram();
void            createTriangle(TriangleState& triangle, sf::Vector2u resolution, const sf::Vector2f& vertex1, const sf::Vector2f& vertex2, const sf::Vector2f& vertex3);
void            drawTriangle(TriangleState& triangle, int shaderProgram);
void            destroyTriangle(TriangleState& triangle);

int main()
{
    //Create OpenGL Window
        //window parameters (OpenGL 3.3)
    sf::Vector2u    window_resolution(1080, 720);
    std::string     window_title    = "OpenGL Window";
    sf::ContextSettings contextSettings;
        contextSettings.depthBits           = 24;
        contextSettings.stencilBits         = 8;
        contextSettings.antialiasingLevel   = 4;
        contextSettings.majorVersion        = 3;
        contextSettings.minorVersion        = 3;

        //create the window
    sf::Window openGLWindow(sf::VideoMode(window_resolution.x, window_resolution.y), window_title, sf::Style::Default, contextSettings);
        //setup the window
    openGLWindow.setVerticalSyncEnabled(true);
    openGLWindow.setActive(true);

    //Initialize GLEW (OpenGL Extension Wrangler Library) and check if OpenGL is available
    bool openGlAvailable = true;
    glewExperimental = GL_TRUE;
    if (glewInit() != GLEW_OK)
    {
        openGlAvailable = false;
    }
    //If OpenGL is not available let's stop everything and exit the program.
    if(!openGlAvailable) return 0;


    //Initialize your game here, let's create a simple triangle
        //create shader program
    int shaderProgram = createShaderProgram();
        //build a triangle
    TriangleState triangle; //a structure to hold the OpenGL state of the triangle
    createTriangle(triangle, window_resolution, sf::Vector2f(540.f, 100.f), sf::Vector2f(340.f, 360.f), sf::Vector2f(740.f, 360.f));


    //Game loop
    bool gameRunning = true;
    while(gameRunning)
    {
        // handle events
        sf::Event event;
        while(openGLWindow.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
            {
                // end the program
                gameRunning = false;
            }
            else if (event.type == sf::Event::Resized)
            {
                // adjust the viewport when the window is resized
                glViewport(0, 0, event.size.width, event.size.height);
            }
        }


        //update your game here
            //we have noting to update, so it's empty


        // clear the buffers
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

            drawTriangle(triangle, shaderProgram);

        // end the current frame (internally swaps the front and back buffers)
        openGLWindow.display();
    }

    //Destroy triangle state
    destroyTriangle(triangle);
    //Destroy shader Program
    glDeleteProgram(shaderProgram);

    return 0;
}

int createShaderProgram()
{
    const char *vertexShaderSource = "#version 330 core\n"
    "layout (location = 0) in vec3 aPos;\n"
    "void main()\n"
    "{\n"
    "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
    "}\0";

    const char *fragmentShaderSource = "#version 330 core\n"
    "out vec4 FragColor;\n"
    "void main()\n"
    "{\n"
    "   FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
    "}\n\0";

    // load resources, initialize the OpenGL states, ...
     // build and compile our shader program
    // ------------------------------------
    // vertex shader
    int vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader);
    // check for shader compile errors
    int success;
    char infoLog[512];
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
    }
    // fragment shader
    int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
    glCompileShader(fragmentShader);
    // check for shader compile errors
    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
    }
    // link shaders
    int shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);
    // check for linking errors
    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
    }
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

    return shaderProgram;
}

sf::Vector2f pixelToNDC(const sf::Vector2f& vertex, sf::Vector2u resolution)
{
    return sf::Vector2f(-1.f + vertex.x/resolution.x * 2.f,
                         1.f - vertex.y/resolution.y * 2.f);
}

void createTriangle(TriangleState& triangle, sf::Vector2u resolution, const sf::Vector2f& vertex1, const sf::Vector2f& vertex2, const sf::Vector2f& vertex3)
{
    // set up vertex data (and buffer(s)) and configure vertex attributes
    // ------------------------------------------------------------------
    float vertices[] =
    {
        pixelToNDC(vertex1, resolution).x, pixelToNDC(vertex1, resolution).y, 0.0f, // left
        pixelToNDC(vertex2, resolution).x, pixelToNDC(vertex2, resolution).y, 0.0f, // right
        pixelToNDC(vertex3, resolution).x, pixelToNDC(vertex3, resolution).y, 0.0f  // top
    };

    glGenVertexArrays(1, &triangle.VAO);
    glGenBuffers(1, &triangle.VBO);
    // bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
    glBindVertexArray(triangle.VAO);

    glBindBuffer(GL_ARRAY_BUFFER, triangle.VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    // note that this is allowed, the call to glVertexAttribPointer registered VBO as the vertex attribute's bound vertex buffer object so afterwards we can safely unbind
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    // You can unbind the VAO afterwards so other VAO calls won't accidentally modify this VAO, but this rarely happens. Modifying other
    // VAOs requires a call to glBindVertexArray anyways so we generally don't unbind VAOs (nor VBOs) when it's not directly necessary.
    glBindVertexArray(0);
}

void drawTriangle(TriangleState& triangle, int shaderProgram)
{
    glUseProgram(shaderProgram);
    glBindVertexArray(triangle.VAO);
    glDrawArrays(GL_TRIANGLES, 0, 3);
}

void destroyTriangle(TriangleState& triangle)
{
    glDeleteVertexArrays(1, &triangle.VAO);
    glDeleteBuffers(1, &triangle.VBO);
    glDeleteBuffers(1, &triangle.EBO);
}
