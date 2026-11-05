// roc 2012-06 00b20630  unit: seg_00b20000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b20630
//
// 00b20630  b9a053e500           mov ecx, 0xe553a0
// 00b20635  e9b618a7ff           jmp 0x591ef0
// auto-matched from its assembly shape

struct T_func_00b20630 { void m(); };
extern T_func_00b20630 G1_func_00b20630;
void func_00b20630()
{
    G1_func_00b20630.m();
}
