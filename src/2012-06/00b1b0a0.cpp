// roc 2012-06 00b1b0a0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1b0a0
//
// 00b1b0a0  b9d8f0e300           mov ecx, 0xe3f0d8
// 00b1b0a5  e9c6488fff           jmp 0x40f970
// auto-matched from its assembly shape

struct T_func_00b1b0a0 { void m(); };
extern T_func_00b1b0a0 G1_func_00b1b0a0;
void func_00b1b0a0()
{
    G1_func_00b1b0a0.m();
}
