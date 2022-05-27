#ifndef KeyEvent_h
#define KeyEvent_h

#include "stdio.h"
#include "Event.h"

#define LONG_PRESS_DURATION 2
#ifdef __cplusplus
extern "C" {
#endif

typedef enum {
    KEY_UNDEF = 0,
    KEY_DOWN,
    KEY_UP,
    KEY_LONG_UP,
} KeyState;

#ifdef __cplusplus
}
#endif

#define NO_KEY  0
/*!
 * @brief 事件类
 */
class KeyEvent : public Event {
public:
  KeyEvent(uint16_t keyCode, KeyState state);
  virtual ~KeyEvent() {};
  uint16_t getKey();
  KeyState getState();

protected:

  KeyState state;
  uint16_t keyCode;
};
#endif // KeyEvent_h