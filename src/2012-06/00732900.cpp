// roc 2012-06 00732900  unit: RBX::GameBasicSettings  size: 7 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00732900
//
// 00732900  8a81ea020000         mov al, byte ptr [ecx + 0x2ea]
// 00732906  c3                   ret 
// auto-matched from its assembly shape

struct S_func_00732900 {
    char pad0[746];
    char m_x;
    char f();
};
char S_func_00732900::f()
{
    return m_x;
}
