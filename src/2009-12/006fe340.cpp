// from server: 100% by atomic.potato
struct RBX_VShirtGraphic_FactoryProduct {
    void dtor_body();
    void dtor_extra();
    void* field_0;
    void* field_4;
    char pad_8[0x10];
    void* field_18;
    void* field_1c;
    char pad_20[0x74];
    void* field_94;
    void* destroy(char flag);
};

extern "C" void __fastcall sub_637b00(void*);
extern "C" void __cdecl sub_7f385a(void*);

void* RBX_VShirtGraphic_FactoryProduct::destroy(char flag) {
    field_0 = (void*)0x9dd6a4;
    field_4 = (void*)0x9dd69c;
    field_18 = (void*)0x9dd690;
    field_1c = (void*)0x9dd688;
    field_94 = (void*)0x9dd680;
    sub_637b00(this);
    if (flag & 1) {
        sub_7f385a(this);
    }
    return this;
}
