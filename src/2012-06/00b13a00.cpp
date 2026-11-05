// roc 2012-06 00b13a00  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b13a00
//
// 00b13a00  b9a021e200           mov ecx, 0xe221a0
// 00b13a05  e9e6e4a7ff           jmp 0x591ef0
// auto-matched from its assembly shape

struct T_func_00b13a00 { void m(); };
extern T_func_00b13a00 G1_func_00b13a00;
void func_00b13a00()
{
    G1_func_00b13a00.m();
}
