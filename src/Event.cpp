#include "Event.h"
#include <stdexcept>
#include "EventBus.h"
#include "Log.h"

/*!
 *    @brief  创建一个事件
 *    @param  type 事件类型。长度最大为 16
 *    @param  data 事件包含的数据
 */
Event::Event(std::string type, long data) {
  if(type.size() >= MAX_TYPE_LENGTH){
    error("Event", "Event type's length must be less than %d", MAX_TYPE_LENGTH);
    throw std::invalid_argument("Event type's length too long");
  }
  this->type = type;
  this->data = data;
}

/*!
 *    @brief  获得事件类型
 *    @return 事件类型
 */
std::string &Event::getType() {
  return type;
}
  
/*!
 *    @brief  获得事件数据
 *    @return 事件数据
 */
long Event::getData() {
  return data;
}