// from server: 30% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

extern "C" void __stdcall SetEvent(void*);

extern "C" void __cdecl func_401610();
extern "C" void* __cdecl func_40a2b0();
extern "C" void __cdecl func_40ddc0(void*);
extern "C" void __cdecl func_40de50(void*);
extern "C" void __cdecl func_411500();
extern "C" void __cdecl func_6b6f40();
extern "C" void __cdecl func_6d7090();
extern "C" void __cdecl func_80b15d(void*);

struct S {
    void* field0;
    void func(void* arg);
};

void S::func(void* arg) {
    func_401610();
    if (!(*(volatile unsigned char*)0xccf3c8 & 1)) {
        *(volatile unsigned long*)0xccf3c8 |= 1;
        *(void**)0xccf3c0 = 0;
        *(void**)0xccf3c4 = 0;
        func_80b15d((void*)0xa3ba00);
    }
    void* local14 = (void*)0xccf3c0;
    char local18 = 0;
    func_411500();
    void* local24 = 0;
    if (this->field0 == 0) {
        void* edi = arg;
        if (edi != 0) {
            func_40de50((char*)edi + 5);
        }
        void* eax = this->field0;
        this->field0 = edi;
        (void)eax;
    } else {
        func_6d7090();
        local14 = 0;
        void* edi = arg;
        void* local0c = 0;
        func_6b6f40();
        if (edi != 0) {
            func_40de50((char*)edi + 5);
        }
        void* eax = this->field0;
        this->field0 = edi;
        if (eax != 0) {
            func_40ddc0((char*)eax + 5);
        }
        void* eax2 = local0c;
        local24 = 0;
        if (eax2 != 0) {
            func_40ddc0((char*)eax2 + 5);
        }
    }
    local24 = (void*)0xffffffff;
    if (local18 != 0) {
        volatile long* p = (volatile long*)local14;
        long old = _InterlockedExchangeAdd(p, (long)0x80000000);
        if (!(old & 0x40000000) && old > (long)0x80000000) {
            if (!(old & 0x40000000)) {
                void* h = func_40a2b0();
                SetEvent(h);
            }
        }
    }
}
