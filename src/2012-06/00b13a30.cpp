// roc 2012-06 00b13a30  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b13a30
//
// 00b13a30  b91824e200           mov ecx, 0xe22418
// 00b13a35  e906c0d6ff           jmp 0x87fa40
// auto-matched from its assembly shape

struct T_func_00b13a30 { void m(); };
extern T_func_00b13a30 G1_func_00b13a30;
void func_00b13a30()
{
    G1_func_00b13a30.m();
}
