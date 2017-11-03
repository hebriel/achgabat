#ifndef AG_AUTOSPRITESHEETENTITY_HPP
#define AG_AUTOSPRITESHEETENTITY_HPP

#include "SpriteSheetEntity.hpp"
#include "Animator.hpp"
#include "Resetable.hpp"

/**
 * @file AutoSpriteSheetEntity.hpp
 * @author Underdisk
    \brief A way to easily manage time with spritesheets
 */

namespace ag {

class AutoSpriteSheetEntity : public ag::SpriteSheetEntity, ag::Animator
{
    public:
        AutoSpriteSheetEntity();
        AutoSpriteSheetEntity(const sf::Texture& texture, unsigned int tilePerLine, unsigned int tilePerColumn);
        virtual ~AutoSpriteSheetEntity();

        void setFrequency(float frequency); /**Frequency in HZ**/

        void updateAnimator(const sf::Time& dt) override;
        void setLine(unsigned int line) {m_line = line;}
        unsigned int getLine() const {return m_line;}
        unsigned int getColumn() const {return m_column;}
        bool isEndOfLoop() const {return m_endOfLoop;}
        void resetLoop();

    protected:

    private:

        float m_cumulus;
        float m_period;
        unsigned int m_column, m_line;
        bool m_endOfLoop;
};

} // namespace ag

#endif // AG_AUTOSPRITESHEETENTITY_HPP
