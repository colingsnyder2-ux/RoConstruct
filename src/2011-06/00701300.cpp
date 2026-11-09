// from server: 20% by atomic.potato
struct RBX_BodyMover {
    char pad0[0xc4];
    float field_c4;
    float field_c8;
    void f(float* out, float a, float b, float c);
};

void RBX_BodyMover::f(float* out, float a, float b, float c) {
    float x = field_c4 * field_c8 + b * c;
    out[0] = a;
    out[1] = x - a;
    out[2] = x;
}
