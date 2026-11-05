// roc 2012-06 006782a0  unit: DummyArbiter  size: 7 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 006782a0
//
// 006782a0  8b8184000000         mov eax, dword ptr [ecx + 0x84]
// 006782a6  c3                   ret 
// auto-matched from its assembly shape

struct S_func_006782a0 {
    char pad0[132];
    int m_x;
    int f();
};
int S_func_006782a0::f()
{
    return m_x;
}
