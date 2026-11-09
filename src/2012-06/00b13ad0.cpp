// roc 2012-06 00b13ad0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b13ad0
//
// 00b13ad0  b93021e200           mov ecx, 0xe22130
// 00b13ad5  e966bfd6ff           jmp 0x87fa40
// auto-matched from its assembly shape

struct T_func_00b13ad0 { void m(); };
extern T_func_00b13ad0 G1_func_00b13ad0;
void func_00b13ad0()
{
    G1_func_00b13ad0.m();
}
