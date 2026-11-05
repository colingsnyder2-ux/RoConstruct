// roc 2012-06 00b11400  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b11400
//
// 00b11400  b99063e100           mov ecx, 0xe16390
// 00b11405  e9760b8fff           jmp 0x401f80
// auto-matched from its assembly shape

struct T_func_00b11400 { void m(); };
extern T_func_00b11400 G1_func_00b11400;
void func_00b11400()
{
    G1_func_00b11400.m();
}
