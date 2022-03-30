#include "Event.h"

/*!
 *    @brief  创建一个事件
 *    @param  type 事件类型
 *    @param  data 事件包含的数据
 */
Event::Event(EventType type, void* data) {
  this->type = type;
  this->data = data;
}

/*!
 *    @brief  获得事件类型
 *    @return 事件类型
 */
EventType Event::getType() {
  return type;
}
  
/*!
 *    @brief  获得事件数据
 *    @return 事件数据
 */
void* Event::getData() {
  return data;
}