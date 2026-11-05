// roc 2012-06 00b1b0f0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1b0f0
//
// 00b1b0f0  b950e7e300           mov ecx, 0xe3e750
// 00b1b0f5  e976488fff           jmp 0x40f970
// auto-matched from its assembly shape

struct T_func_00b1b0f0 { void m(); };
extern T_func_00b1b0f0 G1_func_00b1b0f0;
void func_00b1b0f0()
{
    G1_func_00b1b0f0.m();
}
