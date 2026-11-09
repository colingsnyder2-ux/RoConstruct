// roc 2012-06 00b13a10  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b13a10
//
// 00b13a10  b9a01ee200           mov ecx, 0xe21ea0
// 00b13a15  e9d6e4a7ff           jmp 0x591ef0
// auto-matched from its assembly shape

struct T_func_00b13a10 { void m(); };
extern T_func_00b13a10 G1_func_00b13a10;
void func_00b13a10()
{
    G1_func_00b13a10.m();
}
