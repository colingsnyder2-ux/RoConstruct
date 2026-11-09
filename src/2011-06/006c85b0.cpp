// from server: 47% by atomic.potato
extern "C" int __cdecl sub_005d0750();

struct S_func_006c85b0 {
    char pad0[36];
    int m_value;
};

S_func_006c85b0* __stdcall S_func_006c85b0_func(S_func_006c85b0* p, int a, int b, int c, int d, int e, int f)
{
    int x;
    x = sub_005d0750();
    p->m_value = x;
    return p;
}
