// from server: 43% by atomic.potato
struct VTexture {
    char pad[0xd4];
    float field_d4;
    void setSomething(float value);
};

extern float g_9a6a88;
extern int g_b9211c;

void VTexture::setSomething(float value) {
    float current = field_d4;
    if (current == value) {
        return;
    }
    if (value > g_9a6a88) {
        field_d4 = value;
        g_b9211c = 0xb9211c;
        void (__stdcall *fn)(float) = (void (__stdcall *)(float))0x40c080;
        fn(value);
    }
}
