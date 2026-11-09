// from server: 37% by Intel
extern "C" {
    void __stdcall _invalid_parameter_noinfo();
    int __stdcall SendMessageA(void*, unsigned int, unsigned int, long);
}

struct CDeclarationView {
    void* vtable;
    char pad_4[0x20 - 4];
    void* m_handle;
    char pad_24[0xac - 0x24];
    void* m_item;
    char pad_ac[0xf0 - 0xac];

    void sub_436330();
};

struct ItemData {
    int field_0;
    int field_4;
    int field_8;
    int field_c;
};

void* __stdcall sub_4345F0();
void __stdcall sub_4360A0();
void __stdcall sub_725750();
void __stdcall sub_725770();

void CDeclarationView::sub_436330()
{
    void* v1 = sub_4345F0();
    SendMessageA(m_handle, 0x1101, 0, 0xffff0000);
    m_item = v1;
    sub_725750();
    ItemData* v2 = (ItemData*)((char*)v1 + 0x10);
    int v3 = v2->field_4;
    int v4 = v2->field_8;
    if (v2->field_4 <= v3) {
        _invalid_parameter_noinfo();
    }
    if (v4 <= v2->field_4) {
        _invalid_parameter_noinfo();
    }
    int v5 = v2->field_4;
    int v6 = v2->field_8;
    int v7 = v2->field_c;
    sub_4360A0();
    SendMessageA(m_handle, 0x1115, 0, (long)&v7);
    sub_725770();
}
