// from server: 75% by atomic.potato
struct S
{
    void f(float *out, float *value);
    void *data;
};

void S::f(float *out, float *value)
{
    float *p = value ? value - 7 : 0;
    float *q = (float *)data + (int)p;
    out[0] = q[0];
    out[1] = q[1];
    out[2] = q[2];
}
