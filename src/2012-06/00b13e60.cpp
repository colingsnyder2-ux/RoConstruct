// roc 2012-06 00b13e60  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b13e60
//
// 00b13e60  b92827e200           mov ecx, 0xe22728
// 00b13e65  e91629a4ff           jmp 0x556780
// auto-matched from its assembly shape

struct T_func_00b13e60 { void m(); };
extern T_func_00b13e60 G1_func_00b13e60;
void func_00b13e60()
{
    G1_func_00b13e60.m();
}
