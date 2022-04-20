#include "KeyEvent.h"

KeyEvent::KeyEvent(uint16_t keyCode, KeyState state) : Event(EVT_KEY, 0) {
  this->keyCode = keyCode;
  this->state = state;
}

uint16_t KeyEvent::getKey() {
  return keyCode;
}

KeyState KeyEvent::getState() {
  return state;
}