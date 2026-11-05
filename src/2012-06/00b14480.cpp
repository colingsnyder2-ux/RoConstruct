// roc 2012-06 00b14480  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b14480
//
// 00b14480  b97044e200           mov ecx, 0xe24470
// 00b14485  e966daa7ff           jmp 0x591ef0
// auto-matched from its assembly shape

struct T_func_00b14480 { void m(); };
extern T_func_00b14480 G1_func_00b14480;
void func_00b14480()
{
    G1_func_00b14480.m();
}
