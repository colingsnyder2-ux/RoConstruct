// roc 2012-06 006f0410  unit: RBX::DataModel  size: 7 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 006f0410
//
// 006f0410  8a81680a0000         mov al, byte ptr [ecx + 0xa68]
// 006f0416  c3                   ret 
// auto-matched from its assembly shape

struct S_func_006f0410 {
    char pad0[2664];
    char m_x;
    char f();
};
char S_func_006f0410::f()
{
    return m_x;
}
