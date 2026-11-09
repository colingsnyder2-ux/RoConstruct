// roc 2012-06 00b1a940  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1a940
//
// 00b1a940  b99098e300           mov ecx, 0xe39890
// 00b1a945  e9664cc5ff           jmp 0x76f5b0
// auto-matched from its assembly shape

struct T_func_00b1a940 { void m(); };
extern T_func_00b1a940 G1_func_00b1a940;
void func_00b1a940()
{
    G1_func_00b1a940.m();
}
