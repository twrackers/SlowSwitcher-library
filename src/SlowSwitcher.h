#ifndef _SLOW_SWITCHER__H_
#define _SLOW_SWITCHER__H_

#include <StateMachine.h>

/**
 * SlowSwitcher
 *
 * This class extends the StateMachine class to provide a boolean output which
 * switches between true and false (on and off) upon command, with a settable
 * dead time during which the state actually changes.
 *
 * When a SlowSwitcher object is commanded to toggle its state, say from off
 * (false) to on (true), it internally actually enters a "turning on" state for
 * a fixed duration, then goes to the on state.  While in the "turning on"
 * state, the object will still read back as off, but method isSwitching will
 * return true.  Switching from on to off does the same thing, going through a
 * "turning off" state for the same duration.
 */
class SlowSwitcher : public StateMachine
{
    protected:
        enum E_STATE {
            eOff, eTurningOn, eOn, eTurningOff
        } m_state;                          // current state
        
        unsigned long       m_switchTime;   // clock time at last write
        const unsigned long m_deadTime;     // duration of turning on/off states
        
    public:
        /**
         * Constructor
         *
         * @param deadTime duration of state changes between off and on
         */
        SlowSwitcher(const unsigned int deadTime);
        
        /**
         * Get the current on/off state
         *
         * If object is turning on or off, this method will return the prior
         * state (was off or was on).
         *
         * @return current on/off state
         */
        bool read() const;
        
        /**
         * Get the switching status
         *
         * Returns true if the object is internally in eTurningOn or eTurningOff
         * state, false if in eOn or eOff state.
         *
         * @return switching status
         */
        bool isSwitching() const;
        
        /**
         * Set the commanded state
         *
         * If the object is not switching states, then a write to the opposite
         * state will put the object in switching status.  If the object is
         * already switching, it will change to the opposite switching status
         * and the switching period will start over.
         * For example, if the object is in eOff state and a write(true) is
         * called, it will change internally to eTurningOn, then after the dead
         * time elapses, it will go to eOn state.  If a write(false) is called
         * before the eTurningOn dead time completes, the object will change
         * to eTurningOff state and the dead time will restart.
         *
         * @param state desired new state of object
         */
        void write(bool state);
        
        /*
         * Update this object's state
         *
         * @return true if object's state was updated
         */
        virtual bool update();
};

#endif
