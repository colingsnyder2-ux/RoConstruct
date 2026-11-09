// roc 2012-06 00b1aab0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1aab0
//
// 00b1aab0  b9c088e300           mov ecx, 0xe388c0
// 00b1aab5  e97612c5ff           jmp 0x76bd30
// auto-matched from its assembly shape

struct T_func_00b1aab0 { void m(); };
extern T_func_00b1aab0 G1_func_00b1aab0;
void func_00b1aab0()
{
    G1_func_00b1aab0.m();
}
