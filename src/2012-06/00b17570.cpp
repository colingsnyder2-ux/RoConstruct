// roc 2012-06 00b17570  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b17570
//
// 00b17570  b98418e300           mov ecx, 0xe31884
// 00b17575  e976a9a7ff           jmp 0x591ef0
// auto-matched from its assembly shape

struct T_func_00b17570 { void m(); };
extern T_func_00b17570 G1_func_00b17570;
void func_00b17570()
{
    G1_func_00b17570.m();
}
