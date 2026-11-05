// roc 2012-06 00b1b0c0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1b0c0
//
// 00b1b0c0  b908ede300           mov ecx, 0xe3ed08
// 00b1b0c5  e9a6488fff           jmp 0x40f970
// auto-matched from its assembly shape

struct T_func_00b1b0c0 { void m(); };
extern T_func_00b1b0c0 G1_func_00b1b0c0;
void func_00b1b0c0()
{
    G1_func_00b1b0c0.m();
}
