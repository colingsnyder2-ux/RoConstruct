// roc 2012-06 00b17210  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b17210
//
// 00b17210  b94010e300           mov ecx, 0xe31040
// 00b17215  e956878fff           jmp 0x40f970
// auto-matched from its assembly shape

struct T_func_00b17210 { void m(); };
extern T_func_00b17210 G1_func_00b17210;
void func_00b17210()
{
    G1_func_00b17210.m();
}
