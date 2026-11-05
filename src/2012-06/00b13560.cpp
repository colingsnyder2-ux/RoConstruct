// roc 2012-06 00b13560  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b13560
//
// 00b13560  b91815e200           mov ecx, 0xe21518
// 00b13565  e98637a1ff           jmp 0x526cf0
// auto-matched from its assembly shape

struct T_func_00b13560 { void m(); };
extern T_func_00b13560 G1_func_00b13560;
void func_00b13560()
{
    G1_func_00b13560.m();
}
