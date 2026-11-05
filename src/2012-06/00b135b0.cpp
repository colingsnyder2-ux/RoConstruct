// roc 2012-06 00b135b0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b135b0
//
// 00b135b0  b91813e200           mov ecx, 0xe21318
// 00b135b5  e936e9a7ff           jmp 0x591ef0
// auto-matched from its assembly shape

struct T_func_00b135b0 { void m(); };
extern T_func_00b135b0 G1_func_00b135b0;
void func_00b135b0()
{
    G1_func_00b135b0.m();
}
