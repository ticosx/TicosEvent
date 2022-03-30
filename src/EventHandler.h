#ifndef EventHandler_h
#define EventHandler_h

#include "Event.h"
/*!
 * @brief 消息接收器
 */
class EventHandler {
public:
  EventHandler(EventType type);
  Event* receiveEvent();

private:
  EventType type;
};
#endif // EventHandler_h
