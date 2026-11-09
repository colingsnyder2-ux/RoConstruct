// roc 2012-06 00b133f0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b133f0
//
// 00b133f0  b93006e200           mov ecx, 0xe20630
// 00b133f5  e9f66bb9ff           jmp 0x6a9ff0
// auto-matched from its assembly shape

struct T_func_00b133f0 { void m(); };
extern T_func_00b133f0 G1_func_00b133f0;
void func_00b133f0()
{
    G1_func_00b133f0.m();
}
