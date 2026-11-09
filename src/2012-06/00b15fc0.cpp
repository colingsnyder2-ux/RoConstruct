// roc 2012-06 00b15fc0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b15fc0
//
// 00b15fc0  b998c6e200           mov ecx, 0xe2c698
// 00b15fc5  e9a6998fff           jmp 0x40f970
// auto-matched from its assembly shape

struct T_func_00b15fc0 { void m(); };
extern T_func_00b15fc0 G1_func_00b15fc0;
void func_00b15fc0()
{
    G1_func_00b15fc0.m();
}
