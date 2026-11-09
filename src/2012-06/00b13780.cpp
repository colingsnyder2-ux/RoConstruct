// roc 2012-06 00b13780  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b13780
//
// 00b13780  b9c010e200           mov ecx, 0xe210c0
// 00b13785  e966e7a7ff           jmp 0x591ef0
// auto-matched from its assembly shape

struct T_func_00b13780 { void m(); };
extern T_func_00b13780 G1_func_00b13780;
void func_00b13780()
{
    G1_func_00b13780.m();
}
