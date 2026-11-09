// from server: 62% by atomic.potato
extern "C" void* __cdecl sub_7F4CE6(void* dst, const void* src, unsigned int size);

struct MeshFaceKey {
    void* sub_578210(unsigned int a, unsigned int b);
};

void* MeshFaceKey::sub_578210(unsigned int a, unsigned int b) {
    unsigned int n = 0x38;
    if (a > 0x38) {
        n = a;
    }
    void* p = &n;
    if (a <= 0x38) {
        p = &a;
    }
    unsigned int sz = *(unsigned int*)p;
    return sub_7F4CE6(&b, (const void*)sz, sz);
}
