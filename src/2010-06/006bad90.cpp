// from server: 75% by atomic.potato
struct S
{
    int f(float *out, const float *value);
};

int S::f(float *out, const float *value)
{
    const float *p = value ? (const float *)((const char *)value - 0x1c) : 0;
    float *(*get)(const void *) = *(float *(*)(const void *))((char *)this + 8);
    const void *base = *(const void **)((char *)this + 0xc);
    float *result = get((const char *)base + (p ? (const char *)p - (const char *)0 : 0));

    out[0] = result[0];
    out[1] = result[1];
    out[2] = result[2];
    return (int)out;
}
