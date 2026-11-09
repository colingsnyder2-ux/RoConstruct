// from server: 57% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct Descriptor {
    void* ptr;
    long refcount;
};

struct Holder {
    void* field0;
    long field4;
};

void __cdecl sub_6c0750(Holder* out, Descriptor** in);

void __cdecl sub_6c0750(Holder* out, Descriptor** in) {
    Descriptor* d = *in;
    void* p;
    if (d != 0) {
        p = (char*)d + 0x1c;
    } else {
        p = 0;
    }
    out->field0 = p;
    long rc = d->refcount;
    out->field4 = rc;
    if (rc != 0) {
        _InterlockedExchangeAdd((volatile long*)((char*)d + 0x1c + 4), 1);
    }
}
