// roc 2012-06 00b1ae00  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1ae00
//
// 00b1ae00  b9e840e400           mov ecx, 0xe440e8
// 00b1ae05  e9664b8fff           jmp 0x40f970
// auto-matched from its assembly shape

struct T_func_00b1ae00 { void m(); };
extern T_func_00b1ae00 G1_func_00b1ae00;
void func_00b1ae00()
{
    G1_func_00b1ae00.m();
}
