// roc 2012-06 00b20fa0  unit: seg_00b20000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b20fa0
//
// 00b20fa0  b97066e500           mov ecx, 0xe56670
// 00b20fa5  e9460fa7ff           jmp 0x591ef0
// auto-matched from its assembly shape

struct T_func_00b20fa0 { void m(); };
extern T_func_00b20fa0 G1_func_00b20fa0;
void func_00b20fa0()
{
    G1_func_00b20fa0.m();
}
