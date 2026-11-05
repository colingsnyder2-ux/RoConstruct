// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <string>

extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)

struct Control
{
    virtual void unused();
    virtual void dispose();
    virtual void destroy();
    volatile long strong;
    volatile long weak;

    void release()
    {
        if (_InterlockedDecrement(&strong) == 0)
        {
            dispose();
            if (_InterlockedDecrement(&weak) == 0)
                destroy();
        }
    }
};

struct Second
{
    void* value;
    Control* control;

    ~Second()
    {
        if (control)
            control->release();
    }
};

struct Pair
{
    std::string first;
    char pad[4];
    Second second;

    ~Pair();
};

Pair::~Pair()
{
}
