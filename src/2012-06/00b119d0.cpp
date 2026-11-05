// roc 2012-06 00b119d0  unit: seg_00b10000  size: 11 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b119d0
//
// 00b119d0  b97c87e100           mov ecx, 0xe1877c
// 00b119d5  ff25d047b200         jmp dword ptr [0xb247d0]
// auto-matched from its assembly shape

struct __declspec(dllimport) T_func_00b119d0 { void m(); };
extern T_func_00b119d0 G1_func_00b119d0;
void func_00b119d0()
{
    G1_func_00b119d0.m();
}
