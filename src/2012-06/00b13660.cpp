// roc 2012-06 00b13660  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b13660
//
// 00b13660  b93014e200           mov ecx, 0xe21430
// 00b13665  e9066ab9ff           jmp 0x6aa070
// auto-matched from its assembly shape

struct T_func_00b13660 { void m(); };
extern T_func_00b13660 G1_func_00b13660;
void func_00b13660()
{
    G1_func_00b13660.m();
}
