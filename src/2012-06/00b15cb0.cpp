// roc 2012-06 00b15cb0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b15cb0
//
// 00b15cb0  b980b5e200           mov ecx, 0xe2b580
// 00b15cb5  e936c2a7ff           jmp 0x591ef0
// auto-matched from its assembly shape

struct T_func_00b15cb0 { void m(); };
extern T_func_00b15cb0 G1_func_00b15cb0;
void func_00b15cb0()
{
    G1_func_00b15cb0.m();
}
