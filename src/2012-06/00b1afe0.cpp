// roc 2012-06 00b1afe0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1afe0
//
// 00b1afe0  b9b807e400           mov ecx, 0xe407b8
// 00b1afe5  e986498fff           jmp 0x40f970
// auto-matched from its assembly shape

struct T_func_00b1afe0 { void m(); };
extern T_func_00b1afe0 G1_func_00b1afe0;
void func_00b1afe0()
{
    G1_func_00b1afe0.m();
}
