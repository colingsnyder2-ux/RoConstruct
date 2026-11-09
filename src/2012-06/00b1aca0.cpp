// roc 2012-06 00b1aca0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1aca0
//
// 00b1aca0  b9d86ae400           mov ecx, 0xe46ad8
// 00b1aca5  e9c64c8fff           jmp 0x40f970
// auto-matched from its assembly shape

struct T_func_00b1aca0 { void m(); };
extern T_func_00b1aca0 G1_func_00b1aca0;
void func_00b1aca0()
{
    G1_func_00b1aca0.m();
}
