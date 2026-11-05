// roc 2012-06 00aefdb0  unit: seg_00ae0000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00aefdb0
//
// 00aefdb0  b9604ee200           mov ecx, 0xe24e60
// 00aefdb5  e9761ca7ff           jmp 0x561a30
// auto-matched from its assembly shape

struct T_func_00aefdb0 { void m(); };
extern T_func_00aefdb0 G1_func_00aefdb0;
void func_00aefdb0()
{
    G1_func_00aefdb0.m();
}
