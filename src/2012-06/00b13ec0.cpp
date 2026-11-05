// roc 2012-06 00b13ec0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b13ec0
//
// 00b13ec0  b9202be200           mov ecx, 0xe22b20
// 00b13ec5  e9a6ba8fff           jmp 0x40f970
// auto-matched from its assembly shape

struct T_func_00b13ec0 { void m(); };
extern T_func_00b13ec0 G1_func_00b13ec0;
void func_00b13ec0()
{
    G1_func_00b13ec0.m();
}
