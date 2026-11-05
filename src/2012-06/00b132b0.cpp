// roc 2012-06 00b132b0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b132b0
//
// 00b132b0  b960f5e100           mov ecx, 0xe1f560
// 00b132b5  e9b6c68fff           jmp 0x40f970
// auto-matched from its assembly shape

struct T_func_00b132b0 { void m(); };
extern T_func_00b132b0 G1_func_00b132b0;
void func_00b132b0()
{
    G1_func_00b132b0.m();
}
