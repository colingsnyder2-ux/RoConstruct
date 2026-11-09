// roc 2012-06 00b16210  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b16210
//
// 00b16210  b910d7e200           mov ecx, 0xe2d710
// 00b16215  e92698d6ff           jmp 0x87fa40
// auto-matched from its assembly shape

struct T_func_00b16210 { void m(); };
extern T_func_00b16210 G1_func_00b16210;
void func_00b16210()
{
    G1_func_00b16210.m();
}
