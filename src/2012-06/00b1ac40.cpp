// roc 2012-06 00b1ac40  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1ac40
//
// 00b1ac40  b94876e400           mov ecx, 0xe47648
// 00b1ac45  e9264d8fff           jmp 0x40f970
// auto-matched from its assembly shape

struct T_func_00b1ac40 { void m(); };
extern T_func_00b1ac40 G1_func_00b1ac40;
void func_00b1ac40()
{
    G1_func_00b1ac40.m();
}
