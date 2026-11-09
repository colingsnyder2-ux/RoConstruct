// from server: 26% by atomic.potato
struct S
{
    char pad0[8];
    void *p8;
    char padc[0x4d - 0xc];
    unsigned char flag4d;
    char pad4e[2];
    void f(int count, float *in, int a, int b);
};

extern "C" void *__cdecl sub_7f4a40(int size);

void S::f(int count, float *in, int a, int b)
{
    if (flag4d == 0)
        return;

    float *buf = (float *)sub_7f4a40(count * 12);

    float sign = *(float *)0x9b1610;
    float zero = 0.0f;

    int i = 0;
    if (count >= 4)
    {
        int n = ((count - 4) >> 2) + 1;
        float *src = in + 2;
        float *dst = buf;
        for (int k = 0; k < n; k++)
        {
            int t;
            dst[0] = src[-2];
            t = *(int *)&src[-1] ^ *(int *)&sign;
            dst[1] = *(float *)&t;
            dst[2] = zero;
            dst[3] = src[0];
            t = *(int *)&src[1] ^ *(int *)&sign;
            dst[4] = *(float *)&t;
            dst[5] = zero;
            dst[6] = src[2];
            t = *(int *)&src[3] ^ *(int *)&sign;
            dst[7] = *(float *)&t;
            dst[8] = zero;
            dst[9] = src[4];
            t = *(int *)&src[5] ^ *(int *)&sign;
            dst[10] = *(float *)&t;
            dst[11] = zero;
            dst += 12;
            src += 8;
        }
        i = n * 4;
    }
    for (; i < count; i++)
    {
        int t;
        buf[i * 3 + 0] = in[i * 2 + 0];
        t = *(int *)&in[i * 2 + 1] ^ *(int *)&sign;
        buf[i * 3 + 1] = *(float *)&t;
        buf[i * 3 + 2] = zero;
    }

    void **vt = *(void ***)p8;
    void (*fn1)(void *, void *) = (void (*)(void *, void *))vt[0x3c / 4];
    fn1(p8, (char *)this + 0xc);

    void **vt2 = *(void ***)p8;
    void (*fn2)(void *, float *, int, int) = (void (*)(void *, float *, int, int))vt2[0x64 / 4];
    fn2(p8, buf, count, b);
}
