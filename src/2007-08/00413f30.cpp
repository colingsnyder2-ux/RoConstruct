// from server: 44% by colin
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct Inner {
    void** vtbl;
    int ref;
    int ref2;
};

struct S {
    int a;
    Inner* p;
    char buf[0x24];
    S* ctor(int, Inner*, void*);
};

extern "C" void __cdecl sub_56CEF0(void*, void*);
extern "C" void __cdecl sub_56CE80(void*);

S* S::ctor(int a, Inner* p, void* extra)
{
    this->a = a;
    this->p = p;
    if (p) {
        _InterlockedExchangeAdd((volatile long*)&p->ref, 1);
    }
    sub_56CEF0(&this->buf[0], extra);
    if (p) {
        if (_InterlockedExchangeAdd((volatile long*)&p->ref, -1) == 1) {
            ((void (__thiscall*)(Inner*))p->vtbl[1])(p);
            if (_InterlockedExchangeAdd((volatile long*)&p->ref2, -1) == 1) {
                ((void (__thiscall*)(Inner*))p->vtbl[2])(p);
            }
        }
    }
    sub_56CE80(&this->buf[0]);
    return this;
}
