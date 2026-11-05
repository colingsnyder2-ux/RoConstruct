// roc 2012-06 00b216f0  unit: seg_00b20000  size: 11 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b216f0
//
// 00b216f0  b96c94e500           mov ecx, 0xe5946c
// 00b216f5  ff25d047b200         jmp dword ptr [0xb247d0]
// auto-matched from its assembly shape

struct __declspec(dllimport) T_func_00b216f0 { void m(); };
extern T_func_00b216f0 G1_func_00b216f0;
void func_00b216f0()
{
    G1_func_00b216f0.m();
}
