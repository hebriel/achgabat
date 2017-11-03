#include "achgabat/SpriteSheetEntity.hpp"
#include <iostream>

/**
 * @file SpriteSheetEntity.cpp
 * @author Underdisk
 */

namespace ag {

SpriteSheetEntity::SpriteSheetEntity()
{
    m_rectangle.top = 0;
    m_rectangle.left = 0;
}

SpriteSheetEntity::SpriteSheetEntity(const sf::Texture& texture, unsigned int tilePerLine, unsigned int tilePerColumn)
    : ag::SpriteEntity(texture)
{
    setTilePerLine(tilePerLine);
    setTilePerColumn(tilePerColumn);

    setTexture(texture);
    m_rectangle.width = getTexture()->getSize().x / m_tilePerLine;
    m_rectangle.height = getTexture()->getSize().y / m_tilePerColumn;

    m_rectangle.top = 0;
    m_rectangle.left = 0;
    setTextureRect(m_rectangle);
}

void SpriteSheetEntity::updateTexture(const sf::Texture& texture, unsigned int tilePerLine, unsigned int tilePerColumn)
{
    setTilePerLine(tilePerLine);
    setTilePerColumn(tilePerColumn);

    setTexture(texture);
    m_rectangle.width = getTexture()->getSize().x / m_tilePerLine;
    m_rectangle.height = getTexture()->getSize().y / m_tilePerColumn;

    setTextureRect(m_rectangle);

}

void SpriteSheetEntity::setActiveTile(unsigned int column, unsigned int line)
{
    m_rectangle.left = m_rectangle.width * column;
    m_rectangle.top = m_rectangle.height * line;
    setTextureRect(m_rectangle);
}

SpriteSheetEntity::~SpriteSheetEntity()
{

}

void SpriteSheetEntity::setTilePerLine(unsigned int tilePerLine)
{
   m_tilePerLine = tilePerLine;
}

void SpriteSheetEntity::setTilePerColumn(unsigned int tilePerColumn)
{
    m_tilePerColumn = tilePerColumn;
}


} // namespace ag
