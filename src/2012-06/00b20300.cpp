// roc 2012-06 00b20300  unit: seg_00b20000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b20300
//
// 00b20300  b9e84ce500           mov ecx, 0xe54ce8
// 00b20305  e9e61ba7ff           jmp 0x591ef0
// auto-matched from its assembly shape

struct T_func_00b20300 { void m(); };
extern T_func_00b20300 G1_func_00b20300;
void func_00b20300()
{
    G1_func_00b20300.m();
}
