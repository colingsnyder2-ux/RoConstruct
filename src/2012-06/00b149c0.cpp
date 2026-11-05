// roc 2012-06 00b149c0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b149c0
//
// 00b149c0  b95857e200           mov ecx, 0xe25758
// 00b149c5  e9a6af8fff           jmp 0x40f970
// auto-matched from its assembly shape

struct T_func_00b149c0 { void m(); };
extern T_func_00b149c0 G1_func_00b149c0;
void func_00b149c0()
{
    G1_func_00b149c0.m();
}
