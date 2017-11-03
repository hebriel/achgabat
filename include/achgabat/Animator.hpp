#ifndef AG_ANIMATOR_HPP
#define AG_ANIMATOR_HPP

#include <SFML/Graphics.hpp>

/**
 * @file Animator.hpp
 * @author Underdisk
 */

namespace ag {

class Animator
{
    public:
        Animator();
        virtual ~Animator();

        virtual void updateAnimator();
        virtual void updateAnimator(const sf::Time& dt);

    protected:

    private:
};

} // namespace ag

#endif // AG_ANIMATOR_HPP
