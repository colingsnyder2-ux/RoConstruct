// roc 2012-06 009050f0  unit: RBX::HUMAN::HumanoidState  size: 8 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009050f0
//
// 009050f0  c6815802000001       mov byte ptr [ecx + 0x258], 1
// 009050f7  c3                   ret 
// auto-matched from its assembly shape

struct S_func_009050f0 {
    char pad0[600];
    char m_x;
    void f();
};
void S_func_009050f0::f()
{
    m_x = (char)1;
}
