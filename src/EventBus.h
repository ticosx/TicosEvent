#ifndef EventBus_h
#define EventBus_h
#include <Arduino.h>
#include <list>
#include <map>
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
  Event* receiveEvent(std::string type);
  void init();

private:
  static EventBus* bus;
  std::map<std::string, std::list<Event*>> newEvents;
  std::map<std::string, std::list<Event*>> dispatchedEvents;
  bool initialized = false;
  void _triggerEvent(Event* event);
  EventBus(){}
};
#endif // EventBus_h
