// roc 2012-06 00b1b310  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1b310
//
// 00b1b310  b980a6e300           mov ecx, 0xe3a680
// 00b1b315  e956468fff           jmp 0x40f970
// auto-matched from its assembly shape

struct T_func_00b1b310 { void m(); };
extern T_func_00b1b310 G1_func_00b1b310;
void func_00b1b310()
{
    G1_func_00b1b310.m();
}
