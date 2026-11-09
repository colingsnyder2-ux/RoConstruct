// from server: 28% by atomic.potato
struct M
{
    char pad0[0xc];
    float m0c;
    float m10;
    float m14;
    float m18;
    float m1c;
    float m20;
    float m24;
    float m28;
    float m2c;
    float m30;
    float m34;
    float m38;
    float m3c;
};

void __stdcall f(M* dst, const M* a, const M* b)
{
    M tmp;
    M* out;
    if (dst == a || dst == b)
        out = &tmp;
    else
        out = dst;

    out->m0c = a->m0c * b->m30 + a->m0c * b->m0c;
    out->m10 = a->m0c * b->m10 + a->m0c * b->m14 + a->m10 * b->m0c + a->m14 * b->m10;
    out->m14 = a->m0c * b->m14 + a->m0c * b->m18 + a->m10 * b->m10 + a->m14 * b->m14;
    out->m18 = a->m0c * b->m18 + a->m0c * b->m1c + a->m10 * b->m14 + a->m14 * b->m18;
    out->m1c = a->m0c * b->m1c + a->m0c * b->m20 + a->m10 * b->m18 + a->m14 * b->m1c;
    out->m20 = a->m0c * b->m20 + a->m0c * b->m24 + a->m10 * b->m1c + a->m14 * b->m20;
    out->m24 = a->m0c * b->m24 + a->m0c * b->m28 + a->m10 * b->m20 + a->m14 * b->m24;
    out->m28 = a->m0c * b->m28 + a->m0c * b->m2c + a->m10 * b->m24 + a->m14 * b->m28;
    out->m2c = a->m0c * b->m2c + a->m0c * b->m30 + a->m10 * b->m28 + a->m14 * b->m2c;
    out->m30 = a->m0c * b->m30 + a->m0c * b->m34 + a->m10 * b->m2c + a->m14 * b->m30;
    out->m34 = a->m0c * b->m34 + a->m0c * b->m38 + a->m10 * b->m30 + a->m14 * b->m34;
    out->m38 = a->m0c * b->m38 + a->m0c * b->m3c + a->m10 * b->m34 + a->m14 * b->m38;
    out->m3c = a->m0c * b->m3c + a->m0c * b->m0c + a->m10 * b->m38 + a->m14 * b->m3c;

    if (out != dst)
    {
        for (int i = 0; i < 16; ++i)
            ((float*)dst)[i] = ((float*)out)[i];
    }
}
