// roc 2012-06 00b14740  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b14740
//
// 00b14740  b9e849e200           mov ecx, 0xe249e8
// 00b14745  e926b28fff           jmp 0x40f970
// auto-matched from its assembly shape

struct T_func_00b14740 { void m(); };
extern T_func_00b14740 G1_func_00b14740;
void func_00b14740()
{
    G1_func_00b14740.m();
}
