// roc 2012-06 00b169e0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b169e0
//
// 00b169e0  b938ebe200           mov ecx, 0xe2eb38
// 00b169e5  e95690d6ff           jmp 0x87fa40
// auto-matched from its assembly shape

struct T_func_00b169e0 { void m(); };
extern T_func_00b169e0 G1_func_00b169e0;
void func_00b169e0()
{
    G1_func_00b169e0.m();
}
