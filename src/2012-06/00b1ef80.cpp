// roc 2012-06 00b1ef80  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1ef80
//
// 00b1ef80  b9e81ae500           mov ecx, 0xe51ae8
// 00b1ef85  e9662fa7ff           jmp 0x591ef0
// auto-matched from its assembly shape

struct T_func_00b1ef80 { void m(); };
extern T_func_00b1ef80 G1_func_00b1ef80;
void func_00b1ef80()
{
    G1_func_00b1ef80.m();
}
