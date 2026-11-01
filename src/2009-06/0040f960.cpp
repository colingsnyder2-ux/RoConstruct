// from server: 92% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
#include <string>
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

class CString {
public:
    __declspec(dllimport) CString();
    __declspec(dllimport) ~CString() throw();
    __declspec(dllimport) bool IsEmpty() const;
    __declspec(dllimport) char GetAt(int) const;
    __declspec(dllimport) operator const char*() const;
    char* p;
};

struct Control { unsigned int unused; volatile long references; };
struct Shared {
    void* pointer;
    Control* control;
    Shared(const Shared& value) : pointer(value.pointer), control(value.control)
    {
        if (control) { volatile long* count = &control->references; _InterlockedExchangeAdd(count, 1); }
    }
    ~Shared();
};
struct Guard {
    void* state;
    Guard(Shared, bool);
    ~Guard();
};
struct Receiver {
    void sendCommand(std::string);
    void send(std::string);
};
struct Widget { void close(); };
extern int close_value;

struct ChatEnter {
    unsigned char padding[0x88];
    Widget* widget;
    unsigned char padding2[0x10];
    Shared shared;
    Receiver* receiver;

    void key(int, int, int);
    void Default();
    void close(int);
    void GetWindowTextA(CString&);
};

void ChatEnter::key(int key, int, int)
{
    switch (key) {
    default:
        Default();
        return;
    case 27:
        close(close_value);
        widget->close();
        return;
    case 13:
        break;
    }

    CString text;
    GetWindowTextA(text);
    if (receiver && !text.IsEmpty()) {
        try {
            {
                Guard guard(shared, true);
                if (text.GetAt(0) == '%')
                    receiver->sendCommand((const char*)text);
                else
                    receiver->send((const char*)text);
            }
            close(close_value);
        } catch (...) {
        }
    }
    widget->close();
}
