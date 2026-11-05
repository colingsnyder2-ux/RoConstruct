// roc 2012-06 00b1a9f0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1a9f0
//
// 00b1a9f0  b90091e300           mov ecx, 0xe39100
// 00b1a9f5  e92633c5ff           jmp 0x76dd20
// auto-matched from its assembly shape

struct T_func_00b1a9f0 { void m(); };
extern T_func_00b1a9f0 G1_func_00b1a9f0;
void func_00b1a9f0()
{
    G1_func_00b1a9f0.m();
}
