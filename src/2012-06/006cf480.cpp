// roc 2012-06 006cf480  unit: RBX::VServiceProvider::?$EventDesc  size: 7 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 006cf480
//
// 006cf480  8b81d00c0000         mov eax, dword ptr [ecx + 0xcd0]
// 006cf486  c3                   ret 
// auto-matched from its assembly shape

struct S_func_006cf480 {
    char pad0[3280];
    int m_x;
    int f();
};
int S_func_006cf480::f()
{
    return m_x;
}
