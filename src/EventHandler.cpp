#include "EventHandler.h"
#include "EventBus.h"

EventHandler::EventHandler(std::string type) {
  this->type = type;
}

Event* EventHandler::receiveEvent() {
  return EventBus::getInstance()->receiveEvent(type);
}