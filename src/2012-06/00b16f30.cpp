// roc 2012-06 00b16f30  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b16f30
//
// 00b16f30  b940f7e200           mov ecx, 0xe2f740
// 00b16f35  e9a688bcff           jmp 0x6df7e0
// auto-matched from its assembly shape

struct T_func_00b16f30 { void m(); };
extern T_func_00b16f30 G1_func_00b16f30;
void func_00b16f30()
{
    G1_func_00b16f30.m();
}
