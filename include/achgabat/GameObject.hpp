#ifndef AG_GAMEOBJECT_HPP
#define AG_GAMEOBJECT_HPP

#include <SFML/Graphics.hpp>

/**
 * @file GameObject.hpp
 * @author Underdisk
 */

namespace ag {

class GameObject : public sf::Drawable, sf::Transformable
{
    public:
        GameObject();
    protected:

    private:
};

} // namespace ag

#endif // AG_GAMEOBJECT_HPP
