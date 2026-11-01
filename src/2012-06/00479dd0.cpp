// from server: 52% by Intel




struct CRobloxDHtmlDialog {
    int OnNavigateComplete(int* result, int a2, int a3);
};

extern "C" int __stdcall atoi(const char* str);
extern "C" void __stdcall InterlockedIncrement(int* addend);
extern "C" int __stdcall InterlockedDecrement(int* addend);
extern "C" int __stdcall VariantClear(void* pvarg);
extern "C" int __stdcall VariantChangeType(void* pvargDest, const void* pvargSrc, unsigned short wFlags, unsigned short vt);
extern "C" int __stdcall SysAllocString(const wchar_t* str);
extern "C" void __stdcall SysFreeString(int bstr);

int CRobloxDHtmlDialog::OnNavigateComplete(int* result, int a2, int a3) {
    int v18 = 0;
    int v14 = 0;
    int v1C = 0;

    *result = -1;

    InterlockedIncrement(&v18);

    int (__thiscall *func1)(CRobloxDHtmlDialog*, int, int*, int, int) = (int (__thiscall*)(CRobloxDHtmlDialog*, int, int*, int, int))0x982ee8;
    func1(this, 0x800113ed, &v1C, 0xB5B790, 1);

    int v18_ptr = (int)&v18;
    int hr = VariantChangeType((void*)0xB43BE8, (void*)v18_ptr, 0, 8);

    if (hr == 0) {
        int v18_val = *(int*)v18_ptr;
        int v14_val = atoi((const char*)v18_val);
        if (v14_val == 1) {
            int vtable = *(int*)this;
            int func_ptr = *(int*)(vtable + 0x160);
            ((void (__thiscall*)(CRobloxDHtmlDialog*))func_ptr)(this);
        } else {
            int vtable = *(int*)this;
            int func_ptr = *(int*)(vtable + 0x164);
            ((void (__thiscall*)(CRobloxDHtmlDialog*))func_ptr)(this);
        }
    }

    VariantClear((void*)&v18);
    return 0;
}
