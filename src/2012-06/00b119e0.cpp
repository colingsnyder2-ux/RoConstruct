// roc 2012-06 00b119e0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b119e0
//
// 00b119e0  b99087e100           mov ecx, 0xe18790
// 00b119e5  e92616bcff           jmp 0x6d3010
// auto-matched from its assembly shape

struct T_func_00b119e0 { void m(); };
extern T_func_00b119e0 G1_func_00b119e0;
void func_00b119e0()
{
    G1_func_00b119e0.m();
}
