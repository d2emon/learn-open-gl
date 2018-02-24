#include "display.h"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>
#include <string>
#include <iostream>

Display::Display(int width, int height, const std::string& title)
{
    error = 0;

    sf::ContextSettings settings;
    // settings.

    // Create the main window
    m_window = new sf::RenderWindow(sf::VideoMode(width, height), title, sf::Style::Default, settings);
    m_window->setVerticalSyncEnabled(true);
    m_window->setActive(true);

    // Load a sprite to display
    if (!texture.loadFromFile("res/cb.bmp"))
        error = EXIT_FAILURE;
    else
        sprite = sf::Sprite(texture);
}

bool Display::isOpen()
{
    return m_window->isOpen();
}

void Display::Clear(float r, float g, float b, float a)
{
    // Clear screen
    glClearColor(r, g, b, a);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Display::ProcessEvents()
{
    // Process events
    sf::Event event;
    while (m_window->pollEvent(event))
    {
        // Close window : exit
        if (event.type == sf::Event::Closed)
            m_window->close();
    }
}

void Display::Update()
{
    // Draw the sprite
    m_window->draw(sprite);

    // Update the window
    m_window->display();
}

Display::~Display()
{
    m_window->setActive(false);
}
