// roc 2012-06 00b17db0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b17db0
//
// 00b17db0  b9583ae300           mov ecx, 0xe33a58
// 00b17db5  e9b67b8fff           jmp 0x40f970
// auto-matched from its assembly shape

struct T_func_00b17db0 { void m(); };
extern T_func_00b17db0 G1_func_00b17db0;
void func_00b17db0()
{
    G1_func_00b17db0.m();
}
