// roc 2012-06 00b1c0e0  unit: seg_00b10000  size: 11 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1c0e0
//
// 00b1c0e0  b978a9e400           mov ecx, 0xe4a978
// 00b1c0e5  ff253c26b200         jmp dword ptr [0xb2263c]
// auto-matched from its assembly shape

struct __declspec(dllimport) T_func_00b1c0e0 { void m(); };
extern T_func_00b1c0e0 G1_func_00b1c0e0;
void func_00b1c0e0()
{
    G1_func_00b1c0e0.m();
}
