// from server: 100% by king_originala
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)

extern "C" void* __cdecl G_006a17c6(void*, long, void*, void*, int);

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
    void G_005fc150();
    void G_005fc1d0();
    void G_005fbc80(void*);
};

struct S
{
    char padding[0x1c];
    void* backpack;
    void f(void*, Shared);
};

void S::f(void*, Shared value)
{
    void* result = G_006a17c6(value.object, 0,
                            G_0092907c, G_00937460, 0);
    if (result)
    {
        if (result == backpack)
            ((Owner*)((char*)this - 0x16c))->G_005fc150();
    }
    else
    {
        result = G_006a17c6(value.object, 0,
                          G_0092907c, G_009353ec, 0);
        if (result)
            ((Owner*)((char*)this - 0x16c))->G_005fc1d0();
        else
        {
            result = G_006a17c6(value.object, 0,
                              G_0092907c, G_00951950, 0);
            if (result)
                ((Owner*)((char*)this - 0x16c))->G_005fbc80(result);
        }
    }
}
