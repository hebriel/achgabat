#include "achgabat/Application.hpp"
#include "achgabat/GameState.hpp"
#include <iostream>

/**
 * @file Application.cpp
 * @author Underdisk
 */


namespace ag {

Application::Application(const wchar_t* title, int width, int height, sf::Uint32 style, sf::ContextSettings settings)
    : window(new sf::RenderWindow(sf::VideoMode(width, height), title, style, settings))
{

}

Application::Application(const char* title, int width, int height, sf::Uint32 style, sf::ContextSettings settings)
    : window(new sf::RenderWindow(sf::VideoMode(width, height), title, style, settings))
{

}

int Application::run()
{
    if(!init())
    {
        return -1;
    }

    while(window->isOpen())
    {
        if(!m_states.empty())
        {
            m_states.top()->run();
            delete m_states.top();
            popState();
        }
        else
        {
            std::cout << "Error : No game state to load" << std::endl;
            return 1;
        }

    }

    cleanup();

    return ag::NoErrorStatus;
}

bool Application::init()
{
    return true;
}

void Application::cleanup()
{

}

void Application::pushState(GameState* state)
{
    m_states.push(state);
}

void Application::popState()
{
    m_states.pop();
}

void Application::replaceState(GameState* state)
{
    popState();
    pushState(state);
}



Application::~Application()
{
    delete window;
}

} // namespace ag
