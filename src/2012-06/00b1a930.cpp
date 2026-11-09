// roc 2012-06 00b1a930  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1a930
//
// 00b1a930  b94099e300           mov ecx, 0xe39940
// 00b1a935  e9864ec5ff           jmp 0x76f7c0
// auto-matched from its assembly shape

struct T_func_00b1a930 { void m(); };
extern T_func_00b1a930 G1_func_00b1a930;
void func_00b1a930()
{
    G1_func_00b1a930.m();
}
