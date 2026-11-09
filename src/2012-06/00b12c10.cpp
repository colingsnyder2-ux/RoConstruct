// roc 2012-06 00b12c10  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b12c10
//
// 00b12c10  b9f0dae100           mov ecx, 0xe1daf0
// 00b12c15  e956cd8fff           jmp 0x40f970
// auto-matched from its assembly shape

struct T_func_00b12c10 { void m(); };
extern T_func_00b12c10 G1_func_00b12c10;
void func_00b12c10()
{
    G1_func_00b12c10.m();
}
