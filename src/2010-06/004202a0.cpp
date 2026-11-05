// from server: 37% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct Inner {
    int pad0;
    volatile long refcount;
    void (__stdcall *dtor)(void*);
    void Release();
};

void Inner::Release()
{
    if (_InterlockedExchangeAdd(&refcount, -1) == 1)
        dtor(this);
}

struct Holder {
    int pad0;
    Inner* ptr;
};

struct Outer {
    void* field0;
    Holder holder;
    Outer* Assign(Outer* other, void* arg);
};

extern "C" void __stdcall sub_420210(Holder* h, void* arg);

Outer* Outer::Assign(Outer* other, void* arg)
{
    field0 = other;
    sub_420210(&holder, arg);
    if (other)
    {
        Inner** slot = (Inner**)((char*)other + 0x2c);
        if (slot)
        {
            *slot = (Inner*)other;
            Inner* cur = holder.ptr;
            if (cur != slot[1])
            {
                if (cur)
                    _InterlockedExchangeAdd(&cur->refcount, 1);
                Inner* old = slot[1];
                if (old)
                {
                    if (_InterlockedExchangeAdd(&old->refcount, -1) == 1)
                        old->dtor(old);
                }
                slot[1] = cur;
            }
        }
    }
    return this;
}
