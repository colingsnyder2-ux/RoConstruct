// roc 2012-06 00b137a0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b137a0
//
// 00b137a0  b9600fe200           mov ecx, 0xe20f60
// 00b137a5  e946e7a7ff           jmp 0x591ef0
// auto-matched from its assembly shape

struct T_func_00b137a0 { void m(); };
extern T_func_00b137a0 G1_func_00b137a0;
void func_00b137a0()
{
    G1_func_00b137a0.m();
}
