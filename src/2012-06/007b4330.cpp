// roc 2012-06 007b4330  unit: RBX::MeshContentProvider  size: 7 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 007b4330
//
// 007b4330  8b81c8020000         mov eax, dword ptr [ecx + 0x2c8]
// 007b4336  c3                   ret 
// auto-matched from its assembly shape

struct S_func_007b4330 {
    char pad0[712];
    int m_x;
    int f();
};
int S_func_007b4330::f()
{
    return m_x;
}
