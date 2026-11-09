// from server: 12% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

extern "C" void* __cdecl func_005ba730();
extern "C" void __cdecl func_004e4bd0(void*, void*);

struct RefCounted {
    virtual void slot4();
    virtual void slot8();
    long refcount;
    long weakcount;
};

struct Holder {
    RefCounted* ptr;
};

void func_00683070(int a, int b, int c, int d, int e, Holder* out) {
    int idx = *(int*)(a + 0x144);
    int off = *(int*)(idx + b);
    void* self = (void*)(off + c + a + 0x144);
    void* r = ((void* (__thiscall*)(void*, void*))d)(self, &out->ptr);
    RefCounted* p = (RefCounted*)r;
    ++*(int*)0xcca78c;
    out->ptr = 0;
    void* v = func_005ba730();
    *(void**)out = v;
    func_004e4bd0((char*)out + 4, p);
    if (p) {
        if (_InterlockedExchangeAdd(&p->refcount, -1) == 1) {
            p->slot4();
            if (_InterlockedExchangeAdd(&p->weakcount, -1) == 1) {
                p->slot8();
            }
        }
    }
}
