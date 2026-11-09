// from server: 22% by atomic.potato
struct S {
    char pad0[8];
    int m8;
    char pad1[0x30 - 0xc];
    int m30;
    char pad2[0x38 - 0x34];
    float m38;
    float m3c;
    float m40;
    void f(float *out);
};

extern "C" int __cdecl sub_006e3250();
extern "C" void __cdecl sub_0052b0c0();

struct S2 {
    int f();
};

int S2::f()
{
    int *p = (int *)sub_006e3250();
    if (p)
        return p[0x168 / sizeof(int)];
    return 0;
}

struct S3 {
    int __cdecl f();
};

struct S4 {
    char pad[244];
    S3 *m_p;
    float * __cdecl f();
};

float *S4::f()
{
    return (float *)m_p->f();
}

extern float g_9aea18;
extern float g_b8013c;
extern float g_b80140;
extern float g_b80144;
extern float g_b80148;
extern float g_b8014c;
extern float g_b80150;
extern int g_b80154;

void S::f(float *out)
{
    int *a = (int *)m30;
    if (!a)
        goto fail;
    {
        int *edi = (int *)a[0x168 / 4];
        if (!edi[0xd0 / 4])
            goto fail;
        if (!m8)
            goto fail;
        {
            int *eax = (int *)((S2 *)m8)->f();
            if (!eax)
                goto fail;
            int ebx = ((S3 *)eax)->f();
            if (!ebx)
                goto fail;
            int eax2 = ((S3 *)edi)->f();
            if (ebx == eax2)
                goto fail;
            if (!edi[0xd0 / 4])
                goto fail;
            {
                int *ebx2 = (int *)((int *)m8)[0x240 / 4];
                float *eax3 = ((S4 *)edi)->f();
                float xmm5 = eax3[0x40 / 4];
                float xmm0 = eax3[0x44 / 4];
                float xmm3 = m3c - eax3[0x28 / 4];
                float xmm4 = m40 - eax3[0x2c / 4];
                float xmm2 = m38 - eax3[0x24 / 4];
                float xmm1 = xmm0 * xmm3;
                float xmm6 = xmm5 * xmm4 - xmm1;
                float xmm1b = eax3[0x3c / 4];
                float xmm0b = xmm0 * xmm2;
                float xmm7 = xmm1b;
                xmm1b = xmm1b * xmm3;
                float xmm3b = eax3[0x34 / 4];
                xmm5 = xmm5 * xmm2;
                float xmm2b = eax3[0x30 / 4];
                xmm7 = xmm7 * xmm4;
                float xmm4b = eax3[0x38 / 4];
                xmm1b = xmm1b - xmm5;
                xmm5 = eax3[0x40 / 4];
                xmm0b = xmm0b - xmm7;
                float xmm7b = (float)ebx2[0x30 / 4];
                xmm2b = xmm2b + xmm6;
                float xmm6b = eax3[0x44 / 4];
                xmm3b = xmm3b + xmm0b;
                float xmm0c = g_9aea18;
                xmm0c = xmm0c / xmm7b;
                xmm4b = xmm4b + xmm1b;
                float xmm1c = eax3[0x3c / 4];
                out[0] = xmm2b * xmm0c;
                out[1] = xmm3b * xmm0c;
                out[2] = xmm4b * xmm0c;
                out[3] = xmm1c * xmm0c;
                out[4] = xmm5 * xmm0c;
                out[5] = xmm6b * xmm0c;
                return;
            }
        }
    }
fail:
    if (!(g_b80154 & 1)) {
        g_b80154 |= 1;
        sub_0052b0c0();
    }
    out[0] = g_b8013c;
    out[1] = g_b80140;
    out[2] = g_b80144;
    out[3] = g_b80148;
    out[4] = g_b8014c;
    out[5] = g_b80150;
}
