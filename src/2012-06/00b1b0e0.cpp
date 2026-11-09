// roc 2012-06 00b1b0e0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1b0e0
//
// 00b1b0e0  b938e9e300           mov ecx, 0xe3e938
// 00b1b0e5  e986488fff           jmp 0x40f970
// auto-matched from its assembly shape

struct T_func_00b1b0e0 { void m(); };
extern T_func_00b1b0e0 G1_func_00b1b0e0;
void func_00b1b0e0()
{
    G1_func_00b1b0e0.m();
}
