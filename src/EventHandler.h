#ifndef EventHandler_h
#define EventHandler_h

#include "Event.h"
/*!
 * @brief 消息接收器
 */
class EventHandler {
public:
  EventHandler(std::string type);
  Event* receiveEvent();

private:
  std::string type;
};
#endif // EventHandler_h
