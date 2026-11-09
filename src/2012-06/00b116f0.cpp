// roc 2012-06 00b116f0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b116f0
//
// 00b116f0  b9a869e100           mov ecx, 0xe169a8
// 00b116f5  e976e28fff           jmp 0x40f970
// auto-matched from its assembly shape

struct T_func_00b116f0 { void m(); };
extern T_func_00b116f0 G1_func_00b116f0;
void func_00b116f0()
{
    G1_func_00b116f0.m();
}
