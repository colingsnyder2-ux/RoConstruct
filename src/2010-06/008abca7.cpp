// from server: 42% by atomic.potato
struct S {
    void f(float* out, float angle);
};

void S::f(float* out, float angle) {
    float s, c;
    float* ps = &s;
    float* pc = &c;
    *pc = 0.0f;
    *ps = 0.0f;
    float sn = 0.0f;
    float cs = 0.0f;
    out[0] = cs;
    out[1] = 0.0f;
    out[2] = -sn;
    out[3] = 0.0f;
    out[4] = 0.0f;
    out[5] = 1.0f;
    out[6] = 0.0f;
    out[7] = 0.0f;
    out[8] = cs;
    out[9] = 0.0f;
    out[10] = 0.0f;
    out[11] = 0.0f;
    out[12] = 0.0f;
    out[13] = 0.0f;
    out[14] = 0.0f;
    out[15] = 1.0f;
}
