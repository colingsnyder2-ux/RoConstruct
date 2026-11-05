// roc 2012-06 00b132e0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b132e0
//
// 00b132e0  b928fbe100           mov ecx, 0xe1fb28
// 00b132e5  e986c68fff           jmp 0x40f970
// auto-matched from its assembly shape

struct T_func_00b132e0 { void m(); };
extern T_func_00b132e0 G1_func_00b132e0;
void func_00b132e0()
{
    G1_func_00b132e0.m();
}
