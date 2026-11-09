// from server: 51% by atomic.potato
struct S_func_00784020 {
    char pad[4];
    int m_flag;
    void __cdecl f(float* out, float* a, float* b);
};

extern float g_vec[3];
extern int g_init;

extern "C" void __cdecl sub_00783100(void* self, float* a);
extern "C" bool __cdecl sub_00783920(void* self, float* a);
extern "C" void __cdecl sub_00783ac0(void* self, float* out, float* a);

void S_func_00784020::f(float* out, float* a, float* b)
{
    float tmp[3];
    tmp[0] = 0.0f;
    tmp[1] = 0.0f;
    tmp[2] = 0.0f;

    if (m_flag == 0)
    {
        if ((g_init & 1) == 0)
        {
            g_init |= 1;
            g_vec[0] = 0.0f;
            g_vec[1] = 0.0f;
            g_vec[2] = 0.0f;
        }
        out[0] = g_vec[0];
        out[1] = g_vec[1];
        out[2] = g_vec[2];
        return;
    }

    if ((g_init & 1) == 0)
    {
        g_init |= 1;
        g_vec[0] = 0.0f;
        g_vec[1] = 0.0f;
        g_vec[2] = 0.0f;
    }

    if (a[0] != g_vec[0] || a[1] != g_vec[1] || a[2] != g_vec[2])
    {
        sub_00783100(this, a);
        tmp[0] += a[0];
        tmp[1] += a[1];
        tmp[2] += a[2];
    }

    if (sub_00783920(this, b))
    {
        sub_00783ac0(this, tmp, b);
    }

    out[0] = tmp[0];
    out[1] = tmp[1];
    out[2] = tmp[2];
}
