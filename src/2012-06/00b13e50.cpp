// roc 2012-06 00b13e50  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b13e50
//
// 00b13e50  b9d827e200           mov ecx, 0xe227d8
// 00b13e55  e9362ba4ff           jmp 0x556990
// auto-matched from its assembly shape

struct T_func_00b13e50 { void m(); };
extern T_func_00b13e50 G1_func_00b13e50;
void func_00b13e50()
{
    G1_func_00b13e50.m();
}
