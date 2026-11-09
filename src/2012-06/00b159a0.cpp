// roc 2012-06 00b159a0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b159a0
//
// 00b159a0  b988a6e200           mov ecx, 0xe2a688
// 00b159a5  e946c5a7ff           jmp 0x591ef0
// auto-matched from its assembly shape

struct T_func_00b159a0 { void m(); };
extern T_func_00b159a0 G1_func_00b159a0;
void func_00b159a0()
{
    G1_func_00b159a0.m();
}
