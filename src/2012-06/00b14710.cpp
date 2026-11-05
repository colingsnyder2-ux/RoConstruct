// roc 2012-06 00b14710  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b14710
//
// 00b14710  b9304ce200           mov ecx, 0xe24c30
// 00b14715  e9d6d7a7ff           jmp 0x591ef0
// auto-matched from its assembly shape

struct T_func_00b14710 { void m(); };
extern T_func_00b14710 G1_func_00b14710;
void func_00b14710()
{
    G1_func_00b14710.m();
}
