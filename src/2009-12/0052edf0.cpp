// from server: 89% by atomic.potato
extern "C" void* __stdcall sub_b20210(unsigned int);
extern "C" void __cdecl sub_7f4ce6(void*, void*, unsigned int);

struct S_func_0052edf0 {
    unsigned int m_size;
    char pad[8];
    void* m_ptr;
    void f(void** out);
};

void S_func_0052edf0::f(void** out)
{
    unsigned int n = (m_size + 7) >> 3;
    void* p = sub_b20210(n);
    *out = p;
    unsigned int n2 = (m_size + 7) >> 3;
    sub_7f4ce6(p, m_ptr, n2);
}
