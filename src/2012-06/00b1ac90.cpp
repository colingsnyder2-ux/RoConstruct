// roc 2012-06 00b1ac90  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1ac90
//
// 00b1ac90  b9c06ce400           mov ecx, 0xe46cc0
// 00b1ac95  e9d64c8fff           jmp 0x40f970
// auto-matched from its assembly shape

struct T_func_00b1ac90 { void m(); };
extern T_func_00b1ac90 G1_func_00b1ac90;
void func_00b1ac90()
{
    G1_func_00b1ac90.m();
}
