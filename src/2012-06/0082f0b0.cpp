// from server: 37% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

extern "C" void __cdecl func_00972290(int, const char*);
extern "C" void* __cdecl func_00722e80(void*);
extern "C" void __cdecl func_00439330(void*, void*);
extern "C" char __cdecl func_00751220(void*, void*);
extern "C" void __cdecl func_008e2eb0(void*, void*);

struct S_func_0082f0b0 {
    void* __cdecl f(void* a);
};

void* S_func_0082f0b0::f(void* a)
{
    char* p = (char*)a;
    if (*(char*)0xe580b3 != 0 && *(void**)(p + 4) != 0) {
        void* (__cdecl *g)(const char*, const char*, int) = *(void*(__cdecl**)(const char*, const char*, int))0xe5809c;
        if (g != 0) {
            if (g((const char*)0xbca764, (const char*)0xbcfdf8, 0x3b))
                goto skip;
        }
        func_00972290(*(unsigned char*)0xe580b3, (const char*)0xbcff58);
    }
skip:
    void* result = 0;
    char* base = *(char**)(p + 4);
    int count = (int)((*(char**)(p + 8) - base) >> 3);
    if (count > 0) {
        int i = 0;
        do {
            void* tmp1 = 0;
            void* tmp2 = 0;
            func_00439330(base + i * 8, &tmp1);
            void* obj = tmp1;
            void* ref = tmp2;
            if (func_00751220(obj, ref)) {
                void* v = *(void**)((char*)obj + 0x198);
                func_008e2eb0(*(void**)(p + 0x30), &v);
                if (result == 0) {
                    result = func_00722e80(obj);
                }
                if (*(char*)0xe580b3 != 0 && result == 0) {
                    void* (__cdecl *g)(const char*, const char*, int) = *(void*(__cdecl**)(const char*, const char*, int))0xe5809c;
                    if (g != 0) {
                        if (g((const char*)0xb8f848, (const char*)0xbcfdf8, 0x43))
                            goto after;
                    }
                    func_00972290(*(unsigned char*)0xe580b3, (const char*)0xbcfef0);
                }
            }
after:
            if (ref != 0) {
                if (_InterlockedExchangeAdd((volatile long*)((char*)ref + 4), -1) == 1) {
                    void* vt = *(void**)ref;
                    (*(void(__thiscall**)(void*))(*(char**)vt + 4))(ref);
                    if (_InterlockedExchangeAdd((volatile long*)((char*)ref + 8), -1) == 1) {
                        void* vt2 = *(void**)ref;
                        (*(void(__thiscall**)(void*))(*(char**)vt2 + 8))(ref);
                    }
                }
            }
            base = *(char**)(p + 4);
            i++;
            count = (int)((*(char**)(p + 8) - base) >> 3);
        } while (i < count);
    }
    return result;
}
