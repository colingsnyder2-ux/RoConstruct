// roc 2012-06 00b1cac0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1cac0
//
// 00b1cac0  b9c0d4e400           mov ecx, 0xe4d4c0
// 00b1cac5  e92654a7ff           jmp 0x591ef0
// auto-matched from its assembly shape

struct T_func_00b1cac0 { void m(); };
extern T_func_00b1cac0 G1_func_00b1cac0;
void func_00b1cac0()
{
    G1_func_00b1cac0.m();
}
