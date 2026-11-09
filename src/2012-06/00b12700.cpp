// roc 2012-06 00b12700  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b12700
//
// 00b12700  b934a5e100           mov ecx, 0xe1a534
// 00b12705  e9066b96ff           jmp 0x479210
// auto-matched from its assembly shape

struct T_func_00b12700 { void m(); };
extern T_func_00b12700 G1_func_00b12700;
void func_00b12700()
{
    G1_func_00b12700.m();
}
