// roc 2012-06 00b1d0c0  unit: seg_00b10000  size: 11 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1d0c0
//
// 00b1d0c0  b938e2e400           mov ecx, 0xe4e238
// 00b1d0c5  ff253c26b200         jmp dword ptr [0xb2263c]
// auto-matched from its assembly shape

struct __declspec(dllimport) T_func_00b1d0c0 { void m(); };
extern T_func_00b1d0c0 G1_func_00b1d0c0;
void func_00b1d0c0()
{
    G1_func_00b1d0c0.m();
}
