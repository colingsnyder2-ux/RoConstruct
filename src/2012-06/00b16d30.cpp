// roc 2012-06 00b16d30  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b16d30
//
// 00b16d30  b948efe200           mov ecx, 0xe2ef48
// 00b16d35  e9068dd6ff           jmp 0x87fa40
// auto-matched from its assembly shape

struct T_func_00b16d30 { void m(); };
extern T_func_00b16d30 G1_func_00b16d30;
void func_00b16d30()
{
    G1_func_00b16d30.m();
}
