// from server: 87% by atomic.potato
struct S
{
    char padding[0x190];
    float x;
    float y;
    float z;
    void f(float *out);
};

void S::f(float *out)
{
    out[0] = x;
    out[1] = y;
    out[2] = z;
}
