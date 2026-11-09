// roc 2012-06 00b183e0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b183e0
//
// 00b183e0  b9685ae300           mov ecx, 0xe35a68
// 00b183e5  e986758fff           jmp 0x40f970
// auto-matched from its assembly shape

struct T_func_00b183e0 { void m(); };
extern T_func_00b183e0 G1_func_00b183e0;
void func_00b183e0()
{
    G1_func_00b183e0.m();
}
