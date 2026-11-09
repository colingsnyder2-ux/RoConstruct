// roc 2012-06 007773f0  unit: RBX::VPartInstance::?$ActionStation  size: 7 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 007773f0
//
// 007773f0  8a81e5010000         mov al, byte ptr [ecx + 0x1e5]
// 007773f6  c3                   ret 
// auto-matched from its assembly shape

struct S_func_007773f0 {
    char pad0[485];
    char m_x;
    char f();
};
char S_func_007773f0::f()
{
    return m_x;
}
