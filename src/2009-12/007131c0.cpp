// from server: 73% by atomic.potato
struct S_func_007131c0 {
    char pad[228];
    unsigned char flag;
    char pad2[3];
    float a[3];
    float b[3];
    void f(float *out);
};

void S_func_007131c0::f(float *out)
{
    float *src = flag ? a : b;
    out[0] = src[0];
    out[1] = src[1];
    out[2] = src[2];
}
