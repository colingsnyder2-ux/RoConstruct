// roc 2012-06 00898d60  unit: CRobloxControlColorSelector  size: 7 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00898d60
//
// 00898d60  8b81a4000000         mov eax, dword ptr [ecx + 0xa4]
// 00898d66  c3                   ret 
// auto-matched from its assembly shape

struct S_func_00898d60 {
    char pad0[164];
    int m_x;
    int f();
};
int S_func_00898d60::f()
{
    return m_x;
}
