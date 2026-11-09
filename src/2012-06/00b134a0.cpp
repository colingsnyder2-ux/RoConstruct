// roc 2012-06 00b134a0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b134a0
//
// 00b134a0  b95013e200           mov ecx, 0xe21350
// 00b134a5  e946eaa7ff           jmp 0x591ef0
// auto-matched from its assembly shape

struct T_func_00b134a0 { void m(); };
extern T_func_00b134a0 G1_func_00b134a0;
void func_00b134a0()
{
    G1_func_00b134a0.m();
}
