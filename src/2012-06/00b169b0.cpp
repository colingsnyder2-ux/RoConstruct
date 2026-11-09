// roc 2012-06 00b169b0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b169b0
//
// 00b169b0  b9f8eae200           mov ecx, 0xe2eaf8
// 00b169b5  e98690d6ff           jmp 0x87fa40
// auto-matched from its assembly shape

struct T_func_00b169b0 { void m(); };
extern T_func_00b169b0 G1_func_00b169b0;
void func_00b169b0()
{
    G1_func_00b169b0.m();
}
