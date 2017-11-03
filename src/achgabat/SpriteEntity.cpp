#include "achgabat/SpriteEntity.hpp"

/**
 * @file SpriteEntity.cpp
 * @author Underdisk
 */

namespace ag {

SpriteEntity::SpriteEntity()
    : sf::Sprite()
{   }

SpriteEntity::SpriteEntity(const sf::Texture& texture)
    : sf::Sprite(texture)
{   }

SpriteEntity::SpriteEntity(const sf::Texture& texture, const sf::IntRect& rectangle)
    : sf::Sprite(texture, rectangle)
{   }



} // namespace ag
