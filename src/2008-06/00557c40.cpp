// from server: 100% by colin
// from server: 88% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
#include <string>
#include <exception>

extern "C" long __cdecl _InterlockedIncrement(volatile long*);
#pragma intrinsic(_InterlockedIncrement)

struct Control
{
    long reserved;
    volatile long references;
};

struct Shared
{
    void* object;
    Control* control;

    Shared(const Shared& other);
};

inline Shared::Shared(const Shared& other)
    : object(other.object), control(other.control)
{
    if (control)
        _InterlockedIncrement(&control->references);
}

struct Arguments
{
    Shared first;
    Shared second;
    ~Arguments();
};

struct Callback
{
    virtual void invoke(void* owner, Arguments arguments) = 0;
};

struct StandardOut {
    void print(int, const char *, ...);
};

struct OutHandle {
    StandardOut *pointer;
    void *count;
    ~OutHandle();
    StandardOut *operator->() const { return pointer; }
};

OutHandle __cdecl singleton();

struct S
{
    void f(Arguments arguments, Callback* callback);
};

void S::f(Arguments arguments, Callback* callback)
{
    try
    {
        void* owner = this ? reinterpret_cast<char*>(this) - 0x84 : 0;
        callback->invoke(owner, arguments);
    }
    catch (std::exception &e)
    {
        std::string message(e.what());
        singleton()->print(2, "%s", message.c_str());
    }
}
