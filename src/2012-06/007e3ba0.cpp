// roc 2012-06 007e3ba0  unit: RBX::Assembly  size: 5 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 007e3ba0
//
// 007e3ba0  c6417401             mov byte ptr [ecx + 0x74], 1
// 007e3ba4  c3                   ret 
// auto-matched from its assembly shape

struct S_func_007e3ba0 {
    char pad0[116];
    char m_x;
    void f();
};
void S_func_007e3ba0::f()
{
    m_x = (char)1;
}
