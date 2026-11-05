// roc 2012-06 00b1acc0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1acc0
//
// 00b1acc0  b90867e400           mov ecx, 0xe46708
// 00b1acc5  e9a64c8fff           jmp 0x40f970
// auto-matched from its assembly shape

struct T_func_00b1acc0 { void m(); };
extern T_func_00b1acc0 G1_func_00b1acc0;
void func_00b1acc0()
{
    G1_func_00b1acc0.m();
}
