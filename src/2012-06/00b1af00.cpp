// roc 2012-06 00b1af00  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1af00
//
// 00b1af00  b96822e400           mov ecx, 0xe42268
// 00b1af05  e9664a8fff           jmp 0x40f970
// auto-matched from its assembly shape

struct T_func_00b1af00 { void m(); };
extern T_func_00b1af00 G1_func_00b1af00;
void func_00b1af00()
{
    G1_func_00b1af00.m();
}
