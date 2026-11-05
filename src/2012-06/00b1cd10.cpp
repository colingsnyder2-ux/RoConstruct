// roc 2012-06 00b1cd10  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1cd10
//
// 00b1cd10  b9e0d6e400           mov ecx, 0xe4d6e0
// 00b1cd15  e9d651a7ff           jmp 0x591ef0
// auto-matched from its assembly shape

struct T_func_00b1cd10 { void m(); };
extern T_func_00b1cd10 G1_func_00b1cd10;
void func_00b1cd10()
{
    G1_func_00b1cd10.m();
}
