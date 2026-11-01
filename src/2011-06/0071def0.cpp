// from server: 45% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

extern "C" void* __cdecl sub_640A80(void*);
extern "C" void __cdecl sub_80A058(void*);
extern "C" void __cdecl sub_80B0AC(void*, void*);
extern "C" void __cdecl sub_760C40(void*, void*);
extern "C" void __cdecl sub_760EF0(void*);
extern "C" void __cdecl sub_760880(void*);
extern "C" void __cdecl sub_73F730(void*, void*);
extern "C" void __cdecl sub_63F850(void*);
extern "C" void __cdecl sub_70DBD0(void*);
extern "C" void __cdecl sub_7BDF20(void*);
extern "C" void __cdecl sub_7C1FE0(void*);
extern "C" void __cdecl sub_40A950(void*);
extern "C" void __cdecl sub_A404C4(void*, const char*);

struct VAdvLuaDragger {
    char pad0[0x90];
    int state;
    char pad1[0x14];
    void* ptr_ac;
    void* ptr_b0;
    char pad2[4];
    void* ptr_b8;
    char pad3[0xc];
    void* ptr_c8;
    int mouseUp();
};

int VAdvLuaDragger::mouseUp() {
    if (state == 2) {
        void* local = 0;
        sub_73F730(&ptr_c8, &local);
        void* p = local;
        if (p != 0) {
            if (sub_640A80(p) != 0) {
                char buf[0x14];
                sub_63F850(buf);
                sub_760C40(&ptr_b8, buf);
                sub_70DBD0(buf);
            }
        }
        if (p != 0) {
            if (_InterlockedExchangeAdd((volatile long*)((char*)p + 4), -1) == 1) {
                void** vt = *(void***)p;
                ((void (__thiscall*)(void*))vt[1])(p);
                if (_InterlockedExchangeAdd((volatile long*)((char*)p + 8), -1) == 1) {
                    void** vt2 = *(void***)p;
                    ((void (__thiscall*)(void*))vt2[2])(p);
                }
            }
        }
        sub_760EF0(&ptr_b8);
        sub_760880(&ptr_b8);
        if (ptr_ac != 0) {
            sub_7BDF20(ptr_ac);
            sub_80A058(ptr_ac);
        }
        ptr_ac = 0;
        if (ptr_b0 != 0) {
            sub_7C1FE0(ptr_b0);
            sub_80A058(ptr_b0);
        }
        ptr_b0 = 0;
        state = 3;
        return 0;
    }
    if (state == 1) {
        state = 4;
        return 0;
    }
    char str[0x1c];
    sub_A404C4(str, "Call to AdvLuaDragger::mouseUp without mouseDown");
    sub_40A950(str);
    sub_80B0AC(str, str);
    return 0;
}
