// roc 2012-06 00b16340  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b16340
//
// 00b16340  b938dbe200           mov ecx, 0xe2db38
// 00b16345  e926968fff           jmp 0x40f970
// auto-matched from its assembly shape

struct T_func_00b16340 { void m(); };
extern T_func_00b16340 G1_func_00b16340;
void func_00b16340()
{
    G1_func_00b16340.m();
}
