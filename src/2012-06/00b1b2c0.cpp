// roc 2012-06 00b1b2c0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1b2c0
//
// 00b1b2c0  b908b0e300           mov ecx, 0xe3b008
// 00b1b2c5  e9a6468fff           jmp 0x40f970
// auto-matched from its assembly shape

struct T_func_00b1b2c0 { void m(); };
extern T_func_00b1b2c0 G1_func_00b1b2c0;
void func_00b1b2c0()
{
    G1_func_00b1b2c0.m();
}
