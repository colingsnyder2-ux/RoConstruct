// from server: 100% by king_originala
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)

struct Control
{
    virtual void unused() = 0;
    virtual void dispose() = 0;
    virtual void destroy() = 0;
    volatile long strong;
    volatile long weak;

    void release();
};

inline void Control::release()
{
    if (_InterlockedDecrement(&strong) == 0)
    {
        dispose();
        if (_InterlockedDecrement(&weak) == 0)
            destroy();
    }
}

struct Listener
{
    char storage[0x90];
};

struct Event
{
    void connect(Listener*);
};

struct Object
{
    char padding[0xc4];
    Event event;
};

struct Shared
{
    Object* object;
    Control* control;
    ~Shared();
};

inline Shared::~Shared()
{
    if (control)
        control->release();
}

struct Slot
{
    void assign(Object*);
};

struct CSelectionPropGrid
{
    char padding[0x188];
    Listener listener;
    Slot slot;

    void set(Shared value);
};

void CSelectionPropGrid::set(Shared value)
{
    Listener* target = this ? &listener : 0;
    if (value.object)
        value.object->event.connect(target);
    slot.assign(value.object);
}
