#ifndef Event_h
#define Event_h

#include <string>
using namespace std;

#define MAX_TYPE_LENGTH 16

#define EVT_MODULE  "MOD"
#define EVT_KEY     "KEY"
/*!
 * @brief 事件类
 */
class Event {
public:
  Event(std::string type, long data);
  std::string &getType();
  long getData();

protected:

  std::string type;
  long data = 0;
};
#endif // Event_h
