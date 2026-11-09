// roc 2012-06 00b21550  unit: seg_00b20000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b21550
//
// 00b21550  b9f089e500           mov ecx, 0xe589f0
// 00b21555  e9d64fe5ff           jmp 0x976530
// auto-matched from its assembly shape

struct T_func_00b21550 { void m(); };
extern T_func_00b21550 G1_func_00b21550;
void func_00b21550()
{
    G1_func_00b21550.m();
}
