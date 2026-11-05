// roc 2012-06 00b13e80  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b13e80
//
// 00b13e80  b9e830e200           mov ecx, 0xe230e8
// 00b13e85  e9e6ba8fff           jmp 0x40f970
// auto-matched from its assembly shape

struct T_func_00b13e80 { void m(); };
extern T_func_00b13e80 G1_func_00b13e80;
void func_00b13e80()
{
    G1_func_00b13e80.m();
}
