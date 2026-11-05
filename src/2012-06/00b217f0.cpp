// roc 2012-06 00b217f0  unit: seg_00b20000  size: 11 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b217f0
//
// 00b217f0  b9a8a0e500           mov ecx, 0xe5a0a8
// 00b217f5  ff25d047b200         jmp dword ptr [0xb247d0]
// auto-matched from its assembly shape

struct __declspec(dllimport) T_func_00b217f0 { void m(); };
extern T_func_00b217f0 G1_func_00b217f0;
void func_00b217f0()
{
    G1_func_00b217f0.m();
}
