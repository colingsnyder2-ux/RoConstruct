// from server: 13% by atomic.potato
struct S {
    void f(float* out, const float* scale, const float* mat);
};

void S::f(float* out, const float* scale, const float* mat)
{
    float s0 = scale[0];
    float s1 = scale[1];
    float r0 = s0 * mat[0] + s1 * mat[4];
    float r1 = s0 * mat[1] + s1 * mat[5];
    out[0] = r0;
    out[1] = r1;
}
