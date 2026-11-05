// roc 2012-06 00b16d80  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b16d80
//
// 00b16d80  b900f8e200           mov ecx, 0xe2f800
// 00b16d85  e966b1a7ff           jmp 0x591ef0
// auto-matched from its assembly shape

struct T_func_00b16d80 { void m(); };
extern T_func_00b16d80 G1_func_00b16d80;
void func_00b16d80()
{
    G1_func_00b16d80.m();
}
