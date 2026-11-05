// from server: 14% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct Inner {
    char pad0[8];
    volatile long refcount;
    char pad1[0x20];
    Inner* ptr;
};

struct Sub {
    char pad0[4];
    Inner* ptr;
};

struct Widget {
    void* field0;
    Sub sub;
    void assign(void* a, void* b);
};

extern void sub_005df380(Sub* self, void* a, void* b);

void Widget::assign(void* a, void* b)
{
    this->field0 = a;
    sub_005df380(&this->sub, a, b);
    if (a == 0)
        return;
    Inner* p = (Inner*)((char*)a + 0x2c);
    if (p == 0)
        return;
    p->ptr = (Inner*)a;
    Inner* old = this->sub.ptr;
    if (old == p->ptr)
        return;
    if (old != 0)
        _InterlockedExchangeAdd(&old->refcount, 1);
    Inner* cur = p->ptr;
    if (cur != 0)
    {
        if (_InterlockedExchangeAdd(&cur->refcount, -1) == 1)
        {
            void** vt = *(void***)cur;
            void (*fn)(Inner*) = (void (*)(Inner*))vt[2];
            fn(cur);
        }
    }
    p->ptr = old;
}
