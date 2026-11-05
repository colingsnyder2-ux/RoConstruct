// roc 2012-06 00b17820  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b17820
//
// 00b17820  b99825e300           mov ecx, 0xe32598
// 00b17825  e946818fff           jmp 0x40f970
// auto-matched from its assembly shape

struct T_func_00b17820 { void m(); };
extern T_func_00b17820 G1_func_00b17820;
void func_00b17820()
{
    G1_func_00b17820.m();
}
