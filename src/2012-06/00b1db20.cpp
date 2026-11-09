// roc 2012-06 00b1db20  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1db20
//
// 00b1db20  b970ebe400           mov ecx, 0xe4eb70
// 00b1db25  e9c643a7ff           jmp 0x591ef0
// auto-matched from its assembly shape

struct T_func_00b1db20 { void m(); };
extern T_func_00b1db20 G1_func_00b1db20;
void func_00b1db20()
{
    G1_func_00b1db20.m();
}
