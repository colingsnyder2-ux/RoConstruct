// roc 2012-06 00b13e40  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b13e40
//
// 00b13e40  b98828e200           mov ecx, 0xe22888
// 00b13e45  e9e62da4ff           jmp 0x556c30
// auto-matched from its assembly shape

struct T_func_00b13e40 { void m(); };
extern T_func_00b13e40 G1_func_00b13e40;
void func_00b13e40()
{
    G1_func_00b13e40.m();
}
