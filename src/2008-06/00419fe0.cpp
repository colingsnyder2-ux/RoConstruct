// from server: 100% by colin
extern "C" long __cdecl _InterlockedIncrement(volatile long*);
#pragma intrinsic(_InterlockedExchangeAdd)

struct Counter {
    long reserved;
    volatile long references;
};

struct Data {
    unsigned long first;
    unsigned long second;
    unsigned long third;
    Counter* counter;
};

extern bool __cdecl func_0060a2f0(const Data*);
extern char target_0080ecc0;

struct S {
    void* tag;
    unsigned long reserved;
    Data data;

    void assign(const Data* source);
};

void S::assign(const Data* source)
{
    if (!func_0060a2f0(source)) {
        Data* destination = &data;
        if (destination) {
            destination->first = source->first;
            destination->second = source->second;
            destination->third = source->third;
            Counter* counter = source->counter;
            destination->counter = counter;
            if (counter)
                _InterlockedIncrement(&counter->references);
        }
        tag = &target_0080ecc0;
    } else {
        tag = 0;
    }
}
