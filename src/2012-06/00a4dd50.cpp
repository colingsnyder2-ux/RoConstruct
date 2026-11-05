// roc 2012-06 00a4dd50  unit: CXTPTabPaintManager  size: 7 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00a4dd50
//
// 00a4dd50  8b8104010000         mov eax, dword ptr [ecx + 0x104]
// 00a4dd56  c3                   ret 
// auto-matched from its assembly shape

struct S_func_00a4dd50 {
    char pad0[260];
    int m_x;
    int f();
};
int S_func_00a4dd50::f()
{
    return m_x;
}
