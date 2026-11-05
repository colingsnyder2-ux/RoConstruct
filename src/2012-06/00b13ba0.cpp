// roc 2012-06 00b13ba0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b13ba0
//
// 00b13ba0  b9e820e200           mov ecx, 0xe220e8
// 00b13ba5  e9c6d5b6ff           jmp 0x681170
// auto-matched from its assembly shape

struct T_func_00b13ba0 { void m(); };
extern T_func_00b13ba0 G1_func_00b13ba0;
void func_00b13ba0()
{
    G1_func_00b13ba0.m();
}
