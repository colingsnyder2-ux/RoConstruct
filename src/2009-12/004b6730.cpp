// from server: 25% by atomic.potato
struct RbxMaterialAdapter {
    char pad0[8];
    char pad1[0x98];
    char pad2[0xa0 - 0x98 - 8];
    void setMaterial(const char* name, float a, float b, float c, float d);
};

extern "C" {
    void __stdcall sub_4b3110();
    void __stdcall sub_4b63a0();
    void __stdcall sub_4b5190();
    void __stdcall sub_4ae910();
    void __stdcall sub_98b6e4();
    void __stdcall sub_98b620();
}

void RbxMaterialAdapter::setMaterial(const char* name, float a, float b, float c, float d) {
    float v[4];
    v[0] = a;
    v[1] = b;
    v[2] = c;
    v[3] = d;
    sub_4b3110();
    sub_4b63a0();
    sub_98b6e4();
    sub_98b6e4();
    sub_4b5190();
    sub_4ae910();
    sub_98b620();
    sub_98b6e4();
}
