// roc 2012-06 00b13720  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b13720
//
// 00b13720  b9a00de200           mov ecx, 0xe20da0
// 00b13725  e9c6e7a7ff           jmp 0x591ef0
// auto-matched from its assembly shape

struct T_func_00b13720 { void m(); };
extern T_func_00b13720 G1_func_00b13720;
void func_00b13720()
{
    G1_func_00b13720.m();
}
