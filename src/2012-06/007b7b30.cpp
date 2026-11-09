// from server: 58% by atomic.potato
// roc 2012-06 007b7b30  unit: RBX::VFire::?$FactoryProduct  size: 57 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 007b7b30

struct S {
    char pad[0x88];
    float f88;
    float f8c;
    float f90;
    void f(float* out);
};

extern float g_bb9ad4;
extern float g_bb9ad8;

void S::f(float* out) {
    float a = f88;
    out[2] = f90;
    out[0] = a * g_bb9ad8;
    out[1] = f8c * g_bb9ad4;
}
