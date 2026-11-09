// from server: 45% by colin
struct DxUserInput {
    char pad[0x3c];
    char field_3c;
    char pad2[0x10];
    char field_4d;
    char pad3[0x2];
    char field_4f;
    char pad4[0x114];
    void* field_164;
    void destroy();
};

extern "C" void __stdcall LeaveCriticalSection(void*);
extern "C" void __stdcall sub_41d870(void*);
extern "C" void __stdcall sub_464a20(void*);
extern "C" void __stdcall sub_463d30(void*);

void DxUserInput::destroy()
{
    char local8;
    char localc;
    void* local10;
    void* local18;

    sub_41d870(&local8);
    local18 = 0;
    if (field_3c) {
        sub_464a20(this);
    }
    if (field_164) {
        void** vtbl = *(void***)field_164;
        typedef void (__stdcall *Fn)(void*, unsigned int, char*);
        Fn fn = (Fn)vtbl[9];
        fn(field_164, 0x100, &field_4f);
    }
    if (field_4d) {
        sub_463d30(this);
    }
    if (localc) {
        LeaveCriticalSection(*(void**)&local8);
    }
}
