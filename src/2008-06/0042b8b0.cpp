// from server: 100% by colin
extern "C" long __cdecl _InterlockedIncrement(volatile long*);
#pragma intrinsic(_InterlockedExchangeAdd)

bool __cdecl func_0060a2f0();
extern unsigned char descriptor;

struct RefCount
{
    long reserved;
    volatile long count;
};

struct Buffer
{
    unsigned long a;
    unsigned long b;
    unsigned long c;
    RefCount* owner;
};

struct S
{
    unsigned long tag;
    unsigned long reserved;
    Buffer buffer;

    void f(const Buffer& source);
};

void S::f(const Buffer& source)
{
    typedef bool (__cdecl *Predicate)(const Buffer&);

    if (!reinterpret_cast<Predicate>(&func_0060a2f0)(source))
    {
        Buffer* destination = &buffer;
        if (destination)
        {
            destination->a = source.a;
            destination->b = source.b;
            destination->c = source.c;
            RefCount* owner = source.owner;
            destination->owner = owner;
            if (owner)
            {
                volatile long* count = &owner->count;
                _InterlockedIncrement(count);
            }
        }
        tag = reinterpret_cast<unsigned long>(&descriptor);
    }
    else
    {
        tag = 0;
    }
}
