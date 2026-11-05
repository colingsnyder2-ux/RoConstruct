// roc 2012-06 00b1b2f0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1b2f0
//
// 00b1b2f0  b950aae300           mov ecx, 0xe3aa50
// 00b1b2f5  e976468fff           jmp 0x40f970
// auto-matched from its assembly shape

struct T_func_00b1b2f0 { void m(); };
extern T_func_00b1b2f0 G1_func_00b1b2f0;
void func_00b1b2f0()
{
    G1_func_00b1b2f0.m();
}
