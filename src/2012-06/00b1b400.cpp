// roc 2012-06 00b1b400  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1b400
//
// 00b1b400  b9d88ae400           mov ecx, 0xe48ad8
// 00b1b405  e95611c6ff           jmp 0x77c560
// auto-matched from its assembly shape

struct T_func_00b1b400 { void m(); };
extern T_func_00b1b400 G1_func_00b1b400;
void func_00b1b400()
{
    G1_func_00b1b400.m();
}
