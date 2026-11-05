// from server: 34% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" unsigned char __cdecl _interlockedbittestandset(volatile long*, long);
#pragma intrinsic(_interlockedbittestandset)

extern "C" void __stdcall SetEvent(void*);
extern "C" void __cdecl _invalid_parameter_noinfo();

struct RefCounted {
    long refcount;
    char pad1[4];
    volatile long flags;
    void AddRef();
    void Release();
};

struct Obj {
    char pad0[0x10];
    RefCounted rc;
    char pad2[0x0c];
    void* ptr18;
    void* ptr1c;
};

struct Adapter {
    char pad0[0x20];
    Obj* obj;
    void* get();
    void* make(float*);
};

extern "C" void* __cdecl sub_401630(void*, void*);
extern "C" void* __cdecl sub_5d4cc0();
extern "C" void __cdecl sub_418890(void*);
extern "C" void __cdecl sub_5cfb10(void*, void*, float*);
extern "C" void* __cdecl sub_7f3860(unsigned int);
extern "C" void* __cdecl sub_5e5070(void*, void*, float*);
extern "C" void* __cdecl sub_5d1dc0(void*, float*);
extern "C" void* __cdecl sub_4e5ff0(void*, void*);
extern "C" void* __cdecl sub_4109e0();

extern void* g_98b760;
extern void* g_98b228;

void* Adapter::make(float* p) {
    sub_401630(&g_98b760, (void*)0x5d4d20);
    Obj* o = (Obj*)sub_5d4cc0();
    RefCounted* rc = &o->rc;
    sub_418890(rc);
    float v[3];
    v[0] = p[0];
    v[1] = p[1];
    v[2] = p[2];
    void* a = 0;
    sub_5cfb10((char*)o + 0x20, &a, v);
    void* eax = *(void**)((char*)o + 0x38);
    void* ebx = a;
    void* edi_val = *(void**)((char*)o + 0x20);
    if (ebx != 0 && ebx != edi_val) {
        ((void (__stdcall*)())g_98b760)();
    }
    if (a == eax) {
        void* mem = sub_7f3860(0x8c);
        void* result;
        if (mem != 0) {
            result = sub_5e5070(mem, a, p);
        } else {
            result = 0;
        }
        void* tmp = sub_5d1dc0((char*)o + 0x20, v);
        sub_4e5ff0(tmp, result);
        if (_InterlockedExchangeAdd(&rc->refcount, -1) == 1) {
            *(void**)&rc->pad1[0] = 0;
            long old = _InterlockedExchangeAdd(&rc->flags, 0x80000000);
            if ((old & 0x40000000) == 0 && old > (long)0x80000000) {
                if (!_interlockedbittestandset((volatile long*)&rc->flags, 0x1e)) {
                    void* ev = sub_4109e0();
                    ((void (__stdcall*)(void*))g_98b228)(ev);
                }
            }
        }
        return result;
    } else {
        if (ebx == 0) {
            ((void (__stdcall*)())g_98b760)();
            if (a == *(void**)((char*)ebx + 0x18)) {
                ((void (__stdcall*)())g_98b760)();
            }
            void* edi2 = *(void**)((char*)a + 0x1c);
            if (_InterlockedExchangeAdd(&rc->refcount, -1) == 1) {
                *(void**)&rc->pad1[0] = 0;
                long old = _InterlockedExchangeAdd(&rc->flags, 0x80000000);
                if ((old & 0x40000000) == 0 && old > (long)0x80000000) {
                    if (!_interlockedbittestandset((volatile long*)&rc->flags, 0x1e)) {
                        void* ev = sub_4109e0();
                        ((void (__stdcall*)(void*))g_98b228)(ev);
                    }
                }
            }
            return edi2;
        } else {
            ebx = *(void**)ebx;
            goto retry;
        }
    }
retry:
    return 0;
}
