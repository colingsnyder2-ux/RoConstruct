// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <exception>
#include <string>
#include <boost/shared_ptr.hpp>

namespace RBX {

// INFERRED: minimal local declarations, since no class headers were given.
class World;

struct AutoJoin {
    // INFERRED: passed by value as a single dword
    int value;
};

enum MessageType { MESSAGE_OUTPUT = 0, MESSAGE_INFO = 1, MESSAGE_WARNING = 2, MESSAGE_ERROR = 2 };

class StandardOut {
public:
    static boost::shared_ptr<StandardOut> singleton();
    void print(MessageType type, const char* format, ...);
};

template<class Class, class Event> class Notifier;

template<class Class, class Event>
class Listener {
public:
    virtual void onEvent(const Notifier<Class, Event>* notifier, Event e) = 0;
};

template<class Class, class Event>
class Notifier {
protected:
    void raise(Event event, Listener<Class, Event>* listener) const;
};

template<class Class, class Event>
void Notifier<Class, Event>::raise(Event event, Listener<Class, Event>* listener) const
{
    try
    {
        listener->onEvent(this, event);
    }
    catch (std::exception& e)
    {
        // INFERRED: named local string so c_str() is evaluated directly from the frame object
        std::string msg(e.what());
        StandardOut::singleton()->print(MESSAGE_ERROR, "Exception caught in onEvent. %s",
                                        msg.c_str());
    }
}

template void Notifier<World, AutoJoin>::raise(AutoJoin, Listener<World, AutoJoin>*) const;

}
