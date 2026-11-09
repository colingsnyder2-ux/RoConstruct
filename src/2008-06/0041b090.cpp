// from server: 100% by colin
extern "C" long __cdecl _InterlockedIncrement(volatile long*);
#pragma intrinsic(_InterlockedExchangeAdd)

struct Control
{
    long reserved;
    volatile long references;
};

struct Data
{
    unsigned long a;
    unsigned long b;
    unsigned long c;
    Control* control;
    unsigned long e;
};

extern bool __cdecl func_0060a2f0(const Data*);
extern unsigned char marker_0080ed34;

struct S
{
    void* tag;
    unsigned long reserved;
    Data data;

    void f(const Data* source);
};

void S::f(const Data* source)
{
    if (!func_0060a2f0(source))
    {
        Data* destination = &data;
        if (destination)
        {
            destination->a = source->a;
            destination->b = source->b;
            destination->c = source->c;
            destination->control = source->control;
            if (destination->control)
                _InterlockedIncrement(&destination->control->references);
            destination->e = source->e;
        }
        tag = &marker_0080ed34;
    }
    else
    {
        tag = 0;
    }
}
