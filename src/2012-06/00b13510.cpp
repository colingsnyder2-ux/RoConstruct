// roc 2012-06 00b13510  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b13510
//
// 00b13510  b91415e200           mov ecx, 0xe21514
// 00b13515  e9e64fa1ff           jmp 0x528500
// auto-matched from its assembly shape

struct T_func_00b13510 { void m(); };
extern T_func_00b13510 G1_func_00b13510;
void func_00b13510()
{
    G1_func_00b13510.m();
}
