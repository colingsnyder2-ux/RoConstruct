// roc 2012-06 006ce220  unit: RBX::TopMenuBar  size: 7 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 006ce220
//
// 006ce220  8a81a8000000         mov al, byte ptr [ecx + 0xa8]
// 006ce226  c3                   ret 
// auto-matched from its assembly shape

struct S_func_006ce220 {
    char pad0[168];
    char m_x;
    char f();
};
char S_func_006ce220::f()
{
    return m_x;
}
