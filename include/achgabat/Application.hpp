#ifndef AG_APPLICATION_HPP
#define AG_APPLICATION_HPP

#include <SFML/Graphics.hpp>
#include "Core.hpp"
#include <stack>

/**
 * @file Application.hpp
 * @author Underdisk
 */


namespace ag {

class GameState;

class Application
{
    public:
        Application(const wchar_t* title, int width, int height, sf::Uint32 style = sf::Style::Default, sf::ContextSettings settings = sf::ContextSettings());
        Application(const char* title, int width, int height, sf::Uint32 style = sf::Style::Default, sf::ContextSettings settings = sf::ContextSettings());
        virtual ~Application();

        int run();
        void pushState(GameState* state);
        void popState();
        void replaceState(GameState* state);


        sf::RenderWindow* window;

    protected:

        virtual bool init() = 0;
        virtual void cleanup() = 0;

    private:

        std::stack<GameState*> m_states;

};

} // namespace ag

#endif // AG_APPLICATION_HPP
