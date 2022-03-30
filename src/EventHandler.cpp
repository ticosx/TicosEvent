#include "EventHandler.h"
#include "EventBus.h"

EventHandler::EventHandler(EventType type) {
  this->type = type;
}

Event* EventHandler::receiveEvent() {
  return EventBus::getInstance()->receiveEvent(type);
}