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
  std::string &type = event->getType();
  auto &events = newEvents[type];
  events.push_back(event);
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
 * @brief 分发事件。因为 Ticos 可视化编程语言的运行机制，无法真正实时派送事件，此处只是借用概念，实际动作是清除已分发事件列表，并将新事件转移至待派送列表中。
 * 此方法应在每轮主循环中调用
 */
void EventBus::dispatchEvent() {
  // Clear the dispatchedEvents list
  for (std::map<std::string, std::list<Event*>>::iterator it=dispatchedEvents.begin(); it!=dispatchedEvents.end(); ++it) {
    while(it->second.size() > 0){
      debug("EventBus", "type %s event %d\n",it->first , it->second.size());
      Event* event = it->second.front();
      it->second.pop_front();
      delete event;
    }
  }

  // Move the first event from newEvents to dispatchedEvents in each type
  for (std::map<std::string, std::list<Event*>>::iterator it=newEvents.begin(); it!=newEvents.end(); ++it) {
    if(it->second.size() > 0){
      debug("EventBus", "type %s event %d\n",it->first , it->second.size());
      dispatchedEvents[it->first].push_back(it->second.front());
      it->second.pop_front();
    }
  }
}

/**
 * @brief 获取指定类型中的下一个事件
 *
 * @param type: 希望获得的事件所属的类型
 * @return 指定类型中的下一个事件
 */
Event* EventBus::receiveEvent(std::string type) {
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