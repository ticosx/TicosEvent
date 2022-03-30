#ifndef EventBus_h
#define EventBus_h
#include <Arduino.h>
#include <list>
using namespace std;

#include "Event.h"
/*!
 * @brief 负责收发事件的总线类
 */

class EventBus {

public:
  static void triggerEvent(Event* event);
  static EventBus* getInstance();
  void dispatchEvent();
  Event* receiveEvent(EventType type);
  void init();

private:
  static EventBus* bus;
  std::list<Event*> newEvents[EVENT_COUNT];
  std::list<Event*> dispatchedEvents[EVENT_COUNT];
  bool initialized = false;
  void _triggerEvent(Event* event);
  EventBus(){}
};
#endif // EventBus_h
