// from server: 100% by king_originala
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
extern "C" long __cdecl _InterlockedIncrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)
#pragma intrinsic(_InterlockedIncrement)

struct Control {
    virtual void unused() = 0;
    virtual void dispose() = 0;
    virtual void destroy() = 0;
    volatile long strong;
    volatile long weak;
    void release();
};

void Control::release()
{
    if (_InterlockedDecrement(&strong) == 0) {
        dispose();
        if (_InterlockedDecrement(&weak) == 0)
            destroy();
    }
}

struct Object {
    char padding[20];
    void setParent(Object*);
};

struct Shared {
    Object* pointer;
    Control* control;
    Shared(const Shared&);
    ~Shared();
};

Shared::Shared(const Shared& other)
    : pointer(other.pointer), control(other.control)
{
    if (control)
        _InterlockedIncrement(&control->strong);
}

Shared::~Shared()
{
    if (control)
        control->release();
}

struct Alias {
    void* pointer;
    Control* control;
    Alias(const Shared&);
    Alias(const Alias&);
    ~Alias();
};

Alias::Alias(const Shared& other)
    : pointer(other.pointer ? other.pointer->padding + 20 : 0),
      control(other.control)
{
    if (control)
        _InterlockedIncrement(&control->strong);
}

Alias::Alias(const Alias& other)
    : pointer(other.pointer), control(other.control)
{
    if (control)
        _InterlockedIncrement(&control->strong);
}

Alias::~Alias()
{
    if (control)
        control->release();
}

extern "C" void* __cdecl getArgument(void*, int);
extern "C" void* __cdecl resolveObject(void*);
extern Shared __cdecl makeShared(void*);
extern "C" int __cdecl argumentCount(void*);
extern Shared __cdecl readShared(void*, int);
extern void __cdecl pushShared(void*, Alias);

int __cdecl function(void* state)
{
    Shared object = makeShared(resolveObject(getArgument(state, 1)));
    if (argumentCount(state) >= 2) {
        Shared parent = readShared(state, 2);
        if (parent.pointer)
            object.pointer->setParent(parent.pointer);
    }
    pushShared(state, Alias(object));
    return 1;
}
