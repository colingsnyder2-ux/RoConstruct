// roc 2012-06 00b1da90  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1da90
//
// 00b1da90  b9bcece400           mov ecx, 0xe4ecbc
// 00b1da95  e95644a7ff           jmp 0x591ef0
// auto-matched from its assembly shape

struct T_func_00b1da90 { void m(); };
extern T_func_00b1da90 G1_func_00b1da90;
void func_00b1da90()
{
    G1_func_00b1da90.m();
}
