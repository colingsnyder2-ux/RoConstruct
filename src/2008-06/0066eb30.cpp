// from server: 100% by colin
struct S {
    float f0;
    float f4;
    float f8;
    float fC;
    float f10;
    float f14;
    S* init(const float* src);
};

extern float g_96f044;
extern float g_96f048;
extern float g_96f04c;
extern unsigned int g_96f050;

S* S::init(const float* src) {
    f0 = src[0];
    f4 = src[1];
    f8 = src[2];
    if (!(g_96f050 & 1)) {
        g_96f050 |= 1;
        g_96f044 = 0.0f;
        g_96f048 = 0.0f;
        g_96f04c = 0.0f;
    }
    fC = g_96f044;
    f10 = g_96f048;
    f14 = g_96f04c;
    return this;
}
