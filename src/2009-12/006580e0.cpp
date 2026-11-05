// from server: 42% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct Inner
{
    char pad0[8];
    volatile long refcount;
};

struct Holder
{
    void* ptr;
    void* other;
};

struct S
{
    void* field0;
    void* field4;
    S* construct(void* arg1, void* arg2);
};

extern "C" void* __fastcall sub_00657A80(void*, void*, void*);

S* S::construct(void* arg1, void* arg2)
{
    this->field0 = arg1;
    sub_00657A80(&this->field4, 0, arg2);
    if (arg1 != 0)
    {
        Holder* h = (Holder*)((char*)arg1 + 0x2c);
        if (h != 0)
        {
            h->ptr = arg1;
            void* old = this->field4;
            if (old != h->other)
            {
                if (old != 0)
                {
                    _InterlockedExchangeAdd(&((Inner*)((char*)old + 8))->refcount, 1);
                }
                void* cur = h->other;
                if (cur != 0)
                {
                    if (_InterlockedExchangeAdd(&((Inner*)((char*)cur + 8))->refcount, -1) == 1)
                    {
                        (*(void(__thiscall**)(void*))((*(void***)cur)[2]))(cur);
                    }
                }
                h->other = old;
            }
        }
    }
    return this;
}
