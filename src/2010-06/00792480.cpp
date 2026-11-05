// from server: 25% by atomic.potato
struct S {
    char pad0[4];
    float f4;
    float f8;
    float fC;
    float f10;
    float f14;
    float f18;
    void method(float* out, float angle);
};

extern double g_const;
extern "C" double sin(double);
extern "C" double cos(double);

void S::method(float* out, float angle) {
    float a = angle + angle;
    a = (float)(a * g_const);
    float s = (float)sin(a);
    float c = (float)cos(a);
    float x = f10 * s - f4 * c;
    float y = f14 * s - f8 * c;
    float z = f18 * s - fC * c;
    out[0] = x;
    out[1] = y;
    out[2] = z;
}
