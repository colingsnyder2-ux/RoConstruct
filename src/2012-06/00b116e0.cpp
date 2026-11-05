// roc 2012-06 00b116e0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b116e0
//
// 00b116e0  b9906be100           mov ecx, 0xe16b90
// 00b116e5  e986e28fff           jmp 0x40f970
// auto-matched from its assembly shape

struct T_func_00b116e0 { void m(); };
extern T_func_00b116e0 G1_func_00b116e0;
void func_00b116e0()
{
    G1_func_00b116e0.m();
}
