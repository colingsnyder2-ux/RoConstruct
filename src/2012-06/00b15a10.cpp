// roc 2012-06 00b15a10  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b15a10
//
// 00b15a10  b9b8a6e200           mov ecx, 0xe2a6b8
// 00b15a15  e9d6c4a7ff           jmp 0x591ef0
// auto-matched from its assembly shape

struct T_func_00b15a10 { void m(); };
extern T_func_00b15a10 G1_func_00b15a10;
void func_00b15a10()
{
    G1_func_00b15a10.m();
}
