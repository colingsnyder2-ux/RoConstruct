// roc 2012-06 00b1b1a0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1b1a0
//
// 00b1b1a0  b958d2e300           mov ecx, 0xe3d258
// 00b1b1a5  e9c6478fff           jmp 0x40f970
// auto-matched from its assembly shape

struct T_func_00b1b1a0 { void m(); };
extern T_func_00b1b1a0 G1_func_00b1b1a0;
void func_00b1b1a0()
{
    G1_func_00b1b1a0.m();
}
