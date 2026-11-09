// roc 2012-06 00b1b5f0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1b5f0
//
// 00b1b5f0  b9008de400           mov ecx, 0xe48d00
// 00b1b5f5  e9066ec5ff           jmp 0x772400
// auto-matched from its assembly shape

struct T_func_00b1b5f0 { void m(); };
extern T_func_00b1b5f0 G1_func_00b1b5f0;
void func_00b1b5f0()
{
    G1_func_00b1b5f0.m();
}
