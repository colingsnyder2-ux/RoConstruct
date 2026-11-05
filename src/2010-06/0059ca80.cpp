// from server: 35% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct Inner {
    char pad0[8];
    volatile long refcount;
    char pad1[4];
    void* ptr;
};

struct Outer {
    void* field0;
    Inner* field4;
};

struct PhysicsJob {
    void* field0;
    Inner* field4;
    PhysicsJob* construct(void* arg);
};

void __stdcall sub_59C6C0(Inner* p, void* arg);

PhysicsJob* PhysicsJob::construct(void* arg) {
    Inner* inner = (Inner*)arg;
    this->field0 = arg;
    sub_59C6C0((Inner*)&this->field4, arg);
    if (arg != 0) {
        Inner* p = (Inner*)((char*)arg + 8);
        if (p != 0) {
            p->ptr = arg;
            Inner* old = this->field4;
            if (old != p->ptr) {
                if (old != 0) {
                    _InterlockedExchangeAdd(&old->refcount, 1);
                }
                Inner* prev = (Inner*)p->ptr;
                if (prev != 0) {
                    if (_InterlockedExchangeAdd(&prev->refcount, -1) == 1) {
                        void** vt = *(void***)prev;
                        void (*fn)(Inner*) = (void (*)(Inner*))vt[2];
                        fn(prev);
                    }
                }
                p->ptr = old;
            }
        }
    }
    return this;
}
