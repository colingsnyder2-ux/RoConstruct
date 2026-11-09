// from server: 24% by atomic.potato
struct S {
    char pad0[0x1c];
    char field1c[0xc8];
    float field_e4;
    void method(float);
};

extern float g_a126e4;
extern float g_a17ca4;
extern void* g_c04874;

void S::method(float arg) {
    float v = arg;
    if (g_a126e4 < v) {
        if (v < g_a17ca4) {
            v = v;
        }
    }
    if (v != field_e4) {
        void** vtbl = *(void***)g_c04874;
        void (*fn)(void*, float*) = (void (*)(void*, float*))vtbl[4];
        float tmp = v;
        fn((char*)this + 0x1c, &tmp);
    }
}
