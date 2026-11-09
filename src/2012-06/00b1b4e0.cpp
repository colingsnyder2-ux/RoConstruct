// roc 2012-06 00b1b4e0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1b4e0
//
// 00b1b4e0  b94c8ae400           mov ecx, 0xe48a4c
// 00b1b4e5  e9a6ccc5ff           jmp 0x778190
// auto-matched from its assembly shape

struct T_func_00b1b4e0 { void m(); };
extern T_func_00b1b4e0 G1_func_00b1b4e0;
void func_00b1b4e0()
{
    G1_func_00b1b4e0.m();
}
