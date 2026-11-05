// roc 2012-06 00b1ad00  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1ad00
//
// 00b1ad00  b9685fe400           mov ecx, 0xe45f68
// 00b1ad05  e9664c8fff           jmp 0x40f970
// auto-matched from its assembly shape

struct T_func_00b1ad00 { void m(); };
extern T_func_00b1ad00 G1_func_00b1ad00;
void func_00b1ad00()
{
    G1_func_00b1ad00.m();
}
