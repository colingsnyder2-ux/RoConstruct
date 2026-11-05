// from server: 63% by atomic.potato
struct S_func_0071a1f0 {
    char pad0[0x94];
    int m_flag;
    char pad1[0xc0 - 0x98];
    char m_str[0x1c];
    S_func_0071a1f0* f(S_func_0071a1f0* other);
};

extern "C" void __stdcall sub_b22644(char* dst, char* src);
extern "C" void __stdcall sub_b22654(char* dst);

S_func_0071a1f0* S_func_0071a1f0::f(S_func_0071a1f0* other)
{
    if (m_flag == 0) {
        sub_b22644(other->m_str, m_str);
    } else {
        sub_b22654(other->m_str);
    }
    return other;
}
