// roc 2012-06 00b1b490  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1b490
//
// 00b1b490  b93c87e400           mov ecx, 0xe4873c
// 00b1b495  e906e5c5ff           jmp 0x7799a0
// auto-matched from its assembly shape

struct T_func_00b1b490 { void m(); };
extern T_func_00b1b490 G1_func_00b1b490;
void func_00b1b490()
{
    G1_func_00b1b490.m();
}
