// from server: 27% by atomic.potato
struct TorsoBuilder {
    float field0;
    float field4;
    float field8;
    float fieldC;
    float field10;
    float field14;
    void update(float* a, float* b, float* c);
};

extern "C" void __fastcall normalize_vec(float* out, float* in, float len);
extern "C" float __cdecl sqrtf(float x);

void TorsoBuilder::update(float* a, float* b, float* c) {
    float zero = 0.0f;
    if (a[0] > zero) {
        a[0] = a[0] - field0;
    } else {
        a[0] = a[0] + field0;
    }
    if (a[1] > zero) {
        a[2] = field0 - a[2];
    } else {
        a[1] = a[1] + field0;
    }
    a[5] = c[1];
    a[4] = c[2];
    float* p = a + 3;
    float len = p[0]*p[0] + p[1]*p[1] + p[2]*p[2];
    len = sqrtf(len);
    normalize_vec(p, p, len);
}
