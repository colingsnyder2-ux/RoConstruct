// roc 2012-06 00b169a0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b169a0
//
// 00b169a0  b9b8eae200           mov ecx, 0xe2eab8
// 00b169a5  e99690d6ff           jmp 0x87fa40
// auto-matched from its assembly shape

struct T_func_00b169a0 { void m(); };
extern T_func_00b169a0 G1_func_00b169a0;
void func_00b169a0()
{
    G1_func_00b169a0.m();
}
