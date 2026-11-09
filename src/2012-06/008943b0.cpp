// roc 2012-06 008943b0  unit: RBX::BallBallContact  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 008943b0
//
// 008943b0  8b412c               mov eax, dword ptr [ecx + 0x2c]
// 008943b3  c20400               ret 4
// auto-matched from its assembly shape

struct S_func_008943b0 {
    char pad0[44];
    int m_x;
    int f(int a1);
};
int S_func_008943b0::f(int a1)
{
    return m_x;
}
