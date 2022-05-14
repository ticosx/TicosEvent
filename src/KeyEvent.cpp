#include "KeyEvent.h"

/**
 * @brief 按键事件
 *
 * @param keyCode: 键值。0 为保留键值
 * @param state: 按键状态
 */
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