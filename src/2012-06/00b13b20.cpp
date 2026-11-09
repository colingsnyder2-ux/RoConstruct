// roc 2012-06 00b13b20  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b13b20
//
// 00b13b20  b98019e200           mov ecx, 0xe21980
// 00b13b25  e946be8fff           jmp 0x40f970
// auto-matched from its assembly shape

struct T_func_00b13b20 { void m(); };
extern T_func_00b13b20 G1_func_00b13b20;
void func_00b13b20()
{
    G1_func_00b13b20.m();
}
