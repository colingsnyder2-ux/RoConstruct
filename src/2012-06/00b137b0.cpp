// roc 2012-06 00b137b0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b137b0
//
// 00b137b0  b9480be200           mov ecx, 0xe20b48
// 00b137b5  e936e7a7ff           jmp 0x591ef0
// auto-matched from its assembly shape

struct T_func_00b137b0 { void m(); };
extern T_func_00b137b0 G1_func_00b137b0;
void func_00b137b0()
{
    G1_func_00b137b0.m();
}
