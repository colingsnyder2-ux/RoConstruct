// roc 2012-06 00b1b4d0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1b4d0
//
// 00b1b4d0  b9f489e400           mov ecx, 0xe489f4
// 00b1b4d5  e986d1c5ff           jmp 0x778660
// auto-matched from its assembly shape

struct T_func_00b1b4d0 { void m(); };
extern T_func_00b1b4d0 G1_func_00b1b4d0;
void func_00b1b4d0()
{
    G1_func_00b1b4d0.m();
}
