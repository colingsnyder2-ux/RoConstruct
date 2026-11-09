// from server: 58% by atomic.potato
struct S {
    float v[6];
    void __cdecl f(float *out, const float *in);
};

void S::f(float *out, const float *in)
{
    out[0] = in[0];
    out[1] = in[1];
    out[2] = in[2];
    out[3] = in[3];
    out[4] = in[4];
    out[5] = in[5];
}
