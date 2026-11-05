// roc 2012-06 00b1aee0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1aee0
//
// 00b1aee0  b93826e400           mov ecx, 0xe42638
// 00b1aee5  e9864a8fff           jmp 0x40f970
// auto-matched from its assembly shape

struct T_func_00b1aee0 { void m(); };
extern T_func_00b1aee0 G1_func_00b1aee0;
void func_00b1aee0()
{
    G1_func_00b1aee0.m();
}
