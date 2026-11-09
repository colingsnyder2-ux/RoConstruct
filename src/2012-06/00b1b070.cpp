// roc 2012-06 00b1b070  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1b070
//
// 00b1b070  b990f6e300           mov ecx, 0xe3f690
// 00b1b075  e9f6488fff           jmp 0x40f970
// auto-matched from its assembly shape

struct T_func_00b1b070 { void m(); };
extern T_func_00b1b070 G1_func_00b1b070;
void func_00b1b070()
{
    G1_func_00b1b070.m();
}
