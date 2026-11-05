// roc 2012-06 00b16440  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b16440
//
// 00b16440  b918dae200           mov ecx, 0xe2da18
// 00b16445  e9a6baa7ff           jmp 0x591ef0
// auto-matched from its assembly shape

struct T_func_00b16440 { void m(); };
extern T_func_00b16440 G1_func_00b16440;
void func_00b16440()
{
    G1_func_00b16440.m();
}
