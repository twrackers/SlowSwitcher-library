#include <SlowSwitcher.h>

// Constructor
//
// An instance of this class runs with 10 millisecond timing resolution.
SlowSwitcher::SlowSwitcher(const unsigned int deadTime) :
    StateMachine(10, false),
    m_state(eOff), m_switchTime(0), m_deadTime(deadTime)
{
}

// Gets the current external state (on or off) of the object.
bool SlowSwitcher::read() const
{
    return (m_state == eOn || m_state == eTurningOff);
}

// Gets the switching (true) or steady-state (false) status of the object.
bool SlowSwitcher::isSwitching() const
{
    return (m_state == eTurningOn || m_state == eTurningOff);
}

// Sets the new external state (on or off) of the object.  A state change will
// not be reflected by read until dead time has elapsed.
void SlowSwitcher::write(bool state)
{
    if (state && (m_state == eOff || m_state = eTurningOff)) {
        // Current state is off and on state has been requested.
        m_switchTime = millis();
        m_state = eTurningOn;
    } else if (!state && (m_state == eOn || m_state == eTurningOn)){
        // Current state is on and off state has been requested.
        m_switchTime = millis();
        m_state = eTurningOff;
    }
    // Otherwise nothing changes.
}

// Performs the update cycle for this object.
bool SlowSwitcher::update()
{
    // If it's time to perform an update, ...
    if (StateMachine::update()) {
        // Has dead time elapsed?
        bool past = ((millis() - switchTime) >= deadTime);
        if (m_state == eTurningOn && past) {
            // Dead time elapsed, shift from eTurningOn to eOn.
            m_state = eOn;
        } else if (m_state == eTurningOff && past) {
            // Dead time elapsed, shift from eTurningOff to eOff.
            m_state = eOff;
        }
    }
}
