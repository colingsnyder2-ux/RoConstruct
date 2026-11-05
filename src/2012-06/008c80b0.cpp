// roc 2012-06 008c80b0  unit: RBX::$$A6AXABVUIEvent::?$signal::Vslot::?$callable  size: 7 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 008c80b0
//
// 008c80b0  d98184000000         fld dword ptr [ecx + 0x84]
// 008c80b6  c3                   ret 
// auto-matched from its assembly shape

struct S_func_008c80b0 {
    char pad[132];
    float m_x;
    float f();
};
float S_func_008c80b0::f()
{
    return m_x;
}
