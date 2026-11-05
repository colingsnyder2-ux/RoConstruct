// from server: 30% by atomic.potato
struct P_func_006cbd20 { void g(); };

extern "C" int __cdecl sub_006997a0(void*);
extern "C" int __cdecl sub_006998b0(void*);
extern "C" void* __cdecl sub_006cbd20(void*);

struct S_006e39b0 {
    char pad0[0x19c];
    P_func_006cbd20* m_p;
    float m_a4;
    float m_a8;
    float m_ac;
    bool f(float* out);
};

bool S_006e39b0::f(float* out)
{
    if (m_p == 0)
        return false;
    if (sub_006997a0(this) == 0)
        return false;
    if (sub_006998b0(m_p) == 0)
        return false;
    float* m = (float*)sub_006cbd20(m_p);
    float x = m[0] * m_a4 + m[1] * m_a8 + m[2] * m_ac + m[9];
    float y = m[3] * m_a4 + m[4] * m_a8 + m[5] * m_ac + m[10];
    float z = m[6] * m_a4 + m[7] * m_a8 + m[8] * m_ac + m[11];
    out[0] = x;
    out[1] = y;
    out[2] = z;
    return true;
}
