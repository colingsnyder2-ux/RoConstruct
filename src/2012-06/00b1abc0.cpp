// roc 2012-06 00b1abc0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1abc0
//
// 00b1abc0  b9107de300           mov ecx, 0xe37d10
// 00b1abc5  e956eac4ff           jmp 0x769620
// auto-matched from its assembly shape

struct T_func_00b1abc0 { void m(); };
extern T_func_00b1abc0 G1_func_00b1abc0;
void func_00b1abc0()
{
    G1_func_00b1abc0.m();
}
