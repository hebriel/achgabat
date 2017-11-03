#ifndef AG_SPRITESHEETENTITY_HPP
#define AG_SPRITESHEETENTITY_HPP

#include "SpriteEntity.hpp"
#include "Pausable.hpp"

/**
 * @file SpriteSheetEntity.hpp
 * @author Underdisk
 */

namespace ag {

class SpriteSheetEntity : public ag::SpriteEntity
{
    public:
        SpriteSheetEntity();
        SpriteSheetEntity(const sf::Texture& texture, unsigned int tilePerLine, unsigned int tilePerColumn);
        virtual ~SpriteSheetEntity();
        void setTilePerLine(unsigned int tilePerLine);
        void setTilePerColumn(unsigned int tilePerColumn);
        void updateTexture(const sf::Texture& texture, unsigned int tilePerLine, unsigned int tilePerColumn);
        void setActiveTile(unsigned int column, unsigned int line);

        unsigned int getTilePerLine() const {return m_tilePerLine;}
        unsigned int getTilePerColumn() const {return m_tilePerColumn;}

    protected:

    private:
        unsigned int m_tilePerLine, m_tilePerColumn;
        sf::IntRect m_rectangle;

};

} // namespace ag

#endif // AG_SPRITESHEETENTITY_HPP
