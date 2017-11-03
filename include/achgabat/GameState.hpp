#ifndef AG_GAMESTATE_HPP
#define AG_GAMESTATE_HPP

#include <SFML/Graphics.hpp>
#include "Pausable.hpp"

/**
 * @file GameState.hpp
 * @author Underdisk
 */

namespace ag {

class Application;

class GameState : public ag::Pausable
{
    friend Application;
    public:
        GameState(ag::Application* app);
        virtual ~GameState();


        bool isRunning() const {return m_isRunning;}
        void stop(){m_isRunning = false;}
        void reset();

    protected:

        Application* application;

        virtual bool init() = 0;
        virtual void update(sf::Time& dt) = 0;
        virtual void render(sf::Time& dt) = 0;
        virtual void handleEvents(const sf::Event& e) = 0;
        virtual void cleanup() = 0;


    private:

        void run();

        sf::Clock m_clock;
        sf::Time m_deltaTime;
        bool m_isRunning;
};

} // namespace ag

#endif // AG_GAMESTATE_HPP
