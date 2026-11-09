// from server: 32% by atomic.potato
struct Vec3 { float x, y, z; };

struct Mat3 {
    float m[9];
};

struct Sub {
    char pad[0x24];
    float a, b, c;
};

struct Prim {
    char pad[0xf4];
    int field_f4;
    int getSub();
    void build(Mat3* out, const float* in);
};

extern "C" void __stdcall copy9(Mat3* dst, const void* src);

void Prim::build(Mat3* out, const float* in) {
    Sub* s = (Sub*)this->getSub();
    Mat3 tmp;
    copy9(&tmp, s);
    float v[6];
    v[0] = s->a;
    v[1] = s->b;
    v[2] = s->c;
    v[3] = in[0];
    v[4] = in[1];
    v[5] = in[2];
    float w[3];
    w[0] = in[3];
    w[1] = in[4];
    w[2] = in[5];
    (void)w;
    Mat3 result;
    copy9(&result, &tmp);
    *out = result;
}
