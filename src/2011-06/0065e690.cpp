// from server: 33% by atomic.potato
struct S {
    char pad0[8];
    char flag8;
    char pad9[0x30 - 9];
    float f30;
    float f34;
    float f38;
    char pad3c[0x9c - 0x3c];
    float f9c;
    float fa0;
    float fa4;
    float fa8;
    float fac;
    float fb0;
    void method(float* a, float* b);
};

extern "C" void __stdcall sub_79a3c0();

void S::method(float* a, float* b) {
    if (flag8) {
        sub_79a3c0();
    }
    f9c += a[0];
    fa0 += a[1];
    fa4 += a[2];
    float x = b[0] - f30;
    float y = b[1] - f34;
    float z = b[2] - f38;
    float a0 = a[0];
    float a1 = a[1];
    float a2 = a[2];
    fa8 += a2 * y - a1 * z;
    fac += a0 * z - a2 * x;
    fb0 += a1 * x - a0 * y;
}
