// from server: 100% by colin
extern "C" __declspec(dllimport) void __stdcall DeleteCriticalSection(void*);
extern "C" void __stdcall sub_4485C0(void*);
extern "C" void __cdecl sub_62FC62(void*);

struct CRobloxModule {
    int field0;
    void* field4;
    int field8;
    void* fieldC;
    char field10[0x18];
    void* field28;
    CRobloxModule* destroy(char);
};

CRobloxModule* CRobloxModule::destroy(char flag) {
    if (field4 != 0) {
        if (fieldC != 0) {
            sub_4485C0(&field4);
            fieldC = 0;
        }
        if (field28 != 0) {
            void* p = field28;
            void** vtbl = *(void***)p;
            void (__stdcall *fn)(void*) = (void (__stdcall *)(void*))vtbl[2];
            fn(p);
        }
        DeleteCriticalSection(&field10);
        field4 = 0;
    }
    if (flag & 1) {
        sub_62FC62(this);
    }
    return this;
}
