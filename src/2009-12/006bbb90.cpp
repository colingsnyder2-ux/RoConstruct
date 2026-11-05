// from server: 46% by atomic.potato
struct VTexture {
    char pad[0xcc];
    float field_cc;
    void setSomething(float value);
};

extern float g_9a6a88;
extern char g_b920fc;

void VTexture::setSomething(float value) {
    if (field_cc == value) {
        return;
    }
    if (value > g_9a6a88) {
        field_cc = value;
        g_b920fc = 0;
        // tail call to 0x40c080
        extern void __stdcall func_40c080();
        func_40c080();
    }
}
