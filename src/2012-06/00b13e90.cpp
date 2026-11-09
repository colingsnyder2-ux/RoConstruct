// roc 2012-06 00b13e90  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b13e90
//
// 00b13e90  b9002fe200           mov ecx, 0xe22f00
// 00b13e95  e9d6ba8fff           jmp 0x40f970
// auto-matched from its assembly shape

struct T_func_00b13e90 { void m(); };
extern T_func_00b13e90 G1_func_00b13e90;
void func_00b13e90()
{
    G1_func_00b13e90.m();
}
