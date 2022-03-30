#ifndef Event_h
#define Event_h

#ifdef __cplusplus
extern "C" {
#endif

typedef enum {
    KEY_EVENT = 0,
    MOD_EVENT,
    EVENT_COUNT
} EventType;

#ifdef __cplusplus
}
#endif
/*!
 * @brief 事件类
 */
class Event {
public:
  Event(EventType type, void* data);
  EventType getType();
  void* getData();

protected:

  EventType type;
  void* data;
};
#endif // Event_h
