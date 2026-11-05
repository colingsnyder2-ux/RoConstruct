// roc 2012-06 00b1bdf0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1bdf0
//
// 00b1bdf0  b9909ce400           mov ecx, 0xe49c90
// 00b1bdf5  e9f660a7ff           jmp 0x591ef0
// auto-matched from its assembly shape

struct T_func_00b1bdf0 { void m(); };
extern T_func_00b1bdf0 G1_func_00b1bdf0;
void func_00b1bdf0()
{
    G1_func_00b1bdf0.m();
}
