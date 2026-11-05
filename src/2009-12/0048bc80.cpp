// from server: 42% by atomic.potato
struct S
{
    static void f(float *begin, float *end, float *dst);
};

void S::f(float *begin, float *end, float *dst)
{
    while (begin != end)
    {
        dst[0] = begin[0];
        dst[1] = begin[1];
        dst[2] = begin[2];
        *(int *)(dst + 3) = *(int *)(begin + 3);
        begin += 4;
        dst += 4;
    }
}
