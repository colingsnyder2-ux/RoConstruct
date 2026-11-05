// roc 2012-06 00b20d90  unit: seg_00b20000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b20d90
//
// 00b20d90  b94463e500           mov ecx, 0xe56344
// 00b20d95  e95611a7ff           jmp 0x591ef0
// auto-matched from its assembly shape

struct T_func_00b20d90 { void m(); };
extern T_func_00b20d90 G1_func_00b20d90;
void func_00b20d90()
{
    G1_func_00b20d90.m();
}
