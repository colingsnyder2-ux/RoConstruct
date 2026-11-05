// roc 2012-06 00b17910  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b17910
//
// 00b17910  b99821e300           mov ecx, 0xe32198
// 00b17915  e9d6a5a7ff           jmp 0x591ef0
// auto-matched from its assembly shape

struct T_func_00b17910 { void m(); };
extern T_func_00b17910 G1_func_00b17910;
void func_00b17910()
{
    G1_func_00b17910.m();
}
