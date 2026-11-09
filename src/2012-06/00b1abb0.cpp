// roc 2012-06 00b1abb0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1abb0
//
// 00b1abb0  b9c07de300           mov ecx, 0xe37dc0
// 00b1abb5  e906edc4ff           jmp 0x7698c0
// auto-matched from its assembly shape

struct T_func_00b1abb0 { void m(); };
extern T_func_00b1abb0 G1_func_00b1abb0;
void func_00b1abb0()
{
    G1_func_00b1abb0.m();
}
