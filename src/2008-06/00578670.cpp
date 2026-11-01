// from server: 100% by king_originala
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)

extern void (__cdecl* invalidParameter)();
void* __cdecl operator new(unsigned int) throw();

struct Control {
    virtual void unused();
    virtual void dispose();
    virtual void destroy();
    volatile long strong;
    volatile long weak;
    void release();
};

inline void Control::release()
{
    if (_InterlockedDecrement(&strong) == 0) {
        dispose();
        if (_InterlockedDecrement(&weak) == 0)
            destroy();
    }
}

struct Shared {
    void* object;
    Control* control;
    ~Shared();
};

inline Shared::~Shared()
{
    if (control)
        control->release();
}

struct Object {
    virtual ~Object();
};

struct Slot {
    Object* object;
    void assign(Shared*);
};

struct Arguments {
    unsigned int bookkeeping[3];
    Slot* first;
    Slot* last;
    Slot* limit;

    Arguments(unsigned int);
    ~Arguments();
};

struct Receiver {
    virtual void unused();
    virtual void invoke(Arguments*);
};

struct Wrapper {
    void* vtable;
    void* object;
};

extern void* wrapperVtable[];

struct Creator {
    Receiver* receiver;
    void create(Shared, void*);
};

void Creator::create(Shared value, void* object)
{
    Arguments arguments(2);
    void (__cdecl* invalid)() = invalidParameter;

    if (static_cast<unsigned int>(arguments.last - arguments.first) <= 0)
        invalid();

    arguments.first->assign(&value);

    if (static_cast<unsigned int>(arguments.last - arguments.first) <= 1)
        invalid();

    Slot* slot = arguments.first + 1;
    Wrapper* wrapper = static_cast<Wrapper*>(operator new(8));
    if (wrapper) {
        wrapper->vtable = wrapperVtable;
        wrapper->object = object;
    } else {
        wrapper = 0;
    }

    Object* previous = reinterpret_cast<Object*>(wrapper);
    if (reinterpret_cast<void*>(&object) != reinterpret_cast<void*>(slot)) {
        previous = slot->object;
        slot->object = reinterpret_cast<Object*>(wrapper);
    }

    if (previous)
        delete previous;

    receiver->invoke(&arguments);
}
