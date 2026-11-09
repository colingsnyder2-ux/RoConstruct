// from server: 100% by king_originala
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)

struct Control {
    virtual void reserved();
    virtual void dispose();
    virtual void destroy();
    volatile long strong;
    volatile long weak;
    void release();
};

struct Owner {
    Control* control;
    Owner& operator=(const Owner&);
};

struct Pair {
    void* pointer;
    Owner owner;
    Pair& operator=(const Pair&);
    ~Pair();
};

extern char factory;
extern void* __stdcall invoke(void*, void*);
extern Pair __cdecl makePair(void*);

struct HammerTool {
    char padding[0x1c];
    Pair value;
    void set(void*);
};

__forceinline void Control::release()
{
    if (_InterlockedDecrement(&strong) == 0) {
        dispose();
        if (_InterlockedDecrement(&weak) == 0)
            destroy();
    }
}

__forceinline Pair& Pair::operator=(const Pair& other)
{
    pointer = other.pointer;
    owner = other.owner;
    return *this;
}

__forceinline Pair::~Pair()
{
    if (owner.control)
        owner.control->release();
}

void HammerTool::set(void* argument)
{
    value = makePair(invoke(argument, &factory));
}
