// from server: 43% by tester
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct Inner {
    void* vptr;
    long refcount;
    long weakrefcount;
};

struct Outer {
    void* vptr;
    void* unknown;
    Inner* inner;
    void* owner;
    void dtor();
};

extern void __cdecl sub_437b80(void*);

void Outer::dtor()
{
    this->vptr = (void*)0x794b94;
    if (this->owner != 0) {
        sub_437b80(this);
    }
    Inner* p = this->inner;
    if (p != 0) {
        if (_InterlockedExchangeAdd((volatile long*)((char*)p + 4), -1) == 1) {
            void (__thiscall *f1)(Inner*) = *(void (__thiscall **)(Inner*))((char*)p->vptr + 4);
            f1(p);
            if (_InterlockedExchangeAdd((volatile long*)((char*)p + 8), -1) == 1) {
                void (__thiscall *f2)(Inner*) = *(void (__thiscall **)(Inner*))((char*)p->vptr + 8);
                f2(p);
            }
        }
    }
    this->vptr = (void*)0x787f68;
}
