// roc 2012-06 00b13740  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b13740
//
// 00b13740  b91412e200           mov ecx, 0xe21214
// 00b13745  e9a6e7a7ff           jmp 0x591ef0
// auto-matched from its assembly shape

struct T_func_00b13740 { void m(); };
extern T_func_00b13740 G1_func_00b13740;
void func_00b13740()
{
    G1_func_00b13740.m();
}
