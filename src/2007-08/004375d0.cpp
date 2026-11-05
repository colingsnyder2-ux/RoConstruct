// from server: 100% by EspClaude
// roc 2007-08 004375d0  RBX::MarshaledListener<StandardOut, StandardOutMessage, StandardOut, StandardOutMessage>::MarshaledListener() (RTTI from vtable; vector @+4, threadId @+0x14, marshal HWND @+0x18)
// roc-flags: /O2 /GS /EHsc /MD
#include <vector>
typedef struct HWND__* HWND;
extern "C" __declspec(dllimport) unsigned long __stdcall GetCurrentThreadId();
namespace RBX {
class StandardOut; struct StandardOutMessage { int type; const char* message; };
class CMarshalWindow { public: static HWND getWindow(); };
template<class Source, class Event> class __declspec(novtable) Listener {
protected:
    virtual void onEvent(const Source* source, Event event) = 0;
public:
    virtual ~Listener();
};
template<class Source, class Event, class MSource, class MEvent>
class MarshaledListener : public Listener<Source, Event> {
    std::vector<MEvent> queue;
    unsigned long threadId;
    HWND window;
public:
    MarshaledListener()
    {
        threadId = GetCurrentThreadId();
        window = CMarshalWindow::getWindow();
    }
    virtual void onEvent(const Source* source, Event event);
};
template class MarshaledListener<StandardOut, StandardOutMessage, StandardOut, StandardOutMessage>;
}
