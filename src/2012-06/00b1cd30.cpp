// roc 2012-06 00b1cd30  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1cd30
//
// 00b1cd30  b9d8d0e400           mov ecx, 0xe4d0d8
// 00b1cd35  e9b651a7ff           jmp 0x591ef0
// auto-matched from its assembly shape

struct T_func_00b1cd30 { void m(); };
extern T_func_00b1cd30 G1_func_00b1cd30;
void func_00b1cd30()
{
    G1_func_00b1cd30.m();
}
