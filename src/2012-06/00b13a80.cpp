// roc 2012-06 00b13a80  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b13a80
//
// 00b13a80  b9ac24e200           mov ecx, 0xe224ac
// 00b13a85  e966e4a7ff           jmp 0x591ef0
// auto-matched from its assembly shape

struct T_func_00b13a80 { void m(); };
extern T_func_00b13a80 G1_func_00b13a80;
void func_00b13a80()
{
    G1_func_00b13a80.m();
}
