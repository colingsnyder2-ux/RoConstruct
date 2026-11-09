// roc 2012-06 00b11700  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b11700
//
// 00b11700  b9c067e100           mov ecx, 0xe167c0
// 00b11705  e966e28fff           jmp 0x40f970
// auto-matched from its assembly shape

struct T_func_00b11700 { void m(); };
extern T_func_00b11700 G1_func_00b11700;
void func_00b11700()
{
    G1_func_00b11700.m();
}
