// roc 2012-06 00b1f230  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1f230
//
// 00b1f230  b95820e500           mov ecx, 0xe52058
// 00b1f235  e9b62ca7ff           jmp 0x591ef0
// auto-matched from its assembly shape

struct T_func_00b1f230 { void m(); };
extern T_func_00b1f230 G1_func_00b1f230;
void func_00b1f230()
{
    G1_func_00b1f230.m();
}
