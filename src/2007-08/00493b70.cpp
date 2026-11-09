// from server: 48% by colin
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct Sub {
    void sub_4927a0();
    void sub_493750();
};

struct Obj {
    void sub_5402b0();
    void sub_493b70();
};

extern "C" void __cdecl sub_62fc62(void*);

struct Notifier {
    void destroy();
};

void Notifier::destroy()
{
    *(int*)((char*)this + 0x00) = 0x79b954;
    *(int*)((char*)this + 0x04) = 0x79b948;
    *(int*)((char*)this + 0x10) = 0x79b940;
    *(int*)((char*)this + 0x14) = 0x79b930;
    *(int*)((char*)this + 0x2c) = 0x79b920;
    *(int*)((char*)this + 0x44) = 0x79b910;
    *(int*)((char*)this + 0x5c) = 0x79b900;
    *(int*)((char*)this + 0x74) = 0x79b8f0;
    *(int*)((char*)this + 0x8c) = 0x79b8e0;
    *(int*)((char*)this + 0xe8) = 0x79b8d0;
    *(int*)((char*)this + 0x100) = 0x79b8c0;
    *(int*)((char*)this + 0x118) = 0x79b8b4;

    int* p140 = *(int**)((char*)this + 0x140);
    if (p140 != 0) {
        int* p12c = *(int**)((char*)this + 0x12c);
        int* vt = *(int**)p140;
        void (__stdcall *fn)(int*) = *(void (__stdcall**)(int*))((char*)vt + 0xec);
        fn(p12c);
    }
    *(int*)((char*)this + 0x140) = 0;
    *(int*)((char*)this + 0x144) = 0;

    int* p13c = *(int**)((char*)this + 0x13c);
    if (p13c != 0) {
        if (_InterlockedExchangeAdd((volatile long*)((char*)p13c + 4), -1) == 1) {
            int* vt = *(int**)p13c;
            void (__stdcall *fn)(int*) = *(void (__stdcall**)(int*))((char*)vt + 4);
            fn(p13c);
            if (_InterlockedExchangeAdd((volatile long*)((char*)p13c + 8), -1) == 1) {
                int* vt2 = *(int**)p13c;
                void (__stdcall *fn2)(int*) = *(void (__stdcall**)(int*))((char*)vt2 + 8);
                fn2(p13c);
            }
        }
    }

    int* p134 = *(int**)((char*)this + 0x134);
    if (p134 != 0) {
        if (_InterlockedExchangeAdd((volatile long*)((char*)p134 + 4), -1) == 1) {
            int* vt = *(int**)p134;
            void (__stdcall *fn)(int*) = *(void (__stdcall**)(int*))((char*)vt + 4);
            fn(p134);
            if (_InterlockedExchangeAdd((volatile long*)((char*)p134 + 8), -1) == 1) {
                int* vt2 = *(int**)p134;
                void (__stdcall *fn2)(int*) = *(void (__stdcall**)(int*))((char*)vt2 + 8);
                fn2(p134);
            }
        }
    }

    int* p12c = *(int**)((char*)this + 0x12c);
    if (p12c != 0) {
        int* vt = *(int**)p12c;
        void (__stdcall *fn)(int*) = *(void (__stdcall**)(int*))((char*)vt);
        fn((int*)1);
    }

    Sub* p120 = (Sub*)((char*)this + 0x120);
    p120->sub_493750();
    sub_62fc62(*(void**)((char*)this + 0x124));
    *(int*)((char*)this + 0x124) = 0;

    int* p11c = *(int**)((char*)this + 0x11c);
    if (p11c != 0) {
        ((Sub*)p11c)->sub_4927a0();
        sub_62fc62(p11c);
    }

    *(int*)((char*)this + 0x118) = 0x79b72c;
    *(int*)((char*)this + 0x100) = 0x79b8a4;

    void* p108 = *(void**)((char*)this + 0x108);
    if (p108 != 0) {
        sub_62fc62(p108);
    }
    *(int*)((char*)this + 0x108) = 0;
    *(int*)((char*)this + 0x10c) = 0;
    *(int*)((char*)this + 0x110) = 0;

    *(int*)((char*)this + 0xe8) = 0x79b894;

    void* pf0 = *(void**)((char*)this + 0xf0);
    if (pf0 != 0) {
        sub_62fc62(pf0);
    }
    *(int*)((char*)this + 0xf0) = 0;
    *(int*)((char*)this + 0xf4) = 0;
    *(int*)((char*)this + 0xf8) = 0;

    ((Obj*)this)->sub_5402b0();
}
