// roc 2012-06 00b149b0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b149b0
//
// 00b149b0  b94059e200           mov ecx, 0xe25940
// 00b149b5  e9b6af8fff           jmp 0x40f970
// auto-matched from its assembly shape

struct T_func_00b149b0 { void m(); };
extern T_func_00b149b0 G1_func_00b149b0;
void func_00b149b0()
{
    G1_func_00b149b0.m();
}
