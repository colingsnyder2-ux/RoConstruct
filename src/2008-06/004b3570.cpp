// from server: 100% by colin
extern "C" long __cdecl _InterlockedIncrement(volatile long*);
#pragma intrinsic(_InterlockedExchangeAdd)

struct RefCount {
    long unused;
    volatile long count;
};

struct Data {
    long a;
    long b;
    long c;
    long d;
    RefCount* owner;
};

extern bool __cdecl func_0060a2f0();
extern const char function_table;

struct S {
    const void* table;
    long unused;
    Data data;

    void f(const Data& source);
};

void S::f(const Data& source)
{
    typedef bool (__cdecl *Predicate)(const Data&);
    if (!((Predicate)func_0060a2f0)(source)) {
        Data* destination = &data;
        if (destination) {
            destination->a = source.a;
            destination->b = source.b;
            destination->c = source.c;
            destination->d = source.d;
            destination->owner = source.owner;
            if (destination->owner)
                _InterlockedIncrement(&destination->owner->count);
        }
        table = &function_table;
    } else {
        table = 0;
    }
}
