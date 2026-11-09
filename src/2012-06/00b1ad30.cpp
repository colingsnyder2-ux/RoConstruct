// roc 2012-06 00b1ad30  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1ad30
//
// 00b1ad30  b9b059e400           mov ecx, 0xe459b0
// 00b1ad35  e9364c8fff           jmp 0x40f970
// auto-matched from its assembly shape

struct T_func_00b1ad30 { void m(); };
extern T_func_00b1ad30 G1_func_00b1ad30;
void func_00b1ad30()
{
    G1_func_00b1ad30.m();
}
