// roc 2012-06 00a79a80  unit: CXTCaptionButtonTheme  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00a79a80
//
// 00a79a80  8b442404             mov eax, dword ptr [esp + 4]
// 00a79a84  894134               mov dword ptr [ecx + 0x34], eax
// 00a79a87  c20400               ret 4
// auto-matched from its assembly shape

struct S_func_00a79a80 {
    char pad0[52];
    int m_x;
    void f(int a1);
};
void S_func_00a79a80::f(int a1)
{
    m_x = (int)a1;
}
