// roc 2012-06 00b20fb0  unit: seg_00b20000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b20fb0
//
// 00b20fb0  b92c66e500           mov ecx, 0xe5662c
// 00b20fb5  e9360fa7ff           jmp 0x591ef0
// auto-matched from its assembly shape

struct T_func_00b20fb0 { void m(); };
extern T_func_00b20fb0 G1_func_00b20fb0;
void func_00b20fb0()
{
    G1_func_00b20fb0.m();
}
