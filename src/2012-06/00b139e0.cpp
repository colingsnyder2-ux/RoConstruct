// roc 2012-06 00b139e0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b139e0
//
// 00b139e0  b93816e200           mov ecx, 0xe21638
// 00b139e5  e91638a3ff           jmp 0x547200
// auto-matched from its assembly shape

struct T_func_00b139e0 { void m(); };
extern T_func_00b139e0 G1_func_00b139e0;
void func_00b139e0()
{
    G1_func_00b139e0.m();
}
