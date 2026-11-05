// from server: 43% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct Inner {
    void* obj;
    char pad0[4];
    volatile long refcount;
};

struct Holder {
    void* obj;
    void* prev;
};

struct Outer {
    void* field0;
    Holder holder;
    void init(void* a, void* b);
};

extern "C" void __stdcall sub_4afc40(Holder* h, void* a, void* b);

void Outer::init(void* a, void* b)
{
    this->field0 = a;
    sub_4afc40(&this->holder, a, b);
    if (a != 0) {
        Inner* p = (Inner*)((char*)a + 0x2c);
        if (p != 0) {
            p->obj = a;
            Inner* old = (Inner*)this->holder.obj;
            if (old != (Inner*)this->holder.prev) {
                if (old != 0) {
                    _InterlockedExchangeAdd(&old->refcount, 1);
                }
                Inner* prev = (Inner*)this->holder.prev;
                if (prev != 0) {
                    if (_InterlockedExchangeAdd(&prev->refcount, -1) == 1) {
                        void** vt = *(void***)prev;
                        void (*fn)(Inner*) = (void (*)(Inner*))vt[2];
                        fn(prev);
                    }
                }
                this->holder.prev = old;
            }
        }
    }
}
