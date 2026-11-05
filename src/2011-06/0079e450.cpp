// from server: 22% by atomic.potato
struct HumanoidState {
    char pad[0x20];
    float scale;
    void normalize(float* v);
};

extern float g_a63b14;
extern float g_a7fb48;
extern float g_a9bdd0;
extern float g_a75b68;
extern float g_a75cec;

void HumanoidState::normalize(float* v)
{
    v[0] = v[0] / scale;
    v[1] = v[1] / scale;
    v[2] = v[2] / scale;
    v[3] = v[3] / scale;
    v[4] = v[4] / scale;

    float t = g_a63b14;
    float m0 = v[2];
    if (t <= m0) {
        t = m0;
    }

    float a = v[1] * g_a7fb48 + g_a9bdd0;
    float m1 = a;
    if (t <= m1) {
        m1 = t;
    }

    float b = v[3] * g_a7fb48 + g_a9bdd0;
    float m2 = b;
    if (m1 <= m2) {
        m2 = m1;
    }

    float c = (v[1] + g_a63b14) * g_a75b68;
    float m3 = c;
    if (m2 <= m3) {
        m3 = m2;
    }

    float d = (v[3] + g_a63b14) * g_a75b68;
    float m4 = d;
    if (m3 <= m4) {
        m4 = m3;
    }

    float e = scale * m4;
    float m5 = g_a75cec;
    if (e <= m5) {
        m5 = e;
    }

    v[0] = m5;
}
