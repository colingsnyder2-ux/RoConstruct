// roc 2012-06 00b20600  unit: seg_00b20000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b20600
//
// 00b20600  b97054e500           mov ecx, 0xe55470
// 00b20605  e9e618a7ff           jmp 0x591ef0
// auto-matched from its assembly shape

struct T_func_00b20600 { void m(); };
extern T_func_00b20600 G1_func_00b20600;
void func_00b20600()
{
    G1_func_00b20600.m();
}
