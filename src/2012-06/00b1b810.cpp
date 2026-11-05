// roc 2012-06 00b1b810  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1b810
//
// 00b1b810  b99091e400           mov ecx, 0xe49190
// 00b1b815  e9d666a7ff           jmp 0x591ef0
// auto-matched from its assembly shape

struct T_func_00b1b810 { void m(); };
extern T_func_00b1b810 G1_func_00b1b810;
void func_00b1b810()
{
    G1_func_00b1b810.m();
}
