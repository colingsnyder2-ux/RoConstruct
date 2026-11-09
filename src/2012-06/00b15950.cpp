// roc 2012-06 00b15950  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b15950
//
// 00b15950  b918a7e200           mov ecx, 0xe2a718
// 00b15955  e996c5a7ff           jmp 0x591ef0
// auto-matched from its assembly shape

struct T_func_00b15950 { void m(); };
extern T_func_00b15950 G1_func_00b15950;
void func_00b15950()
{
    G1_func_00b15950.m();
}
