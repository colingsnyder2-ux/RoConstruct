// roc 2012-06 00b13390  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b13390
//
// 00b13390  b970f3e100           mov ecx, 0xe1f370
// 00b13395  e9d6c58fff           jmp 0x40f970
// auto-matched from its assembly shape

struct T_func_00b13390 { void m(); };
extern T_func_00b13390 G1_func_00b13390;
void func_00b13390()
{
    G1_func_00b13390.m();
}
