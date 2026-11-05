// roc 2012-06 00b15610  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b15610
//
// 00b15610  b9f890e200           mov ecx, 0xe290f8
// 00b15615  e956a38fff           jmp 0x40f970
// auto-matched from its assembly shape

struct T_func_00b15610 { void m(); };
extern T_func_00b15610 G1_func_00b15610;
void func_00b15610()
{
    G1_func_00b15610.m();
}
