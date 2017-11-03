#ifndef AG_RESETABLE_HPP
#define AG_RESETABLE_HPP

/**
 * @file Resetable.hpp
 * @author Underdisk
 */

namespace ag {

class Resetable
{
    public:
        Resetable();
        virtual ~Resetable();
        virtual void reset();

    protected:

    private:
};

} // namespace ag

#endif // AG_RESETABLE_HPP
