// roc 2012-06 00b1e550  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1e550
//
// 00b1e550  b9d805e500           mov ecx, 0xe505d8
// 00b1e555  e99639a7ff           jmp 0x591ef0
// auto-matched from its assembly shape

struct T_func_00b1e550 { void m(); };
extern T_func_00b1e550 G1_func_00b1e550;
void func_00b1e550()
{
    G1_func_00b1e550.m();
}
