// from server: 39% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct Inner {
    char pad0[8];
    volatile long refcount;
};

struct Holder {
    void* obj;
    void* prev;
};

struct Outer {
    void* field0;
    Holder holder;
    char pad[0x20];
    void* field2c;
    void* field30;
};

struct S {
    void* field0;
    Holder holder;
    void init(void* a, void* b);
};

void sub_659690(Holder* h, void* a, void* b);

void S::init(void* a, void* b)
{
    this->field0 = a;
    sub_659690(&this->holder, a, b);
    if (a == 0)
        return;
    Outer* o = (Outer*)((char*)a + 0x2c);
    if (o == 0)
        return;
    o->field2c = a;
    void* cur = this->holder.obj;
    if (cur == o->field30)
        return;
    if (cur != 0) {
        _InterlockedExchangeAdd(&((Inner*)((char*)cur + 8))->refcount, 1);
    }
    void* old = o->field30;
    if (old != 0) {
        if (_InterlockedExchangeAdd(&((Inner*)((char*)old + 8))->refcount, -1) == 1) {
            void** vt = *(void***)old;
            void (*fn)(void*) = (void (*)(void*))vt[2];
            fn(old);
        }
    }
    o->field30 = cur;
}
