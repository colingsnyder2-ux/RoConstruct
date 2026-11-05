// roc 2012-06 00b14720  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b14720
//
// 00b14720  b9584de200           mov ecx, 0xe24d58
// 00b14725  e9c6d7a7ff           jmp 0x591ef0
// auto-matched from its assembly shape

struct T_func_00b14720 { void m(); };
extern T_func_00b14720 G1_func_00b14720;
void func_00b14720()
{
    G1_func_00b14720.m();
}
