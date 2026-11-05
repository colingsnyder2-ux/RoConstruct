// roc 2012-06 00b15880  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b15880
//
// 00b15880  b9a8a5e200           mov ecx, 0xe2a5a8
// 00b15885  e966c6a7ff           jmp 0x591ef0
// auto-matched from its assembly shape

struct T_func_00b15880 { void m(); };
extern T_func_00b15880 G1_func_00b15880;
void func_00b15880()
{
    G1_func_00b15880.m();
}
