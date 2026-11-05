// roc 2012-06 00b1b470  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1b470
//
// 00b1b470  b9ec8ae400           mov ecx, 0xe48aec
// 00b1b475  e9e6eec5ff           jmp 0x77a360
// auto-matched from its assembly shape

struct T_func_00b1b470 { void m(); };
extern T_func_00b1b470 G1_func_00b1b470;
void func_00b1b470()
{
    G1_func_00b1b470.m();
}
