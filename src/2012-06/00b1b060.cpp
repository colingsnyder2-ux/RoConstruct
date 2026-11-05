// roc 2012-06 00b1b060  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1b060
//
// 00b1b060  b978f8e300           mov ecx, 0xe3f878
// 00b1b065  e906498fff           jmp 0x40f970
// auto-matched from its assembly shape

struct T_func_00b1b060 { void m(); };
extern T_func_00b1b060 G1_func_00b1b060;
void func_00b1b060()
{
    G1_func_00b1b060.m();
}
