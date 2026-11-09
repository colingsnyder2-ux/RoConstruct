// roc 2012-06 00b13380  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b13380
//
// 00b13380  b9f8fee100           mov ecx, 0xe1fef8
// 00b13385  e9e6c58fff           jmp 0x40f970
// auto-matched from its assembly shape

struct T_func_00b13380 { void m(); };
extern T_func_00b13380 G1_func_00b13380;
void func_00b13380()
{
    G1_func_00b13380.m();
}
