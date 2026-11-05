// roc 2012-06 00b20640  unit: seg_00b20000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b20640
//
// 00b20640  b93c55e500           mov ecx, 0xe5553c
// 00b20645  e9a618a7ff           jmp 0x591ef0
// auto-matched from its assembly shape

struct T_func_00b20640 { void m(); };
extern T_func_00b20640 G1_func_00b20640;
void func_00b20640()
{
    G1_func_00b20640.m();
}
