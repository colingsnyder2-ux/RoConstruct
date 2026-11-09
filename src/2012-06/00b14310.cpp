// roc 2012-06 00b14310  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b14310
//
// 00b14310  b9303de200           mov ecx, 0xe23d30
// 00b14315  e9d6dba7ff           jmp 0x591ef0
// auto-matched from its assembly shape

struct T_func_00b14310 { void m(); };
extern T_func_00b14310 G1_func_00b14310;
void func_00b14310()
{
    G1_func_00b14310.m();
}
