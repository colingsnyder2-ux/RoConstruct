// roc 2012-06 00b1b2b0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1b2b0
//
// 00b1b2b0  b9f0b1e300           mov ecx, 0xe3b1f0
// 00b1b2b5  e9b6468fff           jmp 0x40f970
// auto-matched from its assembly shape

struct T_func_00b1b2b0 { void m(); };
extern T_func_00b1b2b0 G1_func_00b1b2b0;
void func_00b1b2b0()
{
    G1_func_00b1b2b0.m();
}
