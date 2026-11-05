// roc 2012-06 0067f6d0  unit: RBX::Reflection::EventSource  size: 4 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0067f6d0
//
// 0067f6d0  8a4162               mov al, byte ptr [ecx + 0x62]
// 0067f6d3  c3                   ret 
// auto-matched from its assembly shape

struct S_func_0067f6d0 {
    char pad0[98];
    char m_x;
    char f();
};
char S_func_0067f6d0::f()
{
    return m_x;
}
