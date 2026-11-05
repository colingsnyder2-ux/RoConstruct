// roc 2012-06 00b1b1d0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1b1d0
//
// 00b1b1d0  b9a0cce300           mov ecx, 0xe3cca0
// 00b1b1d5  e996478fff           jmp 0x40f970
// auto-matched from its assembly shape

struct T_func_00b1b1d0 { void m(); };
extern T_func_00b1b1d0 G1_func_00b1b1d0;
void func_00b1b1d0()
{
    G1_func_00b1b1d0.m();
}
