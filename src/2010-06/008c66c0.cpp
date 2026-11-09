// from server: 20% by atomic.potato
struct S {
    float v[64];
    void f(const float *p);
};

void S::f(const float *p)
{
    float *d = v + 64;
    d[0] = p[0];
    d[1] = p[1];
    d[2] = p[2];
    d[3] = p[3];
    d[4] = p[4];
    d[5] = p[5];
    d[6] = p[6];
    d[7] = p[7];
    d[8] = p[8];
    d[9] = p[9];
    d[10] = p[10];
    d[11] = p[11];
    d[12] = p[12];
    d[13] = p[13];
    d[14] = p[14];
    d[15] = p[15];
    d[16] = p[16];
    d[17] = p[17];
    d[20] = p[20];
    d[21] = p[21];
    d[22] = p[22];
}
