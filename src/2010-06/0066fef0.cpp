// from server: 68% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

extern "C" int __stdcall MSVCR90_type_info_equals(void*, void*);

struct RefCounted {
    void* vptr;
    long refcount;
    long weakrefcount;
};

struct Holder {
    void* vptr;
    char pad[8];
    RefCounted* ptr;
};

struct TypeInfo {
    void* vptr;
};

struct Slot {
    void* vptr;
    char pad[4];
    RefCounted* ptr;
};

struct Result {
    void* vptr;
    char b4;
    char b5;
};

extern "C" void* __stdcall sub_9EA8D8(void*);

void __cdecl func(int op, void* dst, void* src)
{
    if (op == 0 || op == 1) {
        if (dst) {
            *(void**)dst = *(void**)src;
            *(void**)((char*)dst + 4) = *(void**)((char*)src + 4);
            *(void**)((char*)dst + 8) = *(void**)((char*)src + 8);
            RefCounted* p = *(RefCounted**)((char*)src + 12);
            *(RefCounted**)((char*)dst + 12) = p;
            if (p) {
                _InterlockedExchangeAdd(&p->refcount, 1);
            }
        }
        if (op == 1) {
            RefCounted* p = *(RefCounted**)((char*)src + 12);
            if (p) {
                if (_InterlockedExchangeAdd(&p->refcount, -1) == 1) {
                    ((void (__thiscall*)(RefCounted*))((void**)p->vptr)[1])(p);
                    if (_InterlockedExchangeAdd(&p->weakrefcount, -1) == 1) {
                        ((void (__thiscall*)(RefCounted*))((void**)p->vptr)[2])(p);
                    }
                }
            }
        }
        return;
    }
    if (op == 2) {
        RefCounted* p = *(RefCounted**)((char*)src + 12);
        if (p) {
            if (_InterlockedExchangeAdd(&p->refcount, -1) == 1) {
                ((void (__thiscall*)(RefCounted*))((void**)p->vptr)[1])(p);
                if (_InterlockedExchangeAdd(&p->weakrefcount, -1) == 1) {
                    ((void (__thiscall*)(RefCounted*))((void**)p->vptr)[2])(p);
                }
            }
        }
        return;
    }
    if (op == 3) {
        void* ti = (void*)0xbbfa58;
        int eq = MSVCR90_type_info_equals(*(void**)src, ti);
        *(int*)dst = eq ? *(int*)((char*)src + 4) : 0;
        return;
    }
    *(void**)dst = (void*)0xbbfa58;
    *(char*)((char*)dst + 4) = 0;
    *(char*)((char*)dst + 5) = 0;
}
