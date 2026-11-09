// from server: 100% by tajop
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedIncrement(volatile long*);
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedIncrement)
#pragma intrinsic(_InterlockedDecrement)

struct Inner {
    virtual void unused0();
    virtual void dispose();
    virtual void destroy();
    long use_count;
    long weak_count;
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

void* __cdecl f(Holder* other, int flag) {
    if (flag == 0) {
        Holder* p = (Holder*)sub_62FEF6(0x18);
        if (p != 0) {
            p->a = other->a;
            p->b = other->b;
            p->c = other->c;
            Inner* in = other->inner;
            p->inner = in;
            if (in != 0) {
                _InterlockedIncrement(&in->use_count);
            }
            p->e = other->e;
            p->f = other->f;
        }
        return p;
    }
    Inner* in = other->inner;
    if (in != 0) {
        if (_InterlockedDecrement(&in->use_count) == 0) {
            in->dispose();
            if (_InterlockedDecrement(&in->weak_count) == 0) {
                in->destroy();
            }
        }
    }
    sub_62FC62(other);
    return 0;
}
