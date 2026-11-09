// roc 2012-06 00b21790  unit: seg_00b20000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b21790
//
// 00b21790  b9289ee500           mov ecx, 0xe59e28
// 00b21795  e9d6c0f3ff           jmp 0xa5d870
// auto-matched from its assembly shape

struct T_func_00b21790 { void m(); };
extern T_func_00b21790 G1_func_00b21790;
void func_00b21790()
{
    G1_func_00b21790.m();
}
