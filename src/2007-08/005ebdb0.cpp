// from server: 25% by colin
struct RBX_BodyMover {
    char pad[0x18];
    float f18;
    float f1c;
    void sub_5e79a0(float, float, float, float, float, float);
    void func(float, float, float, float, float, float);
};

void RBX_BodyMover::func(float a, float b, float c, float d, float e, float f) {
    float x = f18 * a + d - e;
    float y = f1c * e + b - f;
    float z = c - d;
    sub_5e79a0(x, y, z, d, e, f);
}
