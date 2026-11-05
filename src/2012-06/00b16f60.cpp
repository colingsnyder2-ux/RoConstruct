// roc 2012-06 00b16f60  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b16f60
//
// 00b16f60  b918f5e200           mov ecx, 0xe2f518
// 00b16f65  e986afa7ff           jmp 0x591ef0
// auto-matched from its assembly shape

struct T_func_00b16f60 { void m(); };
extern T_func_00b16f60 G1_func_00b16f60;
void func_00b16f60()
{
    G1_func_00b16f60.m();
}
