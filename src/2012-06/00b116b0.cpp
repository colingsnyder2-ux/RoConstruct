// roc 2012-06 00b116b0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b116b0
//
// 00b116b0  b94871e100           mov ecx, 0xe17148
// 00b116b5  e9b6e28fff           jmp 0x40f970
// auto-matched from its assembly shape

struct T_func_00b116b0 { void m(); };
extern T_func_00b116b0 G1_func_00b116b0;
void func_00b116b0()
{
    G1_func_00b116b0.m();
}
