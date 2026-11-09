// roc 2012-06 00793390  unit: RBX::Profiling::Profiler  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00793390
//
// 00793390  8b818c000000         mov eax, dword ptr [ecx + 0x8c]
// 00793396  8b4014               mov eax, dword ptr [eax + 0x14]
// 00793399  c3                   ret 
// auto-matched from its assembly shape

struct I_func_00793390 {
    char pad[20];
    int m_x;
};
struct S_func_00793390 {
    char pad[140];
    I_func_00793390* m_p;
    int f();
};
int S_func_00793390::f()
{
    return m_p->m_x;
}
