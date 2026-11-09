// roc 2012-06 00b14730  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b14730
//
// 00b14730  b9f047e200           mov ecx, 0xe247f0
// 00b14735  e936b28fff           jmp 0x40f970
// auto-matched from its assembly shape

struct T_func_00b14730 { void m(); };
extern T_func_00b14730 G1_func_00b14730;
void func_00b14730()
{
    G1_func_00b14730.m();
}
