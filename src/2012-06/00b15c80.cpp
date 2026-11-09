// roc 2012-06 00b15c80  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b15c80
//
// 00b15c80  b900b5e200           mov ecx, 0xe2b500
// 00b15c85  e966c2a7ff           jmp 0x591ef0
// auto-matched from its assembly shape

struct T_func_00b15c80 { void m(); };
extern T_func_00b15c80 G1_func_00b15c80;
void func_00b15c80()
{
    G1_func_00b15c80.m();
}
