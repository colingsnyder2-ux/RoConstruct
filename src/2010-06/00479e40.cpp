// from server: 32% by atomic.potato
struct S
{
    int value;
};

struct F
{
};

void __cdecl f(float* out, const S* src)
{
    out[0] = 0.0f;
    out[1] = 0.0f;
    float v = (float)src->value;
    if (src->value == 0)
        out[0] = v;
    else
        out[1] = v;
}
