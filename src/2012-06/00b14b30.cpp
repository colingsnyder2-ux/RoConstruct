// roc 2012-06 00b14b30  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b14b30
//
// 00b14b30  b9f075e200           mov ecx, 0xe275f0
// 00b14b35  e936ae8fff           jmp 0x40f970
// auto-matched from its assembly shape

struct T_func_00b14b30 { void m(); };
extern T_func_00b14b30 G1_func_00b14b30;
void func_00b14b30()
{
    G1_func_00b14b30.m();
}
