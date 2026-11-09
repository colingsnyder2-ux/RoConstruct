// roc 2012-06 00b15960  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b15960
//
// 00b15960  b940a8e200           mov ecx, 0xe2a840
// 00b15965  e986c5a7ff           jmp 0x591ef0
// auto-matched from its assembly shape

struct T_func_00b15960 { void m(); };
extern T_func_00b15960 G1_func_00b15960;
void func_00b15960()
{
    G1_func_00b15960.m();
}
