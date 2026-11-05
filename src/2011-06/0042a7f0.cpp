// from server: 42% by colin
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

extern "C" int __stdcall SetEvent(void*);

struct Inner {
    void* vtbl;
    long refcount;
    long flags;
};

struct Helper {
    void method();
};

extern "C" void __stdcall sub_7fc370(void*, void*);
extern "C" void* __stdcall sub_40a2b0();

struct CRobloxTreeCtrlNode {
    char pad[0x30];
    Inner* inner;
    char pad2[0x8];
    char field3c[0x8];
    void func(void* arg);
};

void CRobloxTreeCtrlNode::func(void* arg) {
    Inner* esi = this->inner;
    esi = (Inner*)((char*)esi + 0xb0);
    ((Helper*)esi)->method();

    sub_7fc370(&this->field3c, arg);

    if (_InterlockedExchangeAdd(&esi->refcount, -1) == 1) {
        long old = _InterlockedExchangeAdd(&esi->flags, (long)0x80000000);
        if ((old & 0x40000000) == 0 && old > (long)0x80000000) {
            long prev = _InterlockedExchangeAdd(&esi->flags, 0);
            if ((prev & 0x40000000) == 0) {
                SetEvent(sub_40a2b0());
            }
        }
    }

    Inner* ecx = this->inner;
    void** vt = (void**)ecx->vtbl;
    void (*fn)(void*) = (void (*)(void*))vt[0x15c / 4];
    fn(this);
}
