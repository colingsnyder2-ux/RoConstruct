// from server: 10% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

extern "C" void __cdecl func_6c86f0();
extern "C" void __cdecl func_74a260();
extern "C" void __cdecl func_74b1b0();

extern unsigned char byte_b9706d;
extern unsigned char byte_b97071;

struct RefCounted {
    void* vptr;
    long refcount;
    long refcount2;
};

struct S {
    void method(int a, int b, int c, int d);
};

void S::method(int a, int b, int c, int d)
{
    RefCounted* p = 0;
    int local = 0;
    unsigned char v1 = byte_b9706d;
    unsigned char v2 = byte_b97071;
    RefCounted* q = (RefCounted*)0;
    int flag = 1;
    void* vt = (void*)0x749d20;
    if (q) {
        _InterlockedExchangeAdd(&q->refcount, 1);
    }
    func_6c86f0();
    func_74a260();
    func_74b1b0();
    if (p) {
        void* vp = p->vptr;
        if (vp) {
            typedef void (__stdcall *Fn)(void*, int);
            ((Fn)(*(void**)((char*)vp + 0)))((char*)p + 0, 2);
        }
        p = 0;
    }
    if (q) {
        if (_InterlockedExchangeAdd(&q->refcount, -1) == 1) {
            typedef void (__stdcall *Fn)(void*);
            ((Fn)(*(void**)((char*)q->vptr + 4)))(q);
            if (_InterlockedExchangeAdd(&q->refcount2, -1) == 1) {
                ((Fn)(*(void**)((char*)q->vptr + 8)))(q);
            }
        }
    }
}
