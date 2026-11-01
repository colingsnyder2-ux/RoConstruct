// from server: 97% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

extern "C" void __stdcall sub_41B850(int);
extern "C" void* __cdecl sub_7A79A0(unsigned int);

struct Inner {
    int a;
    long ref;
    char b;
};

struct Outer {
    char pad0[0x10];
    Inner** items;
    int capacity;
    int count;
    int index;
    void insert(Inner* value);
};

void Outer::insert(Inner* value)
{
    int idx = index + 1;
    if (capacity <= (unsigned)idx)
        sub_41B850(1);

    int pos = count + index;
    if ((unsigned)capacity <= (unsigned)pos)
        pos -= capacity;

    if (items[pos] == 0)
        items[pos] = (Inner*)sub_7A79A0(0xc);

    Inner* slot = items[pos];
    if (slot != 0)
    {
        slot->a = value->a;
        slot->ref = value->ref;
        if (slot->ref != 0)
            _InterlockedExchangeAdd((volatile long*)(slot->ref + 4), 1);
        slot->b = value->b;
    }
    index++;
}
