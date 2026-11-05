// roc 2012-06 00af0740  unit: seg_00af0000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00af0740
//
// 00af0740  b94073e200           mov ecx, 0xe27340
// 00af0745  e9e612a7ff           jmp 0x561a30
// auto-matched from its assembly shape

struct T_func_00af0740 { void m(); };
extern T_func_00af0740 G1_func_00af0740;
void func_00af0740()
{
    G1_func_00af0740.m();
}
