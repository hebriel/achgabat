#ifndef AG_SPRITEENTITY_HPP
#define AG_SPRITEENTITY_HPP

#include <SFML/Graphics.hpp>
#include "Updatable.hpp"

/**
 * @file SpriteEntity.hpp
 * @author Underdisk
 */

namespace ag {

class SpriteEntity : public sf::Sprite, ag::Updatable
{
    public:
        SpriteEntity();

        SpriteEntity(const sf::Texture& texture);
        SpriteEntity(const sf::Texture& texture, const sf::IntRect& rectangle);

    protected:

    private:
};

} // namespace ag

#endif // AG_SPRITEENTITY_HPP
