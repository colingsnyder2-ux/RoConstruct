// from server: 63% by atomic.potato
struct S_func_006390c0 {
    char pad0[164];
    int m_flag;
    char pad1[40];
    char m_str[32];
    S_func_006390c0* f(S_func_006390c0* other);
};

extern "C" void __stdcall sub_a404c8(char* dst, const char* src);
extern "C" void __stdcall sub_a404bc(char* dst);

S_func_006390c0* S_func_006390c0::f(S_func_006390c0* other)
{
    if (m_flag == 0) {
        sub_a404c8(other->m_str, m_str);
    } else {
        sub_a404bc(other->m_str);
    }
    return other;
}
