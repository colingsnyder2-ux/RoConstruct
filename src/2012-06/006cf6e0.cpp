// roc 2012-06 006cf6e0  unit: boost::io::too_many_args  size: 7 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 006cf6e0
//
// 006cf6e0  8a81740c0000         mov al, byte ptr [ecx + 0xc74]
// 006cf6e6  c3                   ret 
// auto-matched from its assembly shape

struct S_func_006cf6e0 {
    char pad0[3188];
    char m_x;
    char f();
};
char S_func_006cf6e0::f()
{
    return m_x;
}
