// roc 2012-06 00b1db10  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1db10
//
// 00b1db10  b9c0eee400           mov ecx, 0xe4eec0
// 00b1db15  e9d643a7ff           jmp 0x591ef0
// auto-matched from its assembly shape

struct T_func_00b1db10 { void m(); };
extern T_func_00b1db10 G1_func_00b1db10;
void func_00b1db10()
{
    G1_func_00b1db10.m();
}
