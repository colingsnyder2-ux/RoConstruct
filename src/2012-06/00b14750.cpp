// roc 2012-06 00b14750  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b14750
//
// 00b14750  b9204de200           mov ecx, 0xe24d20
// 00b14755  e996d7a7ff           jmp 0x591ef0
// auto-matched from its assembly shape

struct T_func_00b14750 { void m(); };
extern T_func_00b14750 G1_func_00b14750;
void func_00b14750()
{
    G1_func_00b14750.m();
}
