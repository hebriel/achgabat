#include "achgabat/GameState.hpp"
#include "achgabat/Application.hpp"

/**
 * @file GameState.cpp
 * @author Underdisk
 */

namespace ag {

GameState::GameState(ag::Application* app)
    : application(app)
{
    m_isRunning = true;
}

GameState::~GameState()
{
    //dtor
}

bool GameState::init()
{
    return true;
}

void GameState::update(sf::Time& dt)
{

}

void GameState::render(sf::Time& dt)
{

}

void GameState::handleEvents(const sf::Event& e)
{

}

void GameState::cleanup()
{

}

void GameState::run()
{
    if(!init())
    {
        exit(-2);
    }

    while(isRunning() && application->window->isOpen())
    {
        sf::Event e;
        while(application->window->pollEvent(e))
        {
            handleEvents(e);
            if(e.type == sf::Event::Closed) application->window->close();
        }
        if(!isPaused()) update(m_deltaTime);
        render(m_deltaTime);
        m_deltaTime = m_clock.restart();

        application->window->display();
    }

    cleanup();
}
void GameState::reset()
{

}





} // namespace ag
