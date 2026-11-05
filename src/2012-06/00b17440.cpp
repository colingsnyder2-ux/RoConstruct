// roc 2012-06 00b17440  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b17440
//
// 00b17440  b95c16e300           mov ecx, 0xe3165c
// 00b17445  e9a6aaa7ff           jmp 0x591ef0
// auto-matched from its assembly shape

struct T_func_00b17440 { void m(); };
extern T_func_00b17440 G1_func_00b17440;
void func_00b17440()
{
    G1_func_00b17440.m();
}
