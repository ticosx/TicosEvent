#include <stdexcept>
#include "EventBus.h"
#include "Log.h"

EventBus* EventBus::bus = NULL;
/**
 * @brief 触发一个事件
 *
 * @param event: 待触发的事件
 */
void EventBus::triggerEvent(Event* event) {
  getInstance()->_triggerEvent(event);
}

void EventBus::_triggerEvent(Event* event) {
  EventType type = event->getType();
  if(type<0 || type>=EVENT_COUNT){
    error("EventBus", "Invalid service type %d", type);
    throw std::invalid_argument("Invalid service type");
  }
  newEvents[type].push_back(event);
}

/**
 * @brief 获取事件总线实例
 *
 * @return 指向事件总线实例的指针
 */
EventBus* EventBus::getInstance() {
  if(bus == NULL){
    bus = new EventBus();
  }
  return bus;
}

/**
 * @brief 分发事件。因为 Luban 运行机制，无法真正实时派送事件，此处只是借用概念，实际动作是清除已分发事件列表，并将新事件转移至待派送列表中。
 * 此方法应在每轮主循环中调用
 */
void EventBus::dispatchEvent() {
  // Clear the dispatchedEvents list
  int i = 0;
  for(; i < EVENT_COUNT; i++) {
    while(dispatchedEvents[i].size() > 0){
      debug("EventBus", "type %d event %d\n",i , dispatchedEvents[i].size());
      Event* event = dispatchedEvents[i].front();
      dispatchedEvents[i].pop_front();
      delete event;
    }
  }

  // Move the first event from newEvents to dispatchedEvents in each type
  for(i = 0; i < EVENT_COUNT; i++) {
    if(newEvents[i].size() > 0){
      debug("EventBus", "type %d event %d\n",i , newEvents[i].size());
      dispatchedEvents[i].push_back(newEvents[i].front());
      newEvents[i].pop_front();
    }
  }
}

/**
 * @brief 获取指定类型中的下一个事件
 *
 * @param type: 希望获得的事件所属的类型
 * @return 指定类型中的下一个事件
 */
Event* EventBus::receiveEvent(EventType type) {
  if(!initialized) {
    error("EventBus", "\tNo EventBus in the application! Please add one into the project!");
    throw std::invalid_argument("\tNo EventBus in the application!");
  }
  if(dispatchedEvents[type].size() > 0){
    return dispatchedEvents[type].front();
  }
  return NULL;
}

/**
 * @brief 初始化事件总线
 */
void EventBus::init() {
  initialized = true;
}