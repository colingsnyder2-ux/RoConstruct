// roc 2012-06 00b1ace0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1ace0
//
// 00b1ace0  b93863e400           mov ecx, 0xe46338
// 00b1ace5  e9864c8fff           jmp 0x40f970
// auto-matched from its assembly shape

struct T_func_00b1ace0 { void m(); };
extern T_func_00b1ace0 G1_func_00b1ace0;
void func_00b1ace0()
{
    G1_func_00b1ace0.m();
}
