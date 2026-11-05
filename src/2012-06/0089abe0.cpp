// from server: 46% by Intel
extern "C" void __stdcall sub_899b30(void* thisptr);
extern "C" void __stdcall sub_684840(void* thisptr, void* str);
extern "C" void __stdcall dword_b22648(void* thisptr);
extern "C" void __stdcall dword_b2263c(void* thisptr);

struct VCRenderSettingsItem___EnumPropDescriptor {
    void f();
};

void VCRenderSettingsItem___EnumPropDescriptor::f()
{
    sub_899b30(this);

    int* p = reinterpret_cast<int*>(this);
    p[0x84 / 4] = -1;
    p[0x88 / 4] = -1;
    p[0x8C / 4] = -1;
    p[0x90 / 4] = 0;

    float* pf = reinterpret_cast<float*>(p + 0x94 / 4);
    *pf = 0.0f;

    p[0x98 / 4] = 0;

    void* str_ptr = reinterpret_cast<char*>(this) + 0xC;
    sub_684840(str_ptr, (void*)0xB9BD1C);

    dword_b22648(this);

    dword_b2263c(str_ptr);

    int vtable1 = 0xBDBD24;
    int vtable2 = 0xBDBD18;
    int vtable3 = 0xBDBD0C;
    int vtable4 = 0xBDBD00;
    int vtable5 = 0xBDBD00 + 0xD4;

    p[0] = vtable1;
    p[1] = vtable2;
    p[0x18 / 4] = vtable3;
    p[0x1C / 4] = vtable4;
    p[0x80 / 4] = vtable5;

    p[0x9C / 4] = 1;
    p[0xA0 / 4] = 1;
    p[0xA4 / 4] = 2;
}
