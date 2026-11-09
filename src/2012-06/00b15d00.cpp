// roc 2012-06 00b15d00  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b15d00
//
// 00b15d00  b910b4e200           mov ecx, 0xe2b410
// 00b15d05  e9e6c1a7ff           jmp 0x591ef0
// auto-matched from its assembly shape

struct T_func_00b15d00 { void m(); };
extern T_func_00b15d00 G1_func_00b15d00;
void func_00b15d00()
{
    G1_func_00b15d00.m();
}
