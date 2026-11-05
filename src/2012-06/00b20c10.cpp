// roc 2012-06 00b20c10  unit: seg_00b20000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b20c10
//
// 00b20c10  b9485ee500           mov ecx, 0xe55e48
// 00b20c15  e9d612a7ff           jmp 0x591ef0
// auto-matched from its assembly shape

struct T_func_00b20c10 { void m(); };
extern T_func_00b20c10 G1_func_00b20c10;
void func_00b20c10()
{
    G1_func_00b20c10.m();
}
