// roc 2012-06 00aefaa0  unit: seg_00ae0000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00aefaa0
//
// 00aefaa0  b93844e200           mov ecx, 0xe24438
// 00aefaa5  e9861fa7ff           jmp 0x561a30
// auto-matched from its assembly shape

struct T_func_00aefaa0 { void m(); };
extern T_func_00aefaa0 G1_func_00aefaa0;
void func_00aefaa0()
{
    G1_func_00aefaa0.m();
}
