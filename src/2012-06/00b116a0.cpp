// roc 2012-06 00b116a0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b116a0
//
// 00b116a0  b93073e100           mov ecx, 0xe17330
// 00b116a5  e9c6e28fff           jmp 0x40f970
// auto-matched from its assembly shape

struct T_func_00b116a0 { void m(); };
extern T_func_00b116a0 G1_func_00b116a0;
void func_00b116a0()
{
    G1_func_00b116a0.m();
}
