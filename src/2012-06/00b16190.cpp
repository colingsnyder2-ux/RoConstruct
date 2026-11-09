// roc 2012-06 00b16190  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b16190
//
// 00b16190  b900d2e200           mov ecx, 0xe2d200
// 00b16195  e9a65fb8ff           jmp 0x69c140
// auto-matched from its assembly shape

struct T_func_00b16190 { void m(); };
extern T_func_00b16190 G1_func_00b16190;
void func_00b16190()
{
    G1_func_00b16190.m();
}
