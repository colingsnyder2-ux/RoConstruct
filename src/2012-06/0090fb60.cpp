// from server: 29% by Intel
struct RBX__ParallelRampPoly {
    char gap0[0x18];
    void* field18;
    char gap1c[0x10];
    void* field2c;
    char gap30[0x4];
    void* field34;
    char gap38[0x4];
    void* field3c;

    void __thiscall func(void* out);
};

void __thiscall RBX__ParallelRampPoly::func(void* out) {
    void* v1 = field18;
    void* v2 = *(void**)((char*)v1 + 0xc);
    float* dst = (float*)out;
    dst[0] = 0.0f;
    dst[1] = 0.0f;
    dst[2] = 0.0f;
    void* v3 = *(void**)v2;
    if (v3) {
        float v4 = *(float*)((char*)v3 + 0x30);
        float v5 = *(float*)((char*)v3 + 0x34);
        float v6 = *(float*)((char*)v3 + 0x38);
        dst[0] = v4;
        dst[1] = v5;
        dst[2] = v6;
    }
}
