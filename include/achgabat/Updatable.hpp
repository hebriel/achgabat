#ifndef AG_UPDATABLE_HPP
#define AG_UPDATABLE_HPP

#include <SFML/Graphics.hpp>

/**
 * @file Updatable.hpp
 * @author Underdisk
 */

namespace ag {

class Updatable
{
    public:
        Updatable();
        virtual ~Updatable();
        virtual void update();
        virtual void update(const sf::Time& dt);
        virtual void handleEvents(const sf::Event& e);

    protected:

    private:
};

} // namespace ag

#endif // AG_UPDATABLE_HPP
