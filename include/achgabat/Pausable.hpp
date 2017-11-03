#ifndef AG_PAUSABLE_HPP
#define AG_PAUSABLE_HPP

/**
 * @file Pausable.hpp
 * @author Underdisk
 */

namespace ag {

class Pausable
{
    public:
        Pausable();
        virtual ~Pausable();

        void pause();
        void resume();
        void revertPauseState();

        bool isPaused() {return m_isPaused;}

    protected:
        virtual void onPause();
        virtual void onResume();

    private:
        bool m_isPaused;
};

} // namespace ag

#endif // AG_PAUSABLE_HPP
