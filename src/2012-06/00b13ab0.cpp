// roc 2012-06 00b13ab0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b13ab0
//
// 00b13ab0  b9201ee200           mov ecx, 0xe21e20
// 00b13ab5  e986bfd6ff           jmp 0x87fa40
// auto-matched from its assembly shape

struct T_func_00b13ab0 { void m(); };
extern T_func_00b13ab0 G1_func_00b13ab0;
void func_00b13ab0()
{
    G1_func_00b13ab0.m();
}
