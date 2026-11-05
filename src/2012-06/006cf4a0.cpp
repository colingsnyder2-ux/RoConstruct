// roc 2012-06 006cf4a0  unit: RBX::VServiceProvider::?$EventDesc  size: 7 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 006cf4a0
//
// 006cf4a0  8a81940b0000         mov al, byte ptr [ecx + 0xb94]
// 006cf4a6  c3                   ret 
// auto-matched from its assembly shape

struct S_func_006cf4a0 {
    char pad0[2964];
    char m_x;
    char f();
};
char S_func_006cf4a0::f()
{
    return m_x;
}
