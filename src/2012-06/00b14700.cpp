// roc 2012-06 00b14700  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b14700
//
// 00b14700  b9904de200           mov ecx, 0xe24d90
// 00b14705  e9e6d7a7ff           jmp 0x591ef0
// auto-matched from its assembly shape

struct T_func_00b14700 { void m(); };
extern T_func_00b14700 G1_func_00b14700;
void func_00b14700()
{
    G1_func_00b14700.m();
}
