// roc 2012-06 0079edc0  unit: RBX::Humanoid  size: 5 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0079edc0
//
// 0079edc0  c6412801             mov byte ptr [ecx + 0x28], 1
// 0079edc4  c3                   ret 
// auto-matched from its assembly shape

struct S_func_0079edc0 {
    char pad0[40];
    char m_x;
    void f();
};
void S_func_0079edc0::f()
{
    m_x = (char)1;
}
