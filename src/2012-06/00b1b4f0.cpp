// roc 2012-06 00b1b4f0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1b4f0
//
// 00b1b4f0  b9c487e400           mov ecx, 0xe487c4
// 00b1b4f5  e9c6c7c5ff           jmp 0x777cc0
// auto-matched from its assembly shape

struct T_func_00b1b4f0 { void m(); };
extern T_func_00b1b4f0 G1_func_00b1b4f0;
void func_00b1b4f0()
{
    G1_func_00b1b4f0.m();
}
