// from server: 28% by atomic.potato
struct VCRenderSettingsItem_EnumPropDescriptor {
    char pad0[0xe4];
    char field_e4[0x24];
    float f24;
    float f28;
    float f2c;
    void sub_6ddae0();
    void assign(const VCRenderSettingsItem_EnumPropDescriptor* src);
};

void VCRenderSettingsItem_EnumPropDescriptor::assign(const VCRenderSettingsItem_EnumPropDescriptor* src) {
    char* dst = (char*)this + 0xe4;
    const char* s = (const char*)src;
    int i;
    for (i = 0; i < 9; i++) {
        ((int*)dst)[i] = ((const int*)s)[i];
    }
    *(float*)(dst + 0x24) = *(const float*)(s + 0x24);
    *(float*)(dst + 0x28) = *(const float*)(s + 0x28);
    *(float*)(dst + 0x2c) = *(const float*)(s + 0x2c);
    sub_6ddae0();
}
