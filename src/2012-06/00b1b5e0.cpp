// roc 2012-06 00b1b5e0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1b5e0
//
// 00b1b5e0  b93c8ae400           mov ecx, 0xe48a3c
// 00b1b5e5  e9c672c5ff           jmp 0x7728b0
// auto-matched from its assembly shape

struct T_func_00b1b5e0 { void m(); };
extern T_func_00b1b5e0 G1_func_00b1b5e0;
void func_00b1b5e0()
{
    G1_func_00b1b5e0.m();
}
