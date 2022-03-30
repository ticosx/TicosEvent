#include "KeyEvent.h"

KeyEvent::KeyEvent(uint16_t keyCode, KeyState state) : Event(KEY_EVENT, NULL) {
  this->keyCode = keyCode;
  this->state = state;
}

uint16_t KeyEvent::getKey() {
  return keyCode;
}

KeyState KeyEvent::getState() {
  return state;
}