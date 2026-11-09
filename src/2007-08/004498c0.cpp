// from server: 54% by tester
// roc 2007-08 004498c0  unit: CRobloxModule  size: 247 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004498c0

struct CRobloxModule {
    char pad0[0x88];
    int (__thiscall *vtbl_88)(CRobloxModule*, int, int);
    int field_8c;
    int field_90;
    int method();
};

extern "C" void __cdecl sub_448C10();
extern "C" void __cdecl sub_630B9E(void*, void*);
extern "C" void* __stdcall sub_77E698(const char*);
extern "C" void __cdecl sub_412DC0(void*, const char*);

extern "C" void* g_8bbe94;

int CRobloxModule::method()
{
    if (field_90 != 0)
        return 0;

    void* p = g_8bbe94;
    g_8bbe94 = 0;
    if (p != 0) {
        void** vt = *(void***)p;
        void (__thiscall *fn)(void*, int) = (void (__thiscall *)(void*, int))vt[0];
        fn(p, 1);
    }

    int saved = field_8c;
    int (__thiscall *fn2)(CRobloxModule*, int, int) = vtbl_88;
    int result = fn2(this, 0, 1);

    sub_448C10();

    if (result == 0) {
        if (saved != field_8c) {
            sub_77E698("OpenDocumentFile returned NULL - a");
            char buf[0x28];
            sub_412DC0(buf, "OpenDocumentFile returned NULL - a");
            sub_630B9E(buf, (void*)0x8410C0);
        }
        sub_77E698("OpenDocumentFile returned NULL - b");
        char buf2[0x28];
        sub_412DC0(buf2, "OpenDocumentFile returned NULL - b");
        sub_630B9E(buf2, (void*)0x8410C0);
    }

    return result;
}
