// roc 2012-06 00b21800  unit: seg_00b20000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b21800
//
// 00b21800  b9aca0e500           mov ecx, 0xe5a0ac
// 00b21805  e9b884f7ff           jmp 0xa99cc2
// auto-matched from its assembly shape

struct T_func_00b21800 { void m(); };
extern T_func_00b21800 G1_func_00b21800;
void func_00b21800()
{
    G1_func_00b21800.m();
}
