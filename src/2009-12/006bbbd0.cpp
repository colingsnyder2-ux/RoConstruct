// from server: 50% by atomic.potato
struct VTextureFactoryProduct {
    char pad[0xd0];
    float value;
    void setValue(float v);
};

extern float g_9a6a88;
extern void* g_b92140;

void VTextureFactoryProduct::setValue(float v) {
    float cur = value;
    if (!(cur == v)) {
        if (v > g_9a6a88) {
            value = v;
            g_b92140 = (void*)0xb92140;
            ((void (__stdcall*)(void*))0x40c080)(&g_b92140);
        }
    }
}
