// roc 2012-06 00b1b2a0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1b2a0
//
// 00b1b2a0  b9d8b3e300           mov ecx, 0xe3b3d8
// 00b1b2a5  e9c6468fff           jmp 0x40f970
// auto-matched from its assembly shape

struct T_func_00b1b2a0 { void m(); };
extern T_func_00b1b2a0 G1_func_00b1b2a0;
void func_00b1b2a0()
{
    G1_func_00b1b2a0.m();
}
