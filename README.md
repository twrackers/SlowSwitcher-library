# SlowSwitcher library

This library is a subclass of the __StateMachine__ class found in this repository at [Arduino-projects/libraries/StateMachine](https://github.com/twrackers/Arduino-projects/tree/master/libraries/StateMachine).  Application code can switch a SlowSwitcher object between its on and off states, but when a state change is requested, there will be a user-defined interval during which the SlowSwitcher is neither on or off but is transitioning between those two states.

An example of a SlowSwitcher would be a simulation of a two-lamp signal, say red and green, where a motor-driven set of contacts open on the lamp being turned off before the contacts on the other lamp close.  Some trackside signals used by railroads behave exactly in this manner, where there's a fraction of a second when changing indications during which both lamps are dark.  In fact, this very use case is what drove the creation of this library.
