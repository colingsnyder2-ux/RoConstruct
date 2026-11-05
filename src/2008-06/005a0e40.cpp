// from server: 100% by king_originala
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)

extern void __cdecl alignedFree(void*);

struct Control {
    virtual void unused();
    virtual void dispose();
    virtual void destroy();
    volatile long strong;
    volatile long weak;
    void release();
};

__forceinline void Control::release()
{
    if (_InterlockedDecrement(&strong) == 0) {
        dispose();
        if (_InterlockedDecrement(&weak) == 0)
            destroy();
    }
}

struct Holder {
    Control* control;
    ~Holder();
};

__forceinline Holder::~Holder()
{
    if (control)
        control->release();
}

struct Entry {
    void* object;
    Holder holder;
};

struct S {
    Entry* entries;
    int count;
    int capacity;
    void clear();
};

void S::clear()
{
    for (int i = 0; i < count; ++i)
        entries[i].holder.~Holder();

    alignedFree(entries);
    entries = 0;
    count = 0;
    capacity = 0;
}
