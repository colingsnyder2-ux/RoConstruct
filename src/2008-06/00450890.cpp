// from server: 100% by king_originala
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)

struct Control
{
    virtual void unused();
    virtual void dispose();
    virtual void destroy();
    volatile long strong;
    volatile long weak;
};

struct Object
{
    char padding[0x2ec];
    char value;
};

struct Owner
{
    char padding[0x204];
    Object* object;
};

struct Pair
{
    Owner* pointer;
    Control* control;
};

struct S
{
    Pair* get(Pair*);
    void* func_00450890();
};

void* S::func_00450890()
{
    Pair p;
    Object* object = get(&p)->pointer->object;
    void* result = object ? &object->value : 0;
    Control* control = p.control;

    if (control && _InterlockedDecrement(&control->strong) == 0)
    {
        control->dispose();
        if (_InterlockedDecrement(&control->weak) == 0)
            control->destroy();
    }

    return result;
}
