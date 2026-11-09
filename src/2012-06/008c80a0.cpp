// roc 2012-06 008c80a0  unit: RBX::$$A6AXABVUIEvent::?$signal::Vslot::?$callable  size: 7 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 008c80a0
//
// 008c80a0  8a8181000000         mov al, byte ptr [ecx + 0x81]
// 008c80a6  c3                   ret 
// auto-matched from its assembly shape

struct S_func_008c80a0 {
    char pad0[129];
    char m_x;
    char f();
};
char S_func_008c80a0::f()
{
    return m_x;
}
