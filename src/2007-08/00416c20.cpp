// from server: 83% by TrollStein
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct Inner {
    void* vfptr;
    long refcount;
    long refcount2;
};

struct Holder {
    int a;
    int b;
    int c;
    Inner* inner;
    int e;
    int f;
};

extern "C" void* __cdecl sub_62FEF6(unsigned int);
extern "C" void __cdecl sub_62FC62(void*);

struct S {
};

void* __cdecl f(Holder* other, int flag) {
    if (flag == 0) {
        Holder* p = (Holder*)sub_62FEF6(0x18);
        if (p == 0) {
            return 0;
        }
        p->a = other->a;
        p->b = other->b;
        p->c = other->c;
        Inner* in = other->inner;
        p->inner = in;
        if (in != 0) {
            _InterlockedExchangeAdd(&in->refcount, 1);
        }
        p->e = other->e;
        p->f = other->f;
        return p;
    } else {
        Inner* in = other->inner;
        if (in != 0) {
            if (_InterlockedExchangeAdd(&in->refcount, -1) == 1) {
                void** vt = (void**)in->vfptr;
                void (__thiscall *fn)(Inner*) = (void (__thiscall *)(Inner*))vt[1];
                fn(in);
                if (_InterlockedExchangeAdd(&in->refcount2, -1) == 1) {
                    void** vt2 = (void**)in->vfptr;
                    void (__thiscall *fn2)(Inner*) = (void (__thiscall *)(Inner*))vt2[2];
                    fn2(in);
                }
            }
        }
        sub_62FC62(other);
        return 0;
    }
}
