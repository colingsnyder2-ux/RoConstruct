// roc 2012-06 00b1b300  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1b300
//
// 00b1b300  b968a8e300           mov ecx, 0xe3a868
// 00b1b305  e966468fff           jmp 0x40f970
// auto-matched from its assembly shape

struct T_func_00b1b300 { void m(); };
extern T_func_00b1b300 G1_func_00b1b300;
void func_00b1b300()
{
    G1_func_00b1b300.m();
}
