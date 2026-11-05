// from server: 21% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

extern "C" void __stdcall SetEvent(void*);

extern "C" void __cdecl func_00401610();
extern "C" void* __cdecl func_0040a2b0();
extern "C" void __cdecl func_0040ddc0(void*);
extern "C" void __cdecl func_0040de50(void*);
extern "C" void __cdecl func_00411500();
extern "C" void __cdecl func_006b6f40();
extern "C" void __cdecl func_006d7090();
extern "C" void __cdecl func_0080b15d();

struct CScriptEditor {
    void* field_0;
    void func_0048eb40(void* arg);
};

void CScriptEditor::func_0048eb40(void* arg)
{
    func_00401610();
    if (!(*(unsigned char*)0xcb4168 & 1)) {
        *(unsigned int*)0xcb4168 |= 1;
        *(unsigned int*)0xcb4160 = 0;
        *(unsigned int*)0xcb4164 = 0;
        func_0080b15d();
    }
    void* local14 = (void*)0xcb4160;
    char local18 = 0;
    func_00411500();
    void* local24 = 0;
    if (this->field_0 == 0) {
        if (arg != 0) {
            func_0040de50((char*)arg + 5);
        }
        this->field_0 = arg;
    } else {
        func_006d7090();
        local24 = 0;
        func_006b6f40();
        if (arg != 0) {
            func_0040de50((char*)arg + 5);
        }
        void* old = this->field_0;
        this->field_0 = arg;
        if (old != 0) {
            func_0040ddc0((char*)old + 5);
        }
    }
    if (local24 != 0) {
        func_0040ddc0((char*)local24 + 5);
    }
    if (local18 != 0) {
        long old = _InterlockedExchangeAdd((volatile long*)local14, (long)0x80000000);
        if (!(old & 0x40000000) && old > (long)0x80000000) {
            long bit = _InterlockedExchangeAdd((volatile long*)local14, 0);
            if (!(bit & 0x40000000)) {
                SetEvent(func_0040a2b0());
            }
        }
    }
}
