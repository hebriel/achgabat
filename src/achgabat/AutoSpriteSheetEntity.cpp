#include "achgabat/AutoSpriteSheetEntity.hpp"

/**
 * @file AutoSpriteSheetEntity.cpp
 * @author Underdisk
 */

namespace ag {

AutoSpriteSheetEntity::AutoSpriteSheetEntity()
{
    //ctor
}

AutoSpriteSheetEntity::AutoSpriteSheetEntity(const sf::Texture& texture, unsigned int tilePerLine, unsigned int tilePerColumn)
    : SpriteSheetEntity(texture, tilePerLine, tilePerColumn), m_cumulus(0.f), m_column(0), m_line(0), m_endOfLoop(false)
{   }

void AutoSpriteSheetEntity::setFrequency(float frequency)
{
    m_period = 1.f/frequency;
}

void AutoSpriteSheetEntity::updateAnimator(const sf::Time& dt)
{
    m_endOfLoop = false;
    m_cumulus += dt.asSeconds();
    if(m_cumulus >= m_period)
    {
        m_cumulus = 0;
        ++m_column;
        if(m_column >= getTilePerColumn())
        {
            m_column = 0;
            m_endOfLoop = true;
        }
        setActiveTile(m_column, m_line);
    }
}

void AutoSpriteSheetEntity::resetLoop()
{
    m_column = 0;
}

AutoSpriteSheetEntity::~AutoSpriteSheetEntity()
{
    //dtor
}

} // namespace ag
