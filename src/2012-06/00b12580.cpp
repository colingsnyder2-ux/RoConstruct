// roc 2012-06 00b12580  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b12580
//
// 00b12580  b9e4a2e100           mov ecx, 0xe1a2e4
// 00b12585  e9860abcff           jmp 0x6d3010
// auto-matched from its assembly shape

struct T_func_00b12580 { void m(); };
extern T_func_00b12580 G1_func_00b12580;
void func_00b12580()
{
    G1_func_00b12580.m();
}
