// from server: 100% by atomic.potato
struct S
{
    char pad[60];
    float a;
    float b;
    float c;
    float d;
    void f(float *out);
};

void S::f(float *out)
{
    out[0] = a;
    out[1] = b;
    out[2] = c;
    out[3] = d;
}
