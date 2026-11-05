// roc 2012-06 00b147c0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b147c0
//
// 00b147c0  b9904ee200           mov ecx, 0xe24e90
// 00b147c5  e9a6b1a6ff           jmp 0x57f970
// auto-matched from its assembly shape

struct T_func_00b147c0 { void m(); };
extern T_func_00b147c0 G1_func_00b147c0;
void func_00b147c0()
{
    G1_func_00b147c0.m();
}
