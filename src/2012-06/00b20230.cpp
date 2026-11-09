// roc 2012-06 00b20230  unit: seg_00b20000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b20230
//
// 00b20230  b98845e500           mov ecx, 0xe54588
// 00b20235  e936f78eff           jmp 0x40f970
// auto-matched from its assembly shape

struct T_func_00b20230 { void m(); };
extern T_func_00b20230 G1_func_00b20230;
void func_00b20230()
{
    G1_func_00b20230.m();
}
