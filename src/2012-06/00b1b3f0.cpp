// roc 2012-06 00b1b3f0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1b3f0
//
// 00b1b3f0  b95089e400           mov ecx, 0xe48950
// 00b1b3f5  e9a615c6ff           jmp 0x77c9a0
// auto-matched from its assembly shape

struct T_func_00b1b3f0 { void m(); };
extern T_func_00b1b3f0 G1_func_00b1b3f0;
void func_00b1b3f0()
{
    G1_func_00b1b3f0.m();
}
