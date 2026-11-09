// roc 2012-06 00b1b1f0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1b1f0
//
// 00b1b1f0  b9d0c8e300           mov ecx, 0xe3c8d0
// 00b1b1f5  e976478fff           jmp 0x40f970
// auto-matched from its assembly shape

struct T_func_00b1b1f0 { void m(); };
extern T_func_00b1b1f0 G1_func_00b1b1f0;
void func_00b1b1f0()
{
    G1_func_00b1b1f0.m();
}
