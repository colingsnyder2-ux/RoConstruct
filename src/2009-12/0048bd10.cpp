// from server: 56% by atomic.potato
struct S
{
    static void f(float* begin, float* end, float* out);
};

void S::f(float* begin, float* end, float* out)
{
    while (begin != end)
    {
        *out = *begin;
        begin += 4;
        out += 4;
        out[-3] = begin[-3];
        out[-2] = begin[-2];
        out[-1] = begin[-1];
    }
}
