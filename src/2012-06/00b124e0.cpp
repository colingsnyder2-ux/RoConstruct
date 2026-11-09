// roc 2012-06 00b124e0  unit: seg_00b10000  size: 11 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b124e0
//
// 00b124e0  b954a2e100           mov ecx, 0xe1a254
// 00b124e5  ff25d047b200         jmp dword ptr [0xb247d0]
// auto-matched from its assembly shape

struct __declspec(dllimport) T_func_00b124e0 { void m(); };
extern T_func_00b124e0 G1_func_00b124e0;
void func_00b124e0()
{
    G1_func_00b124e0.m();
}
