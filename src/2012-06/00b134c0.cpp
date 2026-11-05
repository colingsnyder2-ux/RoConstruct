// roc 2012-06 00b134c0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b134c0
//
// 00b134c0  b9300ce200           mov ecx, 0xe20c30
// 00b134c5  e926eaa7ff           jmp 0x591ef0
// auto-matched from its assembly shape

struct T_func_00b134c0 { void m(); };
extern T_func_00b134c0 G1_func_00b134c0;
void func_00b134c0()
{
    G1_func_00b134c0.m();
}
