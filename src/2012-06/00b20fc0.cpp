// roc 2012-06 00b20fc0  unit: seg_00b20000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b20fc0
//
// 00b20fc0  b9ac66e500           mov ecx, 0xe566ac
// 00b20fc5  e9260fa7ff           jmp 0x591ef0
// auto-matched from its assembly shape

struct T_func_00b20fc0 { void m(); };
extern T_func_00b20fc0 G1_func_00b20fc0;
void func_00b20fc0()
{
    G1_func_00b20fc0.m();
}
