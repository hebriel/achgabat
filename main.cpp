#include <achgabat/Core.hpp>
#include <achgabat/Application.hpp>
#include <achgabat/GameState.hpp>
#include <achgabat/SpriteEntity.hpp>
#include <achgabat/SpriteSheetEntity.hpp>
#include <achgabat/AutoSpriteSheetEntity.hpp>
#include <achgabat/Vector2.hpp>

#include <cmath>

#include <iostream>

/**
 * @file main.cpp
 * @author Underdisk
 */

class Player : public ag::AutoSpriteSheetEntity /*!< Detailed description after the member */
{
public:
    Player(const sf::Texture& texture, unsigned int tilePerLine, unsigned int tilePerColumn) : ag::AutoSpriteSheetEntity(texture, tilePerLine, tilePerColumn)
    {   }
    Player() : movementVector{1, 1}
    {
        speed = 320;
        //line = 5;
        //cumulus = 0;
        //column = 0;
        setOrigin(16, 32);
        setPosition(150, 150);
        scale = 6;
        setScale(scale, scale);
        isShooting = false;
    }

    void update(const sf::Time& dt) override
    {
        updateAnimator(dt);
        if(isEndOfLoop())
        {
            isShooting = false;
        }


        if((sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::S)
                || sf::Keyboard::isKeyPressed(sf::Keyboard::Q) || sf::Keyboard::isKeyPressed(sf::Keyboard::Z)) && !isShooting)
        {

            setLine(7);

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            {
                setScale(scale, scale);
                move(dt.asSeconds()*speed, 0);
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
            {
                move(0, dt.asSeconds()*speed);
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
            {
                setScale(-scale, scale);
                move(-dt.asSeconds()*speed, 0);
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
            {
               move(0, -dt.asSeconds()*speed);
               //move(movementVector * speed * dt.asSeconds());
            }
        }
        else if (!isShooting)
        {
            setLine(5);
        }
    }

    void handleEvents(const sf::Event& e)
    {
        if(e.type == sf::Event::KeyPressed)
        {
            if(e.key.code == sf::Keyboard::Space)
            {
                if(!isShooting)
                {
                    isShooting = true;
                    resetLoop();
                    setLine(8);
                }
            }
        }
    }

    float speed;
    int scale;
    bool isShooting;
    ag::Vector2f movementVector;

};

class State : public ag::GameState
{
public:
    State(ag::Application* app)
        : ag::GameState(app)
    {
        m_texture.loadFromFile("ranger.png");
        m_player.setTexture(m_texture);
        m_player.updateTexture(m_texture, 10, 10);
        //m_player.setActiveTile(9, 4);

        m_player.setFrequency(12.f);
        m_player.setLine(7);

    }

    bool init() override
    {
        return true;
    }

    void onPause() override
    {
        std::cout << "Game Paused" << std::endl;
    }

    void onResume() override
    {
        std::cout << "Game Resumed" << std::endl;
    }

    void handleEvents(const sf::Event& e) override
    {
        if(e.type == sf::Event::LostFocus)
        {
            pause(); //coming from parent
        }
        else if(e.type == sf::Event::GainedFocus)
        {
            resume(); //coming from parent
        }
        else if(e.type == sf::Event::Resized)
        {

        }

        m_player.handleEvents(e);
    }

    void update(sf::Time& dt) override
    {
        m_player.update(dt);
    }

    void render(sf::Time& dt) override
    {
        application->window->clear(sf::Color::White);
        application->window->draw(m_player);
    }

    void cleanup()
    {

    }

    sf::Texture m_texture;
    Player m_player;
};

class Game : public ag::Application
{
public:

    Game(const wchar_t* title, int width, int height, sf::Uint32 style = sf::Style::Default, sf::ContextSettings settings = sf::ContextSettings())
        : ag::Application(title, width, height, style, settings)
    {   }

    Game(const char* title, int width, int height, sf::Uint32 style = sf::Style::Default, sf::ContextSettings settings = sf::ContextSettings())
        : ag::Application(title, width, height, style, settings)
    {   }

    bool init() override
    {
        return true;
    }

    void cleanup() override
    {

    }
};

int main()
{

    Game* game = new Game("Achgabat", 800, 600);

    int exitStatus = ag::NoErrorStatus;

    State* state = new State(game);
    game->pushState(state);

    game->window->setFramerateLimit(144);

    exitStatus = game->run();

    delete game;

    return exitStatus;
}
