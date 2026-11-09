// from server: 100% by king_originala
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)

extern void __cdecl alignedFree(void*);

struct Control
{
    virtual void unused() = 0;
    virtual void dispose() = 0;
    virtual void destroy() = 0;
    volatile long strong;
    volatile long weak;
};

struct Shared
{
    void* object;
    Control* control;
    ~Shared();
};

Shared::~Shared()
{
    Control* p = control;
    if (p && _InterlockedDecrement(&p->strong) == 0)
    {
        p->dispose();
        if (_InterlockedDecrement(&p->weak) == 0)
            p->destroy();
    }
}

struct Buffer
{
    void* data;
    unsigned size;
    unsigned capacity;
    ~Buffer();
};

Buffer::~Buffer()
{
    alignedFree(data);
    data = 0;
    size = 0;
    capacity = 0;
}

struct Primary
{
    virtual void primarySlot() = 0;
};

struct Secondary
{
    virtual void secondarySlot() = 0;
};

struct Landed : Primary, Secondary
{
    unsigned padding[3];
    Buffer buffer;
    unsigned padding2;
    Shared shared;

    virtual void primarySlot();
    virtual void secondarySlot();
    void reset(int);
    ~Landed();
};

Landed::~Landed()
{
    reset(0);
}
