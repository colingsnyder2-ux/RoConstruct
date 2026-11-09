// roc 2012-06 00b20470  unit: seg_00b20000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b20470
//
// 00b20470  b9f051e500           mov ecx, 0xe551f0
// 00b20475  e9761aa7ff           jmp 0x591ef0
// auto-matched from its assembly shape

struct T_func_00b20470 { void m(); };
extern T_func_00b20470 G1_func_00b20470;
void func_00b20470()
{
    G1_func_00b20470.m();
}
