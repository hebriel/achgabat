#ifndef AG_ENTITY_HPP
#define AG_ENTITY_HPP

#include "GameObject.hpp"
#include "Updatable.hpp"

/**
 * @file Entity.hpp
 * @author Underdisk
 */

namespace ag {

class Entity : public ag::Updatable, ag::GameObject
{
    public:
        Entity();
        virtual ~Entity();

    protected:

    private:
};

} // namespace ag

#endif // AG_ENTITY_HPP
