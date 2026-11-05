// roc 2012-06 00b126c0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b126c0
//
// 00b126c0  b940a4e100           mov ecx, 0xe1a440
// 00b126c5  e9c61996ff           jmp 0x474090
// auto-matched from its assembly shape

struct T_func_00b126c0 { void m(); };
extern T_func_00b126c0 G1_func_00b126c0;
void func_00b126c0()
{
    G1_func_00b126c0.m();
}
