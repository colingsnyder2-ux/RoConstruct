// roc 2012-06 00b14500  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b14500
//
// 00b14500  b9a844e200           mov ecx, 0xe244a8
// 00b14505  e9e6d9a7ff           jmp 0x591ef0
// auto-matched from its assembly shape

struct T_func_00b14500 { void m(); };
extern T_func_00b14500 G1_func_00b14500;
void func_00b14500()
{
    G1_func_00b14500.m();
}
