# SlowSwitcher #

The `SlowSwitcher` library is a subclass of the `StateMachine` class ([StateMachine-library](https://github.com/twrackers/StateMachine-library)).  A *SlowSwitcher* object is usually in an "on" or "off" state.  However, when it is commanded to toggle to the other state, during a user-specified period the *SlowSwitcher* will be neither on nor off, but will be transitioning between the two states.

An example of a *SlowSwitcher* would be a simulation of a two-lamp signal, say red and green, where a motor-driven set of contacts open on the lamp being turned off before the contacts on the other lamp close to turn it on.  Some railroad trackside signals behave exactly in this manner, where there's a fraction of a second while changing indications during which both lamps are dark.  In fact, this very use case is what drove the creation of this library; I want to create model railroad signals that mimic this switching behavior.

## Dependencies ##

The `SlowSwitcher` library uses the `StateMachine` library.

## Installation ##

Instructions for installing the *SlowSwitcher* library can be found in file `INSTALL.md` in this repository at [https://github.com/twrackers/SlowSwitcher-library/blob/main/INSTALL.md](https://github.com/twrackers/SlowSwitcher-library/blob/main/INSTALL.md).