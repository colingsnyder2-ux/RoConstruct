// roc 2012-06 00b1ad60  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1ad60
//
// 00b1ad60  b9f853e400           mov ecx, 0xe453f8
// 00b1ad65  e9064c8fff           jmp 0x40f970
// auto-matched from its assembly shape

struct T_func_00b1ad60 { void m(); };
extern T_func_00b1ad60 G1_func_00b1ad60;
void func_00b1ad60()
{
    G1_func_00b1ad60.m();
}
