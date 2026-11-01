// from server: 100% by king_originala
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)

extern "C" void* __cdecl G_006a17c6(void*, long, void*, void*, int);
extern "C" void* __cdecl G_0049ac80(void*);

extern char G_0092907c[];
extern char G_00937460[];
extern char G_009353ec[];
extern char G_00951950[];

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
    if (p)
    {
        if (_InterlockedDecrement(&p->strong) == 0)
        {
            p->dispose();
            if (_InterlockedDecrement(&p->weak) == 0)
                p->destroy();
        }
    }
}

struct Owner
{
    void G_005fc810(void*);
    void G_005fc940(void*);
    void G_005fd0b0(void*);
};

struct S
{
    void f(void*, Shared);
};

void S::f(void*, Shared value)
{
    void* result = G_006a17c6(value.object, 0,
                            G_0092907c, G_00937460, 0);
    if (result)
    {
        Owner* owner = (Owner*)((char*)this - 0x168);
        if (result == G_0049ac80(owner))
            owner->G_005fc810(result);
    }
    else
    {
        result = G_006a17c6(value.object, 0,
                           G_0092907c, G_009353ec, 0);
        if (result)
            ((Owner*)((char*)this - 0x168))->G_005fc940(result);
        else
        {
            result = G_006a17c6(value.object, 0,
                               G_0092907c, G_00951950, 0);
            if (result)
                ((Owner*)((char*)this - 0x168))->G_005fd0b0(result);
        }
    }
}
