// roc 2012-06 00b15fd0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b15fd0
//
// 00b15fd0  b948c2e200           mov ecx, 0xe2c248
// 00b15fd5  e916bfa7ff           jmp 0x591ef0
// auto-matched from its assembly shape

struct T_func_00b15fd0 { void m(); };
extern T_func_00b15fd0 G1_func_00b15fd0;
void func_00b15fd0()
{
    G1_func_00b15fd0.m();
}
