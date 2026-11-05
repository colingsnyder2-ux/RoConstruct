// from server: 100% by king_originala
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)

struct Instance;

struct Hole {
    void setFirst(Instance*);
    void setSecond(Instance*);
};

struct Control {
    virtual void unused();
    virtual void dispose();
    virtual void destroy();
    volatile long strong;
    volatile long weak;
    void release();
};

struct SharedHole {
    Hole* object;
    Control* control;
    ~SharedHole();
};

extern bool __cdecl eligible(Instance*, Instance*);
extern SharedHole __cdecl createHole();
extern "C" void* __cdecl __RTDynamicCast(void*, long, void*, void*, int);

extern char instanceType;
extern char holeType;

__forceinline void Control::release()
{
    if (_InterlockedDecrement(&strong) == 0) {
        dispose();
        if (_InterlockedDecrement(&weak) == 0)
            destroy();
    }
}

__forceinline SharedHole::~SharedHole()
{
    if (control)
        control->release();
}

void __cdecl connectHole(Instance* a, Instance* b)
{
    if (eligible(a, b)) {
        Instance* first;
        if (__RTDynamicCast(a, 0, &instanceType, &holeType, 0))
            first = a;
        else
            first = b;

        if (first == a)
            a = b;

        SharedHole hole = createHole();
        hole.object->setFirst(first);
        hole.object->setSecond(a);
    }
}
