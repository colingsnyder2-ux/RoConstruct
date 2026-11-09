// from server: 41% by colin
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct RefCounted {
    void AddRef();
    void Release();
};

struct CRobloxApp {
    void ExitInstance();
};

extern "C" void __cdecl sub_448570(void*);
extern "C" void __cdecl sub_54A950(void*);
extern "C" void __cdecl sub_54A040(void*);
extern "C" void __cdecl sub_56C3B0(void*);
extern "C" void __cdecl sub_56C0A0(void*, int, void*);
extern "C" void __cdecl sub_6307A2(void*);

extern char byte_8BBD51;
extern void* dword_8C98C0;
extern void* dword_7905D8;

void CRobloxApp::ExitInstance()
{
    void* p;
    sub_56C3B0(&p);
    void* q = *(void**)p;
    sub_56C0A0(q, 1, &dword_7905D8);

    RefCounted* r = (RefCounted*)p;
    if (r) {
        if (_InterlockedExchangeAdd((volatile long*)((char*)r + 4), -1) == 0) {
            (*(void (__thiscall**)(RefCounted*))(*(void***)r)[1])(r);
            if (_InterlockedExchangeAdd((volatile long*)((char*)r + 8), -1) == 0) {
                (*(void (__thiscall**)(RefCounted*))(*(void***)r)[2])(r);
            }
        }
    }

    sub_448570(&dword_8C98C0);

    if (byte_8BBD51) {
        void* s;
        sub_54A950(&s);
        sub_54A040(*(void**)s);

        RefCounted* t = (RefCounted*)s;
        if (t) {
            if (_InterlockedExchangeAdd((volatile long*)((char*)t + 4), -1) == 0) {
                (*(void (__thiscall**)(RefCounted*))(*(void***)t)[1])(t);
                if (_InterlockedExchangeAdd((volatile long*)((char*)t + 8), -1) == 0) {
                    (*(void (__thiscall**)(RefCounted*))(*(void***)t)[2])(t);
                }
            }
        }
    }

    sub_6307A2(this);
}
