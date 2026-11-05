// roc 2012-06 007b9520  unit: RBX::Geometry  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 007b9520
//
// 007b9520  8b8104010000         mov eax, dword ptr [ecx + 0x104]
// 007b9526  83c004               add eax, 4
// 007b9529  c3                   ret 
// auto-matched from its assembly shape

struct S_func_007b9520 {
    char pad0[260];
    int m_x;
    int f();
};
int S_func_007b9520::f()
{
    return m_x + 4;
}
