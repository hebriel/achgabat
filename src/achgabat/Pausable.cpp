#include "achgabat/Pausable.hpp"

/**
 * @file Pausable.cpp
 * @author Underdisk
 */

namespace ag {

Pausable::Pausable()
    : m_isPaused(false)
{   }

Pausable::~Pausable()
{   }

void Pausable::pause()
{
    m_isPaused = true;
    onPause();
}

void Pausable::resume()
{
    m_isPaused = false;
    onResume();
}

void Pausable::revertPauseState()
{
    m_isPaused = !m_isPaused;
    if(m_isPaused) onPause();
    else onResume();
}

void Pausable::onPause()
{

}

void Pausable::onResume()
{

}


} // namespace ag
