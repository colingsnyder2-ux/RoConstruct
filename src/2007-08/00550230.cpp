// from server: 43% by colin
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

extern "C" void __stdcall sub_77E518();
extern "C" void* __cdecl sub_4621E0(void*, void*, void*);

struct S_func_00550230 {
    void* m_vtbl;
    char pad0[0x38];
    char m_3c;
    char pad1[0xb];
    char m_48;
    char pad2[3];
    int m_4c;
    int m_50;
    int m_54;
    int m_58;
    int m_5c;
    void f(void* a1, void* a2, void* a3);
};

struct S_helper_54F240 {
    void g(void* a1, void* a2, void* a3);
};

void S_func_00550230::f(void* a1, void* a2, void* a3)
{
    void* local;
    void* tmp;
    void* obj;

    sub_77E518();
    m_3c = 0;
    m_48 = 0;
    m_4c = 0;
    m_50 = 0;
    m_54 = 0;
    m_58 = 0;
    m_5c = 0x10;
    m_vtbl = (void*)0x7a7b0c;

    tmp = sub_4621E0(&local, a2, a3);
    ((S_helper_54F240*)this)->g(tmp, a2, a3);

    obj = local;
    if (obj != 0) {
        if (_InterlockedExchangeAdd((volatile long*)((char*)obj + 4), -1) == 1) {
            void** vt = *(void***)obj;
            ((void (__thiscall*)(void*))vt[1])(obj);
            if (_InterlockedExchangeAdd((volatile long*)((char*)obj + 8), -1) == 1) {
                void** vt2 = *(void***)obj;
                ((void (__thiscall*)(void*))vt2[2])(obj);
            }
        }
    }
}
