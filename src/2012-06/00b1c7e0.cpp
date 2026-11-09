// roc 2012-06 00b1c7e0  unit: seg_00b10000  size: 11 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1c7e0
//
// 00b1c7e0  b914d0e400           mov ecx, 0xe4d014
// 00b1c7e5  ff253c26b200         jmp dword ptr [0xb2263c]
// auto-matched from its assembly shape

struct __declspec(dllimport) T_func_00b1c7e0 { void m(); };
extern T_func_00b1c7e0 G1_func_00b1c7e0;
void func_00b1c7e0()
{
    G1_func_00b1c7e0.m();
}
