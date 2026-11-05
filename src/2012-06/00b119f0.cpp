// roc 2012-06 00b119f0  unit: seg_00b10000  size: 11 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b119f0
//
// 00b119f0  b9c087e100           mov ecx, 0xe187c0
// 00b119f5  ff253c26b200         jmp dword ptr [0xb2263c]
// auto-matched from its assembly shape

struct __declspec(dllimport) T_func_00b119f0 { void m(); };
extern T_func_00b119f0 G1_func_00b119f0;
void func_00b119f0()
{
    G1_func_00b119f0.m();
}
