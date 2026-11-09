// from server: 50% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

extern "C" int __cdecl _type_info_equals(void*, void*);

struct VScriptContext {
    void* vptr;
    char pad[8];
    void* ref;
};

struct FactoryProduct {
    void* vptr;
    char pad[8];
    void* ref;
};

void __cdecl sub_637040(void* a, void* b, int c, void* d);

void __cdecl sub_637040(void* a, void* b, int c, void* d)
{
    void* p = *(void**)a;
    int off = *(int*)((char*)a + 4) + *(int*)((char*)a + 8);
    ((void (__cdecl*)(void*, int))p)(b, off);
}

void __cdecl sub_637050(void* self, void* src, int op, void* dst)
{
    int s = op;
    if (s == 0 || s == 1) {
        if (dst) {
            *(int*)((char*)dst + 0) = *(int*)((char*)src + 0);
            *(int*)((char*)dst + 4) = *(int*)((char*)src + 4);
            *(int*)((char*)dst + 8) = *(int*)((char*)src + 8);
            void* r = *(void**)((char*)src + 0xc);
            *(void**)((char*)dst + 0xc) = r;
            if (r) {
                _InterlockedExchangeAdd((volatile long*)((char*)r + 4), 1);
            }
        }
        if (s == 1) {
            void* r = *(void**)((char*)src + 0xc);
            if (r) {
                if (_InterlockedExchangeAdd((volatile long*)((char*)r + 4), -1) == 1) {
                    void** vt = *(void***)r;
                    ((void (__cdecl*)(void*))vt[1])(r);
                    if (_InterlockedExchangeAdd((volatile long*)((char*)r + 8), -1) == 1) {
                        void** vt2 = *(void***)r;
                        ((void (__cdecl*)(void*))vt2[2])(r);
                    }
                }
            }
        }
        return;
    }
    if (s == 2) {
        void* r = *(void**)((char*)src + 0xc);
        if (r) {
            if (_InterlockedExchangeAdd((volatile long*)((char*)r + 4), -1) == 1) {
                void** vt = *(void***)r;
                ((void (__cdecl*)(void*))vt[1])(r);
                if (_InterlockedExchangeAdd((volatile long*)((char*)r + 8), -1) == 1) {
                    void** vt2 = *(void***)r;
                    ((void (__cdecl*)(void*))vt2[2])(r);
                }
            }
        }
        return;
    }
    if (s == 3) {
        void* p = *(void**)src;
        int eq = _type_info_equals(p, (void*)0xa0cff0);
        int m = eq ? -1 : 0;
        *(int*)dst = m & (int)dst;
        return;
    }
    *(int*)dst = 0xa0cff0;
    *(char*)((char*)dst + 4) = 0;
    *(char*)((char*)dst + 5) = 0;
}
